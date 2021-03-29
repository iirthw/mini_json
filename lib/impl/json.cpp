#include "json.h"

namespace minijson
{
    Json::Json(const std::string& data)
    : mRawData(utils::removeSeparators(data)) {}

} // namespace minijson