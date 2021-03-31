#pragma once

#include <string>

namespace minijson
{
    class StringUtils
    {
        public:
            /**
            * @brief A helper static member function which remove
            *        all white-space characters from the input string.
            * @return the string which is obtained from the input string
            *         by removing all white space characters.
            *
            * For the "C" locale, white-space characters are any of:  
            * ' '   (0x20)  space (SPC)
            * '\t'    (0x09)  horizontal tab (TAB)
            * '\n'    (0x0a)  newline (LF)
            * '\v'    (0x0b)  vertical tab (VT)
            * '\f'    (0x0c)  feed (FF)
            * '\r'    (0x0d)  carriage return (CR
            */
            static std::string removeWhitespace(std::string str); // Intentionally pass by value as we actually need a copy
    }; // class StringUtils
} // namespace minijson