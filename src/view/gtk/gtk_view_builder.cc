#include <gtk_view_builder.h>

#include <string>
#include <memory>

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
	auto p=std::unique_ptr<IEmptyViewPresenter>(new EmptyViewPresenter);
	return buildEmptyView(container,std::move(p),title);
}

GTK_EmptyView* GTK_ViewBuilder::buildEmptyView(GTK_ViewContainer* container,std::unique_ptr<IEmptyViewPresenter> presenter, std::string title) {
	GTK_EmptyView* ev=new GTK_EmptyView(container->getHAdjustment(),container->getVAdjustment());
	presenter->setView(ev);
	ev->setPresenter(std::move(presenter));
	ev->setTitle(title);
	ev->setParent(container);
	ev->createContextMenu();
	return ev;
}

GTK_HexView* GTK_ViewBuilder::buildHexView(GTK_ViewContainer* container,std::string title) {
	auto p=std::unique_ptr<IHexViewPresenter>(new HexViewPresenter);
	return buildHexView(container,std::move(p),title);
}

GTK_HexView* GTK_ViewBuilder::buildHexView(GTK_ViewContainer* container,std::unique_ptr<IHexViewPresenter> presenter, std::string title) {
	GTK_HexView* ev=new GTK_HexView(container->getHAdjustment(),container->getVAdjustment());
	presenter->setView(ev);
	ev->setPresenter(std::move(presenter));
	ev->setTitle(title);
	ev->setParent(container);
	ev->createContextMenu();
	return ev;
}

}//namespace erebus
