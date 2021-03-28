#pragma once

#include <string>

namespace minijson
{
	class Json
	{
		public:
			// FIXME: all of the following have dummy implementation

			explicit Json(const std::string& str)
			: mRawData(str) {}

			Json parse(const std::string& attrib) const { return Json(""); }
			bool getBool(const std::string& key) const { return false; }
			int getInt(const std::string& str) const { return 0; }
			float getFloat(const std::string& str) const { return 0.0f; }
			std::string getString(const std::string& str) const { return ""; }
			size_t numObjects() const { return 0u; }
			Json operator[] (int index) const { return Json(""); }

		private:
			static std::string readTextFile(const std::string& filePath) { return ""; }
			static Json fromFile(const std::string& filePath) { return Json(""); }

			std::string mRawData;
	}; // class Json
} // namespace minijson