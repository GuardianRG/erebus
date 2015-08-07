#include <gtk_window_factory.h>

#include <memory>


#include <presenter/interfaces/i_main_window_presenter.h>
#include <presenter/interfaces/i_view_window_presenter.h>

#include <gtk_main_window.h>
#include <presenter/main_window_presenter.h>
#include <presenter/view_window_presenter.h>
#include <glade_file.h>
#include <gtk_logger.h>
#include <gtk_builder_factory.h>
#include <view/window_type.h>
#include <gtk_view_window.h>

INIT_LOCATION;

namespace erebus {
class IGUIManager;
}

namespace erebus {
GTK_WindowFactory::GTK_WindowFactory() {
}

GTK_WindowFactory::~GTK_WindowFactory() {

}

std::unique_ptr<GTK_MainWindow> GTK_WindowFactory::createMainWindow(IGUIManager& manager) {
	auto presenter=std::unique_ptr<IMainWindowPresenter>(std::make_unique<MainWindowPresenter>());
	return std::move(createMainWindow(manager,std::move(presenter)));
}

std::unique_ptr<GTK_MainWindow> GTK_WindowFactory::createMainWindow(IGUIManager& manager,
        std::unique_ptr<IMainWindowPresenter> presenter) {
	auto builder=GTK_BuilderFactory::getBuilder(GladeFile::getFile(WindowType::MAIN_WINDOW));

	GTK_MainWindow* window=nullptr;
	builder->get_widget_derived("main_window", window);
	LOG_ASSERT(gtk_l::get(),window!=nullptr);

	presenter->setWindow(*window);

	window->setPresenter(std::move(presenter));
	window->initialize(manager);

	return std::unique_ptr<GTK_MainWindow>(window);
}

std::unique_ptr<GTK_ViewWindow> GTK_WindowFactory::createViewWindow(IGUIManager& manager) {
	auto presenter=std::unique_ptr<IViewWindowPresenter>(std::make_unique<ViewWindowPresenter>());
	return std::move(createViewWindow(manager,std::move(presenter)));
}

std::unique_ptr<GTK_ViewWindow> GTK_WindowFactory::createViewWindow(IGUIManager& manager,
        std::unique_ptr<IViewWindowPresenter> presenter) {
	auto builder=GTK_BuilderFactory::getBuilder(GladeFile::getFile(WindowType::VIEW_WINDOW));

	GTK_ViewWindow* window=nullptr;
	builder->get_widget_derived("view_window", window);
	LOG_ASSERT(gtk_l::get(),window!=nullptr);

	presenter->setWindow(*window);

	window->setPresenter(std::move(presenter));
	window->initialize(manager);

	return std::unique_ptr<GTK_ViewWindow>(window);
}

}//namespace erebus
