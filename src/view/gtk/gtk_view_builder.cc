#include <gtk_view_builder.h>

#include <string>

#include <presenter/interfaces/i_empty_view_presenter.h>
#include <presenter/interfaces/i_hex_view_presenter.h>

#include <presenter/empty_view_presenter.h>
#include <presenter/hex_view_presenter.h>
#include <gtk_empty_view.h>
#include <gtk_hex_view.h>

namespace erebus {
GTK_ViewBuilder::GTK_ViewBuilder() {

}

GTK_EmptyView* GTK_ViewBuilder::buildEmptyView(GTK_ViewContainer* container,std::string title) {
	IEmptyViewPresenter* p=new EmptyViewPresenter;
	return buildEmptyView(container,p,title);
}

GTK_EmptyView* GTK_ViewBuilder::buildEmptyView(GTK_ViewContainer* container,IEmptyViewPresenter* presenter, std::string title) {
	GTK_EmptyView* ev=new GTK_EmptyView(container->getHAdjustment(),container->getVAdjustment());
	presenter->setView(ev);
	ev->setPresenter(presenter);
	ev->setTitle(title);
	ev->setParent(container);
	ev->createContextMenu();
	return ev;
}

GTK_HexView* GTK_ViewBuilder::buildHexView(GTK_ViewContainer* container,std::string title) {
	IHexViewPresenter* p=new HexViewPresenter;
	return buildHexView(container,p,title);
}

GTK_HexView* GTK_ViewBuilder::buildHexView(GTK_ViewContainer* container,IHexViewPresenter* presenter, std::string title) {
	GTK_HexView* ev=new GTK_HexView(container->getHAdjustment(),container->getVAdjustment());
	presenter->setView(ev);
	ev->setPresenter(presenter);
	ev->setTitle(title);
	ev->setParent(container);
	ev->createContextMenu();
	return ev;
}

}//namespace erebus