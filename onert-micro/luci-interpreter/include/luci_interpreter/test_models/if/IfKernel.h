/*
 * Copyright (c) 2023 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef LUCI_INTERPRETER_TEST_MODELS_IF_KERNEL_H
#define LUCI_INTERPRETER_TEST_MODELS_IF_KERNEL_H

#include "luci_interpreter/test_models/TestDataBase.h"

namespace luci_interpreter
{
namespace test_kernel
{

namespace if_kernel
{
/*
 * If Kernel:
 *    Main graph:
 *  Input Bool(1) Input_1(2,3) Input_2(2,3)
 *                    |
 *                   If
 *                    |
 *                Output(2,3)
 *
 *    If else graph:
 *         Input_1(2,3) Input_2(2,3)
 *                     |
 *                    Add
 *                     |
 *                 Output(2,3)
 *
 *    If then graph:
 *         Input_1(2,3) Input_2(2,3)
 *                     |
 *                    Mul
 *                     |
 *                 Output(2,3)
 */
const unsigned char test_kernel_model_circle[] = {
  0x18, 0x00, 0x00, 0x00, 0x43, 0x49, 0x52, 0x30, 0x00, 0x00, 0x0e, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x08, 0x00, 0x10, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x68, 0x00, 0x00, 0x00, 0xd4, 0x03, 0x00, 0x00, 0x0c, 0x04, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
  0x54, 0x00, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00,
  0x34, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x30, 0xfc, 0xff, 0xff,
  0x34, 0xfc, 0xff, 0xff, 0x38, 0xfc, 0xff, 0xff, 0x3c, 0xfc, 0xff, 0xff, 0x40, 0xfc, 0xff, 0xff,
  0x44, 0xfc, 0xff, 0xff, 0x48, 0xfc, 0xff, 0xff, 0x4c, 0xfc, 0xff, 0xff, 0x50, 0xfc, 0xff, 0xff,
  0x54, 0xfc, 0xff, 0xff, 0x58, 0xfc, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x10, 0x02, 0x00, 0x00,
  0xfc, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0a, 0xfe, 0xff, 0xff, 0x14, 0x00, 0x00, 0x00,
  0x1c, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x49, 0x46, 0x5f, 0x54, 0x48, 0x45, 0x4e, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0xfa, 0xfd, 0xff, 0xff, 0x00, 0x00, 0x00, 0x15, 0x10, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xb0, 0xfc, 0xff, 0xff,
  0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00,
  0x2c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x84, 0xfd, 0xff, 0xff, 0x0c, 0x00, 0x00, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x6f, 0x66, 0x6d, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xa8, 0xfd, 0xff, 0xff,
  0x0c, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x69, 0x66, 0x6d, 0x32, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0xd0, 0xfd, 0xff, 0xff, 0x0c, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x69, 0x66, 0x6d, 0x31, 0x00, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xff, 0xff,
  0x14, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
  0x68, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x49, 0x46, 0x5f, 0x45, 0x4c, 0x53, 0x45, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x0c, 0x00, 0x07, 0x00, 0x08, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b,
  0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xb0, 0xfd, 0xff, 0xff,
  0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00,
  0x2c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x84, 0xfe, 0xff, 0xff, 0x0c, 0x00, 0x00, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x6f, 0x66, 0x6d, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xa8, 0xfe, 0xff, 0xff,
  0x0c, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x69, 0x66, 0x6d, 0x32, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0xd0, 0xfe, 0xff, 0xff, 0x0c, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x69, 0x66, 0x6d, 0x31, 0x00, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x18, 0x00, 0x14, 0x00, 0x10, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00,
  0x84, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x4d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x18, 0x00, 0x14, 0x00,
  0x10, 0x00, 0x0c, 0x00, 0x07, 0x00, 0x08, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5c,
  0x18, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x04, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x9c, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00,
  0x2c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xb4, 0xff, 0xff, 0xff, 0x0c, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x6f, 0x66, 0x6d, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xd8, 0xff, 0xff, 0xff,
  0x0c, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x69, 0x66, 0x6d, 0x32, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x10, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x08, 0x00, 0x04, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x69, 0x66, 0x6d, 0x31, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x14, 0x00, 0x10, 0x00, 0x0f, 0x00,
  0x08, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x06, 0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x69, 0x66, 0x6d, 0x62,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xf4, 0xff, 0xff, 0xff, 0x76, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x76, 0x0c, 0x00, 0x0c, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x04, 0x00, 0x04, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x4f, 0x4e, 0x45, 0x2d, 0x74, 0x66, 0x6c, 0x69,
  0x74, 0x65, 0x32, 0x63, 0x69, 0x72, 0x63, 0x6c, 0x65, 0x00, 0x00, 0x00};

const std::vector<float> input_data = {1.}; // cast to bool

const std::vector<float> input1_data = {1., 1., 1., 1., 1., 1.};
const std::vector<float> input2_data = {1., 1., 1., 1., 1., 1.};

const std::vector<float> reference_output_data = {1., 1., 1., 1., 1., 1.};
} // namespace if_kernel

template <typename T> class TestDataIfKernel : public TestDataBase<T>
{
public:
  TestDataIfKernel()
  {
    _input_data = if_kernel::input_data;
    _input1_data = if_kernel::input1_data;
    _input2_data = if_kernel::input2_data;
    _reference_output_data = if_kernel::reference_output_data;
    _test_kernel_model_circle = if_kernel::test_kernel_model_circle;
  }

  ~TestDataIfKernel() override = default;

  const unsigned char *get_model_ptr() override final { return _test_kernel_model_circle; }

  const std::vector<T> &get_input_data_by_index(int i) override final
  {
    switch (i)
    {
      case 0:
        return _input_data;
      case 1:
        return _input1_data;
      case 2:
        return _input2_data;
      default:
        assert(false && "Wrong input index");
    }
  }

  const std::vector<T> &get_output_data_by_index(int i) override final
  {
    assert(i == 0);
    return _reference_output_data;
  }

protected:
  std::vector<T> _input_data;
  std::vector<T> _input1_data;
  std::vector<T> _input2_data;
  std::vector<T> _reference_output_data;
  const unsigned char *_test_kernel_model_circle;
};

} // namespace test_kernel
} // namespace luci_interpreter

#endif // LUCI_INTERPRETER_TEST_MODELS_IF_KERNEL_H
