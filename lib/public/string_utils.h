#pragma once

#include <string>

namespace minijson
{
    class StringUtils
    {
        public:
            /**
            * @brief A helper static member function which remove
            * all white-space characters from the input string.
            *
            * For the "C" locale, white-space characters are any of:  
            * ' '   (0x20)  space (SPC)
            * '\t'    (0x09)  horizontal tab (TAB)
            * '\n'    (0x0a)  newline (LF)
            * '\v'    (0x0b)  vertical tab (VT)
            * '\f'    (0x0c)  feed (FF)
            * '\r'    (0x0d)  carriage return (CR
            */
            static void removeWhitespace(std::string& str);
    }; // class StringUtils
} // namespace minijson