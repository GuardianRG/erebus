#pragma once

#include <memory>

namespace erebus {
class GTK_EmptyView;
class IGUIManager;
class IEmptyViewPresenter;
}

namespace erebus {
class GTK_ViewFactory {
	GTK_ViewFactory();
  public:
	~GTK_ViewFactory();
	static GTK_EmptyView* createEmptyView(IGUIManager& manager);
	static GTK_EmptyView* createEmptyView(IGUIManager& manager,
	                                      std::unique_ptr<IEmptyViewPresenter> presenter);
};


}//namespace erebus
