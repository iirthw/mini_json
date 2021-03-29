#pragma once

namespace minijson
{
    namespace utils
    {
        class StringUtils
        {
            public:

                /**
                 * @brief Remove all white-space characters in the input string.
                 *
                 * For the "C" locale, white-space characters are any of:  
                 * ' '   (0x20)  space (SPC)
                 * '\t'    (0x09)  horizontal tab (TAB)
                 * '\n'    (0x0a)  newline (LF)
                 * '\v'    (0x0b)  vertical tab (VT)
                 * '\f'    (0x0c)  feed (FF)
                 * '\r'    (0x0d)  carriage return (CR
                 */
                static std::string removeSeparators(const std::string& str);
        }; // class StringUtils
    } // namespace utils
} // namespace minijson