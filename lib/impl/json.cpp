#include "json.h"

#include <vector>

#include "string_utils.h"

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

        std::shared_ptr<JsonObject>
            getObject(std::shared_ptr<JsonObject> obj, const std::string& key) const
        {
            return nullptr;
        }

        bool getBool(std::shared_ptr<JsonObject> obj, const std::string& key) const
        {
            return false;
        }

        int	getInt(std::shared_ptr<JsonObject> obj, const std::string& key) const
        {
            return 0;
        }

        float getFloat(std::shared_ptr<JsonObject> obj, const std::string& key) const
        {
            return 0.0f;
        }

        std::string getString(std::shared_ptr<JsonObject> obj, const std::string& key) const
        {
            return "";
        }

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

    std::shared_ptr<JsonObject> 
        Json::getObject(std::shared_ptr<JsonObject> obj, const std::string& key) const
    {
        return mImpl->getObject(obj, key);
    }

    bool Json::getBool(std::shared_ptr<JsonObject> obj, const std::string& key) const
    {
        return mImpl->getBool(obj, key);
    }

    int	Json::getInt(std::shared_ptr<JsonObject> obj, const std::string& key) const
    {
        return mImpl->getInt(obj, key);
    }

    float Json::getFloat(std::shared_ptr<JsonObject> obj, const std::string& key) const
    {
        return mImpl->getFloat(obj, key);
    }

    std::string Json::getString(std::shared_ptr<JsonObject> obj, const std::string& key) const
    {
        return mImpl->getString(obj, key);
    }

    // =========================================================================
    // JsonObject
    // =========================================================================

} // namespace minijson