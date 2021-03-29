#include "string_utils.h"

#include <algorithm>

namespace minijson
{
    namespace utils
    {
        std::string removeSeparators(const std::string& str)
        {
            return str.erase(std::remove_if(str.begin(), str.end(), std::isspace));
        }
    } // namespace utils
} // namespace minijson