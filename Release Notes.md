# sarmfsw (release notes)

The MIT License (MIT)

Copyright (c) 2017 SMFSW (Sebastien Bizien)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


## v1.1

* arm_macros: added shifting macros & refactoring
* arm_inlines: refactoring & addded some inlines for 64b and bcd, ascii & gray code
* arm_inlines: removed some always inline qualifiers for some inlines producing lots of instructions
* arm_inlines: inTolerance tolerance param is now float for higher accuracy when needed
* arm_cmsis: updated latest chips references for STMicro
* arm_cmsis: platform CMSIS includes & HAL config included from there
* arm_cmsis: removed including HAL config (already included from CMSIS includes)
* arm_hal_peripheral: added to include used peripherals
* arm_hal_peripheral: reworked all peripheral includes
* arm_chip_stm32: added wrapper for PWM tim/channels
* arm_chip_stm32: refactored wrappers for TIM & GPIO names to what's mentioned here
* arm_chip_xx: Families divided into files with respective fam name
* arm_errors: added to sarmfsw
* refactoring names of platform header files

## v1.0

* arm_cmsis: added generic define for all families
* STM\_CONF\_HEADER() include hal header file instead of hal conf directly (more HAL access)
* Added macro SZ_OBJ to compute number of elements of an object following its type
* arm_cmsis: added macros to enable/disable interrupts
* arm_macros: Renamed macro OFFSETOF, now OFFSET_OF & removed space after & in OFFSET_OF macro (causing issues compiling with gcc)
* arm_macros: Some refactoring and bool returning inlines optimization
* sarmfsw: includes CMSIS & HAL header files by default
* arm_inlines: Added file for inlines, as some needs to access to HAL (included after arm_cmsis)
* arm_inlines: inRange & inTolerance now using int32_t

## v0.9 and below

* initial commit and beta versions
