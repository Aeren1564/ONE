/*
 * Copyright (c) 2021 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ConnectNode.h"

#include "ConnectNode.test.h"

#include <luci/Service/CircleNodeClone.h>

#include <gtest/gtest.h>

namespace
{

using namespace luci::test;

class NodeGraphlet : public NodeGraphletT<luci::CircleNonMaxSuppressionV4>
{
public:
  NodeGraphlet() = default;
};

class TestNodeGraph : public TestIsOGraph<5>, public NodeGraphlet
{
public:
  TestNodeGraph() = default;

public:
  void init(const ShapeU32 shape)
  {
    TestIsOGraph<5>::init({shape, shape, shape, shape, shape}, shape);
    NodeGraphlet::init(g());

    node()->boxes(input(0));
    node()->scores(input(1));
    node()->max_output_size(input(2));
    node()->iou_threshold(input(3));
    node()->score_threshold(input(4));

    output()->from(node());
  }
};

} // namespace

TEST(ConnectNodeTest, connect_NonMaxSuppressionV4)
{
  TestNodeGraph tng;
  tng.init({2, 3});

  ConnectionTestHelper cth;
  cth.prepare_inputs(&tng);

  auto *node = tng.node();
  ASSERT_NO_THROW(loco::must_cast<luci::CircleNonMaxSuppressionV4 *>(node));

  auto *clone = luci::clone_node(node, cth.graph_clone());
  ASSERT_NO_THROW(loco::must_cast<luci::CircleNonMaxSuppressionV4 *>(clone));

  cth.clone_connect(node, clone);

  ASSERT_EQ(5, clone->arity());
  ASSERT_EQ(cth.inputs(0), clone->arg(0));
  ASSERT_EQ(cth.inputs(1), clone->arg(1));
  ASSERT_EQ(cth.inputs(2), clone->arg(2));
  ASSERT_EQ(cth.inputs(3), clone->arg(3));
  ASSERT_EQ(cth.inputs(4), clone->arg(4));
}

TEST(ConnectNodeTest, connect_NonMaxSuppressionV4_NEG)
{
  TestNodeGraph tng;
  tng.init({2, 3});

  ConnectionTestHelper cth;
  cth.prepare_inputs_miss(&tng);

  auto *node = tng.node();
  ASSERT_NO_THROW(loco::must_cast<luci::CircleNonMaxSuppressionV4 *>(node));

  auto *clone = luci::clone_node(node, cth.graph_clone());
  ASSERT_NO_THROW(loco::must_cast<luci::CircleNonMaxSuppressionV4 *>(clone));

  EXPECT_ANY_THROW(cth.clone_connect(node, clone));
}
