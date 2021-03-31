#include "string_utils.h"

#include <algorithm>

namespace minijson
{
    void StringUtils::removeWhitespace(std::string& input)
    {
        input.erase(
            std::remove_if(input.begin(), input.end(), std::isspace),
            input.end()
        );
    }
} // namespace minijson