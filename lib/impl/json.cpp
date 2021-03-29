#include "json.h"

#include <memory>
#include <vector>

#include "string_utils.h"

namespace minijson
{
    // Class to represent internal json objects hierarchy
    struct Json::JsonImpl
    {
        explicit JsonImpl()
        : mRawData(utils::removeSeparators(data))
        , mChildren({}) {}

        std::string mRawData;            
        std::vector<std::unique_ptr<JsonIntern>> mChildren;
    };

    // =========================================================================
    // Json 
    // =========================================================================
    Json::Json(const std::string& data)
    : mImpl(std::make_unique<JsonImpl>(data))
    {}

    Json::~Json() = default;
    Json::Json(Json&& rhs) noexcept = default;
    Json& Json::operator= (Json&& rhs) noexcept = default;
} // namespace minijson