#include <gtk_view_builder.h>

#include <string>

#include <presenter/interfaces/i_empty_view_presenter.h>

#include <presenter/empty_view_presenter.h>
#include <gtk_empty_view.h>

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
	ev->setViewContainer(container);
	ev->createContextMenu();
	return ev;
}
}//namespace erebus