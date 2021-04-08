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
    // PIMPL for the Json class
    struct Json::JsonImpl
    {
        explicit JsonImpl(const std::string& data)
        : mRawData(StringUtils::removeWhitespace(data))
        {}

        std::shared_ptr<JsonObject> rootElement() const;

        std::string mRawData;
    };

    // ========================================================================
    // JsonImpl
    // ========================================================================

    std::shared_ptr<JsonObject> Json::JsonImpl::rootElement() const
    {
        const uint16_t posStart = (mRawData.front() == '{') ? 1u : 0u;
        const uint16_t posEnd = (mRawData.back() == '}') ? mRawData.length() - 1 : mRawData.length();
        return std::make_shared<JsonObject>(std::make_pair(posStart, posEnd));
    }

    // ========================================================================
    // Json 
    // ========================================================================

    Json::Json(const std::string& data)
    : mImpl(std::make_unique<JsonImpl>(data))
    {}

    Json::~Json() = default;
    Json::Json(Json&& rhs) noexcept = default;
    Json& Json::operator= (Json&& rhs) noexcept = default;

    std::shared_ptr<JsonObject> Json::rootElement() const
    {
        return mImpl->rootElement();
    }

    std::string Json::rawString() const
    {
        return mImpl->mRawData;
    }

    Json Json::fromFile(const std::string& path)
    {
        std::ifstream inStream(path); // RAII object => will close automatically on destruction
        std::stringstream stringBuffer;
        stringBuffer << inStream.rdbuf();
        
        return Json(stringBuffer.str());
    }

    bool Json::getBool(std::shared_ptr<JsonObject> obj, const std::string& key) const
    {
        return false;
    }

    int Json::getInt(std::shared_ptr<JsonObject> obj, const std::string& key) const
    {
        return 0;
    }

    float Json::getFloat(std::shared_ptr<JsonObject> obj, const std::string& key) const
    {
        return 0.0f;
    }

    std::string Json::getString(std::shared_ptr<JsonObject> obj, const std::string& key) const
    {
        return "";
    }

    std::shared_ptr<JsonObject> Json::getObject(std::shared_ptr<JsonObject> obj,
        const std::string& key) const
    {
        return nullptr;
    }
} // namespace minijson