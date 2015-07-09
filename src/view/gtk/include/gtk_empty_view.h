#pragma once

#include <view/interfaces/i_empty_view.h>

namespace erebus {

class GTK_EmptyView : public IEmptyView {
public:
	GTK_EmptyView();
	~GTK_EmptyView();
	
	void showContextMenu();
};

}