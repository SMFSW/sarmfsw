# sarmfsw (release notes)

The MIT License (MIT)

Copyright (c) 2017-2025 SMFSW (Sebastien Bizien)

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

## v3.7

* Partial MISRA C2012 compliance
* enums, unions, structs tag names change (now with leading _)
* arm_preprocess: added (for pre-processing macros and directives needed to be defined at the beginning of sarmfsw)
* arm_macros: CAT, XCAT, STR & XSTR moved to arm_preprocess
* sarmfsw: arm_preprocess added & arm_macros moved
* arm_typedefs: uintPTR_t & intPTR_t added
* arm_stdclib: renamed to arm_inlines_stdclib, total refactoring and inlines added
* arm_attributes: PRINTF__ & FMT__ attributes added (+ some compilers attributes review)
* I_FIND_BINARY_HEADER_USEFUL symbol renamed to USE_INO_BINARY_HEADER
* arm_typedefs & arm_chip_ino: fix for USE_INO_BINARY_HEADER (re-define B0 & B1)
* arm_errors: error codes added
* arm_chip_stm32: STM32_UNIQUE_ID split to get 3 different parts of unique ID
* arm_inlines_float: get_fp_dec fix for negative values
* arm_cmsis: update for STM32 families (also added H7RS, MP2, MP13, N6, WB0 families)
* arm_macros: isNull & isNotNull added
* arm_macros: isOdd & isEven added
* arm_macros: SET_BITS_VAL also applies mask on given value to apply
* arm_inlines_ascii: strHexToInt fix for 8b/16b platforms
* arm_inlines_var_test: inTolerance fix for negative reference values
* arm_cmsis: SARMFSW_NO_CHIP_HAL symbol implementation
* arm_cmsis & arm_chip_xxx: HALTicks symbol refactoring and checks added for provided function declaration consistency
* arm_macros: TEST_BITS_VAL & TEST_MASK_VAL macros added
* arm_macros: Register intended macros (such as GET_BITS...) encloses tested variable/register/values in parenthesis
* arm_macros: OVF_DIFF fix, thanks to @Simben
* keywords.txt: update
* arm_inlines_float: SPLIT_FLOAT_TO_INTS added
* arm_inlines_float: sIntFrac struct and associated float2sIntFrac and sIntFrac2float functions added
* arm_cmsis: Some CMSIS alias macros added
* arm_macros: XSTR added (stringification of an expanded macro)
* arm_stdclib: str_add_cr change (adding only cr) + str_add_lf and str_add_crlf added 
* arm_macros: OVF_DIFF added (overflow handling diff)
* arm_inline_ticks: inlines use of OVF_DIFF
* arm_macros: min, max, min3, max3 & clamp refactored (double evaluation safe)
* arm_macros: min & max declared as upper case, preventing std::min std::max issues when library is included in cpp file
* min and max uses set to upper case in the whole library (cpp std workaround)
* arm_attributes: TYPEOF__ alias added, ASM__ alias set to __asm__ for consistency
* sarmfsw: include order set back (to keep compatibility without warnings with older cmsis versions)
* arm_chip_xxx: all qualifier macros for functions changed by explicit qualifiers (due to includes order)
* sarmfsw: include order fix (so that arm_chip_xxx attributes can be properly pre-processed) -> revert
* arm_hal_peripheral: pre-processing symbols can be defined to disable HAL includes (globally or separately)

## v3.6

* arm_cmsis: update for STM32 families (also added H5, WBA families)
* sarmfsw: includes order fix
* arm_attributes: __STATIC keyword added
* arm_attributes: __INLINE keyword workaround with C99 inline semantics (static inlining)
* library entry point being sarmfsw.h, most cross includes in files now removed
* inlines variable length and types reviewed
* arm_inlines_average: code size optimization
* arm_hal_peripheral: PCD device enabled includes usb_device.h header
* arm_macros: SCALE_VAL_T added
* arm_macros: BYTE_TO_PERC byte value clamp added
* arm_macros: LSHIFT & RSHIFT changed (handling optimized shift opcodes and more explicit sizes if desired/required)
* arm_typedefs.h: intCPU_t & uintCPU_t typedefs added
* arm_hal_peripheral: No include for some peripherals without dedicated headers (STM32)
* arm_chip_xxx: an external definition of HAL_getTick is provided when used (implicitly checking consistency with the one defined in project)
* arm_attributes: few fixes and CSMC compiler attributes added
* arm_cmsis: volatile symbols definition added in case not defined
* arm_cmsis: UNUSED symbol definition (removed multiple definitions from other files)
* arm_cmsis: __ASM symbol definition moved to arm_attributes.h
* arm_cmsis: xc symbol test fix; moved __INLINE and __STATIC_INLINE definitions (when defined) in arm_attributes.h
* arm_attributes: manual definition of __INLINE and __STATIC_INLINE if __STATIC_FORCEINLINE is not defined
* arm_attributes: xc symbol test fix; moved xc part prior to gnuc (as the symbol is also defined by xc compiler)
* README & keywords.txt update
* arm_cmsis: update for STM32 families (also added C0, U5 families)
* introducing Microchip XC compiler & PIC compatibility
* arm_typedefs: stdbool.h & stdint.h can be skept if not handled by compiler (through pre-processing symbols definition)
* arm_typedefs: matching stdbool.h & stdint.h common types used in arm_typdefs.h to native C types by typedefs if headers are not included
* arm_inlines_ascii: strDecToInt & strHexToInt returns correctly converted part if something goes wrong
* arm_inlines_ascii: added check and convert inlines (num, alphanum, lower and upper case)
* arm_inlines_ascii: added strDecToInt & strHexToInt
* arm_inlines_linearization: sLinearFlexArray typedef & linearization_eval_flex function added 
* arm_inlines_linearization: linearization_eval constant parameters, nb values set to 32b
* arm_inlines_linearization: linearXXX LINEAR_TAB macro generated name now outputs sLinearXXX
* arm_attributes: scalar storage order attributes defined for __GNUC__ compiler (mostly for reference, not defined for other compilers)
* Doxyfiles updated to reflect changes in Doxygen v1.9.x

