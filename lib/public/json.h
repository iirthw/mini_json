#pragma once

#include <memory>
#include <string>

namespace minijson
{
	class JsonObject;

	class Json
	{
		public:
		
			explicit Json(const std::string& data);
			// Intentionally declarations only 
			// for the dtor, move ctor, move assignment operator
			~Json();
			Json(Json&& rhs) noexcept;
			Json& operator= (Json&& rhs) noexcept;

			std::shared_ptr<JsonObject> 
				getObject(std::shared_ptr<JsonObject> obj,const std::string& key) const;
			bool getBool(std::shared_ptr<JsonObject> obj, const std::string& key) const;
			int getInt(std::shared_ptr<JsonObject> obj, const std::string& key) const;
			float getFloat(std::shared_ptr<JsonObject> obj, const std::string& key) const;
			std::string getString(std::shared_ptr<JsonObject> obj, const std::string& key) const;

			size_t numObjects() const { return 0u; }
			Json operator[] (int index) const { return Json(""); }

		private:
			
			static std::string readTextFile(const std::string& filePath) { return ""; }
			static Json fromFile(const std::string& filePath) { return Json(""); }

			struct JsonImpl;
			std::unique_ptr<JsonImpl> mImpl;
	}; // class Json
} // namespace minijson