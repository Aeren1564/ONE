/*
 * Copyright (c) 2023 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef __ONERT_IR_TRAIN_OPERATION_SOFTMAX_H__
#define __ONERT_IR_TRAIN_OPERATION_SOFTMAX_H__

#include "ir/operation/Softmax.h"
#include "ir/train/ITrainableOperation.h"

namespace onert
{
namespace ir
{
namespace train
{
namespace operation
{

class Softmax : public ir::operation::Softmax, public ITrainableOperation
{
private:
  using OperationType = ir::operation::Softmax;

public:
  Softmax(const OperationType &operation);

public:
  std::unique_ptr<ITrainableOperation> clone() const override;
  void accept(OperationVisitor &v) const override;
  void accept(TrainableOperationVisitor &v) const override;
};

} // namespace operation
} // namespace train
} // namespace ir
} // namespace onert

#endif // __ONERT_IR_TRAIN_OPERATION_SOFTMAX_H__
