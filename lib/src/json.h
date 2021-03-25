#pragma once

#include <string>

namespace mini
{
	class Json
	{
		public:
			explicit Json(const std::string& str);

			Json parse(const std::string& attrib) const;
			bool value() const;
			int value() const;
			float value() const;
			std::string value() const;
			size_t numObjects() const;
			Json operator[] (int index) const;

		private:
			static std::string readTextFile(const std::string& filePath);
			static Json fromFile(const std::string& filePath);
	}; // class Json
} // namespace mini