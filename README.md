# sarmfsw

ARM based common headers

Basic yet useful typedefs/macros/inlines for any ARM CMSIS based project

Library has been updated to become compatible with Arduino platform
(not only ARM cores, yet less optimized for 8/16bit cores)

## Library handled symbols (to be defined if needed)

* STM_FAMILY: Define with proper family name if your STM32 MCU is not automatically recognized (in case of warning message displayed)
* SAM_FAMILY: Define with proper family name if your ATMEL SAM MCU is not automatically recognized (in case of warning message displayed)
* HAL_MAX_TICKS val: Define with custom max value in project if tick max value is not using 32b variable full scale
* HAL_MS_TICKS_FACTOR: Define with custom multiplier in project if tick period is not 1ms
* BIG_ENDIAN: Define this symbol if using big endian target architecture if not automatically recognized (in case of warning message displayed)
* LITTLE_ENDIAN: Define this symbol if using little endian target architecture if not automatically recognized (in case of warning message displayed)
* REVERSE_BITFIELD: By default biftfields are stored from lsb to msb; if not the case with the compiler, use a pragma or define this symbol
* I_FIND_BINARY_HEADER_USEFUL: For Arduino platform, if using defines from binary.h, define this symbol (not recommended, use 0bxxx for binary instead)

## Help appreciated (and wanted):

* Cosmic compiler users: attributes aliases implementation (or related documentation)
* Texas Instruments chips users: defining families & sub-families for chips in arm_cmsis.h & peripheral includes (if available)
* Any ARM chip provider users: defining families & sub-families for chips in arm_cmsis.h & peripheral includes (if available)
* Atmel SAM users: defining new families & sub-families for chips & rationalization of peripheral includes (arm_peripherals.h)
* Arduino platform users: miscellaneous improvements (not related to <32b optimizations, ARM core being the main focus of sarmfsw library) 
* No redeeming ARM users: improvements & optimizations, additions and bug fixes are welcome as long as it still remains in the spirit of C header helpers 

## Notes

Macros/Inlines name standardization (case) not always respected for backward compatibility with older versions:
- For new users: sorry for this apparent nonsense (aliases may be implemented sooner, later or never)!
- For former users: you're welcome (except some special cases, backward compatibility should still be handled)!
 
## Documentation

Doxygen generated documentation can be found in "sarmfsw_vXXX.pdf"

## Release Notes

See [release notes](https://github.com/SMFSW/sarmfsw/ReleaseNotes.md)

## License

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
