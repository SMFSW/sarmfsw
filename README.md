# sarmfsw

ARM based common headers

Basic yet useful typedefs/macros/inlines for any ARM CMSIS based project

Library has been updated to become compatible with Arduino & other 8/16bit platforms
(not only ARM cores, yet less optimized for 8/16bit cores)

## Library handled symbols (to be defined if needed, at project level)

* `STM_FAMILY`: Define with proper family name if your STM32 MCU is not automatically recognized (in case of warning message displayed)
* `SAM_FAMILY`: Define with proper family name if your ATMEL SAM MCU is not automatically recognized (in case of warning message displayed)

* `SARMFSW_NO_CHIP_HAL`: No includes and definitions of HAL chip files (can be useful to use sarmfsw for static libraries code generation)

* `HALTicks`: can be defined with a function name to use ticks getter function already implemented under the form `uint32_t func(void)`

* `HAL_MAX_TICKS` val: Define with custom max value in project if tick max value is not using 32b variable full scale
* `HAL_MS_TICKS_FACTOR`: Define with custom multiplier in project if tick period is not 1ms

* `HAL_INC_DISABLE`: Define this symbol at project level to disable inclusion of all HAL headers
* `HAL_XXX_INC_DISABLE`: Define this symbol at project level (replacing `XXX` by peripheral name) to disable inclusion of corresponding HAL header

* `BIG_ENDIAN`: Define this symbol when using big endian target architecture if not automatically recognized (in case of warning message displayed)
* `LITTLE_ENDIAN`: Define this symbol when using little endian target architecture if not automatically recognized (in case of warning message displayed)
* `REVERSE_BITFIELD`: By default bitfields are stored from lsb to msb; if not the case with used compiler, use a pragma or define this symbol

* `STDBOOL_NDEF`: define this symbol in case used compiler doesn't have stdbool.h header
* `STDINT_NDEF`: define this symbol in case used compiler doesn't have stdint.h header
* `USE_INO_BINARY_HEADER`: For Arduino platform, some binary.h definitions needs to be undefined.
	If you find them useful, define USE_INO_BINARY_HEADER before including sarmfsw.h to keep them defined.
	Please note, B0 & B1 Bytes sub-structures of unions defined hereafter will not be available in this case.
	(0bxxx notation can be used for binary instead)

* `SINGLE_SHIFT_ONLY_OPCODE`: If used CPU only handles single shifts opcode, define this symbol to optimize use of LSHIFTx & RSHIFTx with constants

* `NO_STATIC_FUNC` or `UNITY_TESTING`: using __STATIC keyword, functions will always be visible by linker if set (useful for unit testing)

## Notes

Macros/Inlines name standardization (case) not always respected for backward compatibility with older versions:
- For new users: sorry for this apparent nonsense (aliases may be implemented sooner, later, bust most likely never)!
- For former users: you're welcome (except some special cases, backward compatibility should still be handled)!
 
## Documentation

Doxygen doc can be generated using "Doxyfile"

See [generated documentation](https://smfsw.github.io/sarmfsw/)

## Release Notes

See [release notes](ReleaseNotes.md)
