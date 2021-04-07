#pragma once

#include <memory>
#include <string>
#include <utility>

namespace minijson
{
	/** 
	 * A wrapper struct holding start& end positions of character interval 
	 * from the corresponding json raw string
	*/
	struct JsonObject
	{
		explicit JsonObject(const std::pair<uint16_t, uint16_t> posInString)
		: interval(posInString)
		{
		}

		std::pair<uint16_t, uint16_t> interval;
	}; // struct JsonObject

	// ========================================================================
	// Json 
	// ========================================================================

	class Json
	{
		struct JsonImpl;

		public:
		
			explicit Json(const std::string& data);
			// Intentionally declarations only 
			// for the dtor, move ctor, move assignment operator
			~Json();
			Json(Json&& rhs) noexcept;
			Json& operator= (Json&& rhs) noexcept;

			std::shared_ptr<JsonObject> rootElement() const;
            std::string rawString() const;

			size_t numObjects() const { return 0u; }
			Json operator[] (int index) const { return Json(""); }

			static Json fromFile(const std::string& path);

			bool getBool(std::shared_ptr<JsonObject> obj,
				const std::string& key) const;
			int getInt(std::shared_ptr<JsonObject> obj,
				const std::string& key) const;
			float getFloat(std::shared_ptr<JsonObject> obj,
				const std::string& key) const;
			std::string getString(std::shared_ptr<JsonObject> ojb,
				const std::string& key) const;
			std::shared_ptr<JsonObject> getObject(std::shared_ptr<JsonObject> obj,
				const std::string& key) const;

		private:			

			std::unique_ptr<JsonImpl> mImpl;
	}; // class Json
} // namespace minijson