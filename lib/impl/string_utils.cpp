#include "string_utils.h"

#include <algorithm>

namespace minijson
{
    // Pass by value is intentional (instead of const &) since the method 
    // needs a copy of the original input string anyway. Returning by value
    // will also benefit from NRVO in our particular case.
    std::string StringUtils::removeWhitespace(std::string str)
    {
        str.erase(std::remove_if(str.begin(), str.end(), std::isspace),
                  str.end());
        return str;
    }
} // namespace minijson