## v3.5

* arm_inlines_ascii: fix lower case result of ASCIIToHex
* arm_inlines_var_size: fix reducing number of bits in convXtoYBits
* arm_inlines_float: limit set to 9 digits after floating point in get_fp_dec
* arm_attributes: Overriding inline attributes when optimizations are set to none with gcc like toolchains
* Doxyfiles updated to reflect changes in Doxygen v1.9.x

## v3.4

* Some refactoring
* arm_chip_stm32: few changes using G0 family
* arm_chip_stm32: Added other reset sources in eResetSource
* arm_chip_stm32: pins & ports refactored to stm_xxx
* arm_cmsis: update for STM32 families (also added G4, L5, MP1 & WB families)
* arm_macros: SZ_ARRAY macro added
* arm_macros: charNUL renamed to charNULL
* arm_macros: mathematical constants under the macro form M_xxx as in math.h
* arm_macros: added bitwise boolean arithmetic macros (useful for register or bitfields registers/variables)
* arm_macros: added SCALE_VAL macro
* arm_inlines: inlines split into separate files
* arm_inlines_angle: added inlines instead of associated macros in arm_macros.h (and associated constants)
* arm_inlines_angle: DEG_TO_RAD & RAD_TO_DEG not defined for Arduino platforms (already defined as conversion value)
* arm_inlines_bcd: updated inlines to handle up to 32b conversions
* arm_inlines_rotation: added 2D coordinates rotation inline
* arm_inlines_linearization: added linearization inline
* arm_inlines_ascii: fix HexToASCII
* arm_inlines_float: changed get_fp_dec to get decimal part as absolute value
* arm_inlines_var_size: added mask on input value in convXtoYBits (if value given size mismatch with from size)
* arm_inlines_var_size: replaced sums by bitwise or operations in every variable size expansion inlines 
* arm_inlines_var_size: added scaleValue macro
* arm_stdclib: fix str_clr_safe use of sarmfsw macros and use of predefined macros
* arm_typedefs: BIG_ENDIAN/LITTLE_ENDIAN/PDP_ENDIAN changed to ___XXX_ENDIAN___ (were already all defined in endian.h)

## v3.3

* Doxyfile update
* Adding support for unit tests and doxygen documentation generation with Travis CI
* Few type names changed to their own typedefs
* arm_attributes: Added macro for section, used, nonnull(...) & ATTR__ multiple attributes
* arm_cmsis: Added latest STM32 chips (and STM32G0 family added)
* arm_chip_stm32: Added FLASH_SIZE macro (returning flash size in bytes)
* arm_chip_stm32: Added enum for last reset source (TODO: add more for sam & ino)
* arm_chip_stm32: Added some special STM32 registers getter macros
* arm_hal_peripheral: Removed unlikely defined include files (not related to STM32 peripherals, rather linked to middlewares)
* arm_hal_peripheral: Fixed qspi.h include (quadspi.h)
* arm_inlines: added some binary manipulation inlines
* arm_inlines: added nonnull check for pointers in SWAP_ENDxxB_TAB
* arm_inlines: added temperature conversions (kelvin, celsius, fahrenheit)
* arm_inlines: added RestrictedAverage_XXX inlines
* arm_inlines: ASCIIToHex returns BYTE with 0xFF value if not valid ASCII char
* arm_inlines: var size conversions (bits) fixed to gain accuracy
* arm_inlines: inline added to convert var size from x to y number of bits
* arm_macros & arm_stdclib: simplified STR macro (no need of "")
* arm_macros: moved TestMalloc to arm_macros.h (renamed to malloc_assert)
* arm_macros: added SZ_TYP_MBR macro to get the sizeof of a member in a structure
* arm_macros: added TYP_MBR macro to get member of typedef struct
* arm_macros: added TYP_MBR_TYP macro to get type of member in typedef struct
* arm_macros: added VAL_AT macro to get content of an address
* arm_macros: added undef of LOBYTE & HIBYTE if previously defined
* arm_typedefs: Doxygen eGPIOState enum name fixed
* arm_typedefs: Doxygen note added related to Arduino platform (for binary representation in binary.h)
* sarmfsw.h: target names changed in enum
* keywords.txt: added Error codes & Reset codes
* misc: typo fixes, Doxygen comments, notes & warnings added
* README.md: sections added

## v3.2

* arm_typedefs: endianness handling for bitfields and unions
* arm_typedefs: added eGPIOState & eGPIOPull enums
* arm_inlines: added L & LL qualifiers when needed for compatibility with <32b architectures
* arm_inlines: added testEndian basic & full inlines
* arm_macros: added SWAP_TYPE macro for any simple typedef swapping
* arm_macros: added missing SWAP_LWORD, SWAP_FLOAT & SWAP_DOUBLE macros
* arm_macros: added aliases for True, False, TRUE, FALSE
* README: added list and description of special symbols to change library behavior
* keywords.txt: Added new and enum literal keywords

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
* arm_cmsis: fixed multi-line macro SAMDA1
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
* arm_chip_xx: Families divided into files with respective family name
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
