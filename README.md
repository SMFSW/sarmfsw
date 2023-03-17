# sarmfsw [![Build Status](https://app.travis-ci.com/SMFSW/sarmfsw.svg?branch=master)](https://app.travis-ci.com/SMFSW/sarmfsw)

ARM based common headers

Basic yet useful typedefs/macros/inlines for any ARM CMSIS based project

Library has been updated to become compatible with Arduino & other 8/16bit platforms
(not only ARM cores, yet less optimized for 8/16bit cores)

## Library handled symbols (to be defined if needed, at project level)

* `STM_FAMILY`: Define with proper family name if your STM32 MCU is not automatically recognized (in case of warning message displayed)
* `SAM_FAMILY`: Define with proper family name if your ATMEL SAM MCU is not automatically recognized (in case of warning message displayed)

* `HAL_MAX_TICKS` val: Define with custom max value in project if tick max value is not using 32b variable full scale
* `HAL_MS_TICKS_FACTOR`: Define with custom multiplier in project if tick period is not 1ms

* `BIG_ENDIAN`: Define this symbol when using big endian target architecture if not automatically recognized (in case of warning message displayed)
* `LITTLE_ENDIAN`: Define this symbol when using little endian target architecture if not automatically recognized (in case of warning message displayed)
* `REVERSE_BITFIELD`: By default biftfields are stored from lsb to msb; if not the case with used compiler, use a pragma or define this symbol

* `STDBOOL_NDEF`: define this symbol in case used compiler doesn't have stdbool.h header
* `STDINT_NDEF`: define this symbol in case used compiler doesn't have stdint.h header
* `I_FIND_BINARY_HEADER_USEFUL`: For Arduino platform, if using defines from binary.h, define this symbol (not recommended, use 0bxxx for binary instead)

* `SINGLE_SHIFT_ONLY_OPCODE`: If used CPU only handles single shifts opcode, define this symbol to optimize use of LSHIFTx & RSHIFTx with constants

* `NO_STATIC_FUNC` or `UNITY_TESTING`: using __STATIC keyword, functions will always be visible by linker if set (useful for unit testing)

## Help would be appreciated:

* Cosmic compiler users: attributes aliases implementation (or related documentation)
* Texas Instruments chips users: defining families & sub-families for chips in arm_cmsis.h & peripheral includes (if available)
* Any ARM chip provider users: defining families & sub-families for chips in arm_cmsis.h & peripheral includes (if available)
* Atmel SAM users: defining new families & sub-families for chips & rationalization of peripheral includes (arm_peripherals.h)
* Arduino platform users: miscellaneous improvements (not related to <32b optimizations, ARM core being the main focus of sarmfsw library)
* No redeeming ARM users: improvements & optimizations, additions and bug fixes are welcome as long as it still remains in the spirit of C header helpers

## Notes

Macros/Inlines name standardization (case) not always respected for backward compatibility with older versions:
- For new users: sorry for this apparent nonsense (aliases may be implemented sooner, later, bust most likely never)!
- For former users: you're welcome (except some special cases, backward compatibility should still be handled)!
 
## Documentation

Doxygen doc can be generated using "Doxyfile"

See [generated documentation](https://smfsw.github.io/sarmfsw/)

## Release Notes

See [release notes](ReleaseNotes.md)
