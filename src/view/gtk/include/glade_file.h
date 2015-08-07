#pragma once

#include <string>

namespace erebus {
	enum class ViewType;
	enum class WindowType;
}

namespace erebus {

class GladeFile {
GladeFile();
public:
	~GladeFile();
	
	static std::string getFile(ViewType type);
	static std::string getFile(WindowType type);
};


}//namespace erebus
