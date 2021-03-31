#include "string_utils.h"

#include <algorithm>

namespace minijson
{
    namespace utils
    {
        void StringUtils::removeWhitespace(std::string& input)
        {
            input.erase(
                std::remove_if(input.begin(), input.end(), std::isspace),
                input.end()
            );
        }
    } // namespace utils
} // namespace minijson