#include <gtk_window_factory.h>

#include <presenter/interfaces/i_main_window_presenter.h>

#include <memory>
#include <gtk_main_window.h>
#include <presenter/main_window_presenter.h>
#include <glade_files.h>
#include <gtk_logger.h>
#include <gtk_builder_factory.h>

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
	return createMainWindow(manager,std::move(presenter));
}

std::unique_ptr<GTK_MainWindow> GTK_WindowFactory::createMainWindow(IGUIManager& manager,
        std::unique_ptr<IMainWindowPresenter> presenter) {
	auto builder=GTK_BuilderFactory::getBuilder(Windows::MAIN_WINDOW);

	GTK_MainWindow* window=nullptr;
	builder->get_widget_derived("main_window", window);
	LOG_ASSERT(gtk_l::get(),window!=nullptr);

	presenter->setWindow(window);

	window->setPresenter(std::move(presenter));
	window->initialize(manager);

	return std::unique_ptr<GTK_MainWindow>(window);
}

}//namespace erebus
