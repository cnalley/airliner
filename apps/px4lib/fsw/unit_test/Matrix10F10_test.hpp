/****************************************************************************
*
*   Copyright (c) 2017 Windhover Labs, L.L.C. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
* 3. Neither the name Windhover Labs nor the names of its 
*    contributors may be used to endorse or promote products derived 
*    from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/

#ifndef MATRIX10F10_TEST_H
#define MATRIX10F10_TEST_H

#ifdef __cplusplus
extern "C" {
#endif

void Test_Matrix10F10_Constructor(void);
void Test_Matrix10F10_Mult_10F(void);
void Test_Matrix10F10_Mult_10F1(void);
void Test_Matrix10F10_Mult_10F_Random(void);
void Test_Matrix10F10_Mult_10F1_Random(void);
void Test_Matrix10F10_Mult_10F3(void);
void Test_Matrix10F10_Mult_10F3_Random(void);
void Test_Matrix10F10_Mult_10F6(void);
void Test_Matrix10F10_Mult_10F6_Random(void);
void Test_Matrix10F10_Mult_10F10(void);
void Test_Matrix10F10_Mult_10F10_Sparse(void);
void Test_Matrix10F10_Mult_10F10_Random(void);
void Test_Matrix10F10_Mult_Scaler(void);
void Test_Matrix10F10_Addition(void);
void Test_Matrix10F10_Addition_Random(void);
void Test_Matrix10F10_Subtraction(void);
void Test_Matrix10F10_Subtraction_Random(void);
void Test_Matrix10F10_Zero(void);
void Test_Matrix10F10_Identity(void);
void Test_Matrix10F10_Transpose(void);
void Test_Matrix10F10_PlusEquals(void);
void Test_Matrix10F10_PlusEquals_Random(void);
void Test_Matrix10F10_MinusEquals(void);
void Test_Matrix10F10_MinusEquals_Random(void);


#ifdef __cplusplus
}
#endif

#endif /* MATRIX10F10_TEST_H */