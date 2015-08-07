#include <gtk_view_container_factory.h>

#include <gtkmm/adjustment.h>
#include <gtkmm/notebook.h>
#include <glibmm/refptr.h>

#include <memory>

#include <presenter/view_container_presenter.h>
#include <gtk_view_container.h>
#include <gtk_gui_manager.h>

namespace erebus {
class IViewContainerPresenter;
}

namespace erebus {

GTK_ViewContainerFactory::GTK_ViewContainerFactory() {

}

GTK_ViewContainerFactory::~GTK_ViewContainerFactory() {

}

std::unique_ptr<GTK_ViewContainer> GTK_ViewContainerFactory::createViewContainer(
    IGUIManager& manager,
    std::unique_ptr<IViewContainerPresenter> presenter,
    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
    Glib::RefPtr<Gtk::Adjustment> v_adjustment,
    std::unique_ptr<Gtk::Notebook> notebook
) {
	auto viewContainer=std::make_unique<GTK_ViewContainer>(h_adjustment,v_adjustment,
	                   std::move(notebook),manager);
	presenter->setViewContainer(viewContainer.get());
	viewContainer->setPresenter(std::move(presenter));

	return std::move(viewContainer);
}

std::unique_ptr<GTK_ViewContainer> GTK_ViewContainerFactory::createViewContainer(
    IGUIManager& manager,
    std::unique_ptr<IViewContainerPresenter> presenter,
    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
    Glib::RefPtr<Gtk::Adjustment> v_adjustment
) {
	auto notebook=std::unique_ptr<Gtk::Notebook>(nullptr);

	return std::move(createViewContainer(manager,std::move(presenter),h_adjustment,v_adjustment,
	                                     std::move(notebook)));
}

std::unique_ptr<GTK_ViewContainer> GTK_ViewContainerFactory::createViewContainer(
    IGUIManager& manager,
    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
    Glib::RefPtr<Gtk::Adjustment> v_adjustment,
    std::unique_ptr<Gtk::Notebook> notebook
) {
	auto presenter=std::unique_ptr<IViewContainerPresenter>(std::make_unique<ViewContainerPresenter>());

	return std::move(createViewContainer(manager,std::move(presenter),h_adjustment,v_adjustment,std::move(notebook)));
}

std::unique_ptr<GTK_ViewContainer> GTK_ViewContainerFactory::createViewContainer(
    IGUIManager& manager,
    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
    Glib::RefPtr<Gtk::Adjustment> v_adjustment
) {
	auto presenter=std::unique_ptr<IViewContainerPresenter>(std::make_unique<ViewContainerPresenter>());

	return std::move(createViewContainer(manager,std::move(presenter),h_adjustment,v_adjustment));
}

}//namespace erebus
