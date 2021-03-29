#include "string_utils.h"

#include <algorithm>

namespace minijson
{
    /*
        For the "C" locale, white-space characters are any of:  
        ' '   (0x20)  space (SPC)
        '\t'    (0x09)  horizontal tab (TAB)
        '\n'    (0x0a)  newline (LF)
        '\v'    (0x0b)  vertical tab (VT)
        '\f'    (0x0c)  feed (FF)
        '\r'    (0x0d)  carriage return (CR
    */
    std::string removeSeparators(const std::string& str)
    {
        return str.erase(std::remove_if(str.begin(), str.end(), std::isspace));
    }
} // namespace minijson