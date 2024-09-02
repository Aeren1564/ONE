/*
 * Copyright (c) 2024 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __ONERT_BACKEND_LAYER_SCOPE_TENSOR_H__
#define __ONERT_BACKEND_LAYER_SCOPE_TENSOR_H__

#include <backend/basic/Tensor.h>

namespace onert
{
namespace backend
{
namespace train
{

// LayerScopeTensor is a tensor that is not shown in graph but required by each layer.
// It is accessed within one operation layer.
class LayerScopeTensor final : public basic::Tensor
{
public:
  LayerScopeTensor() = delete;

public:
  LayerScopeTensor(const ir::OperandInfo &info) : basic::Tensor(info, nullptr)
  {
    // DO NOTHING
  }
};

} // namespace train
} // namespace backend
} // namespace onert

#endif // __ONERT_BACKEND_LAYER_SCOPE_TENSOR_H__