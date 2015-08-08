#pragma once

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>

#include <memory>

#include <gtk_window.h>
#include <i_window_presenter.h>
#include <window_type.h>
#include <i_gui_manager.h>
#include <gtk_builder_factory.h>
#include <glade_file.h>

namespace erebus {

/**
 * This class is a window factory.
 */
class GTK_WindowFactory {
	GTK_WindowFactory();
  public:
	/**
	 * Destructor.
	 */
	~GTK_WindowFactory();

	/**
	 * Creates a window.
	 *
	 * first template argument: the window to create. must be derived from GTK_Window.
	 * second template argument: the presenter to use. must be derived from IWindowPresenter.
	 *
	 * @param manager the manager to use
	 * @param type the WindoType of the first template argument
	 *
	 * @return the created window
	 */
	template <class T,class F>
	typename std::enable_if<std::is_base_of<GTK_Window, T>::value&&std::is_base_of<IWindowPresenter,F>::value,
	         std::unique_ptr<T>>::type
	static createWindow(IGUIManager& manager,WindowType type) {
		auto presenter=std::make_unique<F>();

		auto builder=GTK_BuilderFactory::getBuilder(GladeFile::getFile(type));

		T* window=nullptr;
		builder->get_widget_derived("window", window);

		presenter->setWindow(*window);
		window->setPresenter(std::move(presenter));
		window->initialize(manager);

		return std::unique_ptr<T>(window);
	}

};


}//namespace erebus
