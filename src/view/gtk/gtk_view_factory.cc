#include <gtk_view_factory.h>

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>

#include <memory>

#include <view/interfaces/i_gui_manager.h>
#include <presenter/interfaces/i_empty_view_presenter.h>

#include <gtk_empty_view.h>
#include <presenter/empty_view_presenter.h>
#include <gtk_builder_factory.h>
#include <glade_file.h>
#include <gtk_logger.h>
#include <view/view_type.h>

INIT_LOCATION;

namespace erebus {

GTK_ViewFactory::GTK_ViewFactory() {

}

GTK_ViewFactory::~GTK_ViewFactory() {

}

GTK_EmptyView* GTK_ViewFactory::createEmptyView(IGUIManager& manager) {
	auto presenter=std::unique_ptr<IEmptyViewPresenter>(std::make_unique<EmptyViewPresenter>());

	return createEmptyView(manager,std::move(presenter));
}

GTK_EmptyView* GTK_ViewFactory::createEmptyView(IGUIManager& manager,
        std::unique_ptr<IEmptyViewPresenter> presenter) {

	//The static is kind of a hack to prevent the builder from getting destroyed
	//and the view with it. For some reason i dont get the ownership of the
	//pointer im requesting... To be honest i think this is a bug in gtkmm.
	static Glib::RefPtr<Gtk::Builder> builder;
	builder=GTK_BuilderFactory::getBuilder(GladeFile::getFile(ViewType::EMPTY_VIEW));

	GTK_EmptyView* view=nullptr;

	builder->get_widget_derived("empty_view", view);
	LOG_ASSERT(gtk_l::get(),view!=nullptr);

	presenter->setView(*view);

	view->setPresenter(std::move(presenter));
	view->setGUIManager(manager);

	return view;
}

}//namespace erebus
