# sarmfsw (release notes)

The MIT License (MIT)

Copyright (c) 2017-2018 SMFSW (Sebastien Bizien)

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

## v3.3

* Adding support for unit tests and doxygen documentation generation with Travis CI
* arm_attributes: Added macro for section, used nonnull(...) & multiple attibutes attributes
* arm_cmsis: Added latest STM32 chips
* arm_chip_stm32: Added enum for last reset source (TODO: add more for sam & ino)
* arm_inlines: added some binary manipulation inlines
* arm_macros & arm_stdclib: simplified STR macro (no need of "")
* arm_macros: moved TestMalloc to arm_macros.h (renamed to malloc_assert)
* arm_typedefs: Doxygen eGPIOState enum name fixed
* arm_typedefs: Doxygen note added related to Arduino platform (for binary representation in binary.h)
* sarmfsw.h: target names changed in enum
* misc: typo fixes, Doxygen comments, notes & warnings added
* Release Notes.md: sections added

## v3.2

* arm_typedefs: endianness handling for bitfields and unions
* arm_typedefs: added eGPIOState & eGPIOPull enums
* arm_inlines: added L & LL qualifiers when needed for compatibility with <32b architectures
* arm_inlines: added testEndian basic & full inlines
* arm_macros: added SWAP_TYPE macro for any simple typedef swapping
* arm_macros: added missing SWAP_LWORD, SWAP_FLOAT & SWAP_DOUBLE macros
* arm_macros: added aliases for True, False, TRUE, FALSE
* README: added list and description of special symbols to change library behavior
* keywords.txt: Added new and enum litteral keywords

## v3.1

* arm_chip_ino: fixed enable/disable interrupts macro (and undef arm_cmsis defined ones)
* arm_chip_ino: fixed Arduino HALTicks macro (ms tick base is millis, not micros)

## v3.0

* moved defines & inlines from arm_hal_peripheral to arm_family headers
* arm_macros: added ROOT_OF macro
* arm_macros: added L qualifier for LSHIFT & RSHIFT (compatibility with less than 32b CPUs)
* arm_inlines: const qualifier for most inline parameters
* arm_inlines: modified TPSSUP_MS & TPSINF_MS to handle custom tick frequency (following arm_family header or custom defines)
* arm_chip_sam: refactored doxygen comments block
* arm_cmsis: fixed multiline macro SAMDA1
* arm_chip_ino: made compatible with Arduino platform

## v2.0

* arm_macros: added shifting macros & refactoring
* arm_inlines: refactoring & addded some inlines for 64b and bcd, ascii & gray code
* arm_inlines: removed some always inline qualifiers for some inlines producing lots of instructions
* arm_inlines: inTolerance tolerance param is now float for higher accuracy when needed
* arm_inlines: using an alias defined in arm_hal_peripheral.h for GetTicks call
* arm_inlines: added get_fp_dec (formerly in HARMcksL)
* arm_cmsis: updated latest chips references for STMicro
* arm_cmsis: platform CMSIS includes & HAL config included from there
* arm_cmsis: removed including HAL config (already included from CMSIS includes)
* arm_hal_peripheral: added to include used peripherals
* arm_hal_peripheral: reworked all peripheral includes
* arm_chip_stm32: added wrapper for PWM tim/channels
* arm_chip_stm32: refactored wrappers for TIM & GPIO names to what's mentioned here
* arm_chip_sam: added support for Atmel SAM families
* arm_chip_xx: Families divided into files with respective fam name
* arm_errors: added to sarmfsw & refactored ERR_xx to ERROR_xx
* arm_attributes: renamed WEAK__ to __WEAK
* arm_attributes: added various compiler attributes definition
* added missing includes in some headers (to be able to import them as standalone)
* refactored includes order and where some declarations are done through files
* refactored names of platform header files
* added anchors to define external C (for Cpp)

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
