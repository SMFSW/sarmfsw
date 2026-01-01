# sarmfsw

[![author](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/SMFSW/a9a2b2a02fda1b33461d53ddfe69d649/raw/auth_SMFSW.json)](https://github.com/SMFSW)
![badge](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/SMFSW/a9a2b2a02fda1b33461d53ddfe69d649/raw/sarmfsw_status_badge.json)
[![license](https://img.shields.io/badge/License-MIT-darkred.svg)](LICENSE)
[![CodeFactor](https://www.codefactor.io/repository/github/smfsw/sarmfsw/badge)](https://www.codefactor.io/repository/github/smfsw/sarmfsw)

![platform](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/SMFSW/a9a2b2a02fda1b33461d53ddfe69d649/raw/platform_ARM.json)
![platform](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/SMFSW/a9a2b2a02fda1b33461d53ddfe69d649/raw/platform_INO.json)

[![doxy](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/SMFSW/a9a2b2a02fda1b33461d53ddfe69d649/raw/tool_DOXY.json)](https://smfsw.github.io/sarmfsw)
[![re_note](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/SMFSW/a9a2b2a02fda1b33461d53ddfe69d649/raw/tool_RN.json)](ReleaseNotes.md)

![badge](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/SMFSW/a9a2b2a02fda1b33461d53ddfe69d649/raw/sarmfsw_custom_repo_badge.json)

ARM based common headers

Collection of typedefs/macros/inlines for any ARM CMSIS based project

Library is compatible with Arduino & other 8b/16b/32b platforms (not optimized for 8b/16b cores though)

## Library handled symbols (to be defined if needed, at project level)

* `STM_FAMILY`: Define with proper family name if your STM32 MCU is not automatically recognized (warning message will be triggered in such case)
* `SAM_FAMILY`: Define with proper family name if your SAM MCU is not automatically recognized (warning message will be triggered in such case)

* `SARMFSW_NO_CHIP_HAL`: No includes and definitions of HAL chip files (can be useful to use sarmfsw for static libraries code generation)

* `HAL_INC_DISABLE`: Define this symbol at project level to disable inclusion of all HAL headers (automatically set when `SARMFSW_NO_CHIP_HAL` is defined)
* `HAL_XXX_INC_DISABLE`: Define this symbol at project level (replacing `XXX` by peripheral name) to disable inclusion of corresponding HAL header

* `HALTicks`: can be defined with a function name to use ticks getter function already implemented under the form `uint32_t ms_tick_get(void)`

* `HAL_MAX_TICKS` `val`: Define with custom maximum value `val` in project if tick maximum value is not using unsigned 32b full scale
* `HAL_MS_TICKS_FACTOR` `val`: Define with custom multiplier `val` in project if tick period is not triggered every 1ms

* `BIG_ENDIAN`: Define this symbol when using big endian target architecture if not automatically recognized (warning message will be triggered in such case)
* `LITTLE_ENDIAN`: Define this symbol when using little endian target architecture if not automatically recognized (warning message will be triggered in such case)
* `REVERSE_BITFIELD`: Bitfields are stored from lsb to msb as default in sarmfsw; use a pragma or define this symbol in case your compiler stores bitfields from msb to lsb

* `STDBOOL_NDEF`: define this symbol in case used compiler doesn't have stdbool.h header
* `STDINT_NDEF`: define this symbol in case used compiler doesn't have stdint.h header
* `USE_INO_BINARY_HEADER`: For Arduino platform, some binary.h definitions needs to be undefined.
	If you find them useful, define USE_INO_BINARY_HEADER before including sarmfsw.h to keep them defined.
	Please note, B0 & B1 Bytes sub-structures of unions defined hereafter will not be available in this case.
	bxxxxxxxx C standard notation can be used for binary instead, using this symbol is highly discouraged due to previously mentioned drawbacks.

* `SINGLE_SHIFT_ONLY_OPCODE`: If used CPU only handles single shifts opcode, you may define this symbol to hopefully optimize use of LSHIFTx & RSHIFTx with constants

* `NO_STATIC_FUNC` or `UNITY_TESTING`: using __STATIC keyword, functions will always be visible by linker if set (useful for unit testing)

## Notes

Macros/Inlines name standardization (case) not always respected for backward compatibility with older versions:
- For new users: sorry for this apparent nonsense (aliases may be implemented sooner, later, bust most likely never)!
- For former users: you're welcome (except for some special cases, backward compatibility should still be handled)!
