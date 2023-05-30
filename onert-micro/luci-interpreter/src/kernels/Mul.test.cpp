/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 * Copyright 2017 The TensorFlow Authors. All Rights Reserved.
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

#include "kernels/TestUtils.h"
#include "luci_interpreter/test_models/mul/FloatMulKernel.h"
#include "luci_interpreter/test_models/mul/IntMulKernel.h"
#include "luci_interpreter/test_models/mul/NegMulKernel.h"

#include "loader/ModuleLoader.h"

namespace luci_interpreter
{
namespace
{

using namespace testing;

class MulTest : public ::testing::Test
{
  // Do nothing
};

template <typename T> std::vector<T> checkMulKernel(test_kernel::TestDataBase<T> *test_data_base)
{
  MemoryManager memory_manager{};
  RuntimeModule runtime_module{};
  bool dealloc_input = true;

  // Load model with single op
  auto *model_data_raw = reinterpret_cast<const char *>(test_data_base->get_model_ptr());
  ModuleLoader::load(&runtime_module, &memory_manager, model_data_raw, dealloc_input);

  auto *main_runtime_graph = runtime_module.getMainGraph();
  assert(main_runtime_graph->getNumOfInputTensors() == 2);

  // set left input data
  {
    auto *input_tensor_data = reinterpret_cast<T *>(main_runtime_graph->configureGraphInput(0));
    std::copy(test_data_base->get_input_data_by_index(0).begin(),
              test_data_base->get_input_data_by_index(0).end(), input_tensor_data);
  }

  // set right input data
  {
    auto *input_tensor_data = reinterpret_cast<T *>(main_runtime_graph->configureGraphInput(1));
    std::copy(test_data_base->get_input_data_by_index(1).begin(),
              test_data_base->get_input_data_by_index(1).end(), input_tensor_data);
  }

  runtime_module.execute();

  assert(main_runtime_graph->getNumOfOutputTensors() == 1);

  T *output_data = reinterpret_cast<T *>(main_runtime_graph->getOutputDataByIndex(0));
  const size_t num_elements = (main_runtime_graph->getOutputDataSizeByIndex(0) / sizeof(T));
  std::vector<T> output_data_vector(output_data, output_data + num_elements);
  return output_data_vector;
}

TEST_F(MulTest, Float_P)
{
  // No broadcast
  {
    const bool is_with_broadcast = false;
    test_kernel::TestDataFloatMul test_data_kernel(is_with_broadcast);
    std::vector<float> output_data_vector = checkMulKernel(&test_data_kernel);
    EXPECT_THAT(output_data_vector, kernels::testing::FloatArrayNear(
                                      test_data_kernel.get_output_data_by_index(0), 0.0001f));
  }
  // With broadcast
  {
    const bool is_with_broadcast = true;
    test_kernel::TestDataFloatMul test_data_kernel(is_with_broadcast);
    std::vector<float> output_data_vector = checkMulKernel(&test_data_kernel);
    EXPECT_THAT(output_data_vector, kernels::testing::FloatArrayNear(
                                      test_data_kernel.get_output_data_by_index(0), 0.0001f));
  }
}

TEST_F(MulTest, INT_P)
{
  // No broadcast
  {
    const bool is_with_broadcast = false;
    test_kernel::TestDataIntMul test_data_kernel(is_with_broadcast);
    const auto output_data_vector = checkMulKernel<int32_t>(&test_data_kernel);
    EXPECT_THAT(output_data_vector, test_data_kernel.get_output_data_by_index(0));
  }
  // With broadcast
  {
    const bool is_with_broadcast = true;
    test_kernel::TestDataIntMul test_data_kernel(is_with_broadcast);
    const auto output_data_vector = checkMulKernel<int32_t>(&test_data_kernel);
    EXPECT_THAT(output_data_vector, test_data_kernel.get_output_data_by_index(0));
  }
}

TEST_F(MulTest, Wrong_Input1_Type_NEG)
{
  test_kernel::TestDataInput1WrongTypeMul test_data_kernel(true);
  EXPECT_DEATH(checkMulKernel(&test_data_kernel), "");
}

TEST_F(MulTest, Wrong_Input2_Type_NEG)
{
  test_kernel::TestDataInput2WrongTypeMul test_data_kernel(true);
  EXPECT_DEATH(checkMulKernel(&test_data_kernel), "");
}

TEST_F(MulTest, Wrong_Ouput_Type_NEG)
{
  test_kernel::TestDataInt16TypeMul test_data_kernel(true);
  EXPECT_DEATH(checkMulKernel(&test_data_kernel), "");
}

// TODO: add tests for U8 and S16
// TODO: add tests for inplace optimizations for all types

} // namespace
} // namespace luci_interpreter
