#pragma once

#include <memory>
#include <string>

namespace minijson
{
	class JsonObject
	{
		public:

			bool getBool(const std::string& key) const { return false; }
			int getInt(const std::string& key) const { return 0; }
			float getFloat(const std::string& key) const { return 0.0f; }
			std::string getString(const std::string& key) const { return ""; }
			std::shared_ptr<JsonObject> getObject(const std::string& key) { return nullptr; }
	}; // class JsonObject

	class Json
	{
		public:
		
			explicit Json(const std::string& data);
			// Intentionally declarations only 
			// for the dtor, move ctor, move assignment operator
			~Json();
			Json(Json&& rhs) noexcept;
			Json& operator= (Json&& rhs) noexcept;

			std::shared_ptr<JsonObject> rootElement() const { return nullptr; }

			size_t numObjects() const { return 0u; }
			Json operator[] (int index) const { return Json(""); }

		private:
			
			static std::string readTextFile(const std::string& filePath) { return ""; }
			static Json fromFile(const std::string& filePath) { return Json(""); }

			struct JsonImpl;
			std::unique_ptr<JsonImpl> mImpl;
	}; // class Json
} // namespace minijson