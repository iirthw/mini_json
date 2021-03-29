#pragma once

#include <memory>
#include <string>

namespace minijson
{
	class Json
	{
		public:
		
			explicit Json(const std::string& data);
			~Json();
			Json(Json&& rhs) noexcept;
			Json& operator= (Json&& rhs) noexcept;

			// FIXME: all of the following have dummy implementation

			explicit Json(const std::string& data);

			Json parse(const std::string& attrib) const { return Json(""); }
			bool getBool(const std::string& key) const { return false; }
			int getInt(const std::string& str) const { return 0; }
			float getFloat(const std::string& str) const { return 0.0f; }
			std::string getString(const std::string& str) const { return ""; }
			int getInt(const std::string& key) const;
			float getFloat(const std::string& key) const { return 0.0f; }
			std::string getString(const std::string& key) const { return ""; }

			size_t numObjects() const { return 0u; }
			Json operator[] (int index) const { return Json(""); }

		private:
			static std::string readTextFile(const std::string& filePath) { return ""; }
			static Json fromFile(const std::string& filePath) { return Json(""); }

			struct JsonImpl;
			std::unique_ptr<JsonImpl> mImpl;
	}; // class Json
} // namespace minijson