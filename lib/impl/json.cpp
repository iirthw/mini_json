#include "json.h"

#include <fstream>
#include <sstream>
#include <vector>

#include "string_utils.h"

/*
  According to the modified Backus-Naur-Form on the right side pane of http://json.org/ 
  the root element of a JSON data structure can be any of these seven types/values:
  - Object
  - Array
  - String
  - Number
  - true
  - false
  - null
*/

namespace minijson
{
    // Internal json hierarchy representation
    class JsonObject;

    // PIMPL for the Json class
    struct Json::JsonImpl
    {
        explicit JsonImpl(const std::string& data)
        : mRawData(StringUtils::removeWhitespace(data))
        {}

        std::string mRawData;
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

    Json Json::fromFile(const std::string& path)
    {
        std::ifstream inStream(path); // RAII object => will close automatically on destruction
        std::stringstream stringBuffer;
        stringBuffer << inStream.rdbuf();
        
        return Json(stringBuffer.str());
    }

    // =========================================================================
    // JsonObject
    // =========================================================================

} // namespace minijson