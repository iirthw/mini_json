#include "json.h"

#include <memory>
#include <vector>

#include "string_utils.h"

namespace minijson
{
    // Class to represent internal json objects hierarchy
    struct Json::JsonImpl
    {
        public:

            explicit JsonImpl()
            : mRawData(utils::removeSeparators(data))
            , mChildren({}) {}

        private:
            std::string mRawData;            
            std::vector<std::unique_ptr<JsonIntern>> children;
    };

    Json::Json(const std::string& data)
    : mRawData(utils::removeSeparators(data)) {}

} // namespace minijson