#pragma once

#include <gtkmm/builder.h>
#include <glibmm/refptr.h>

#include <memory>

#include <i_gui_manager.h>
#include <gtk_builder_factory.h>
#include <glade_file.h>
#include <gtk_view.h>
#include <i_view_presenter.h>
#include <view_type.h>


namespace erebus {

/**
 * This class creates vies.
 */
class GTK_ViewFactory {
	GTK_ViewFactory();

  public:
	/**
	 * Destructor.
	 */
	~GTK_ViewFactory();

	/**
	 * Creates a view.
	 *
	 * The ownership behavior is a little bit weird because of gtkmm. As long you do not
	 * have added the view to a container the ownership remains to this function (it is saved
	 * within a static variable inside this function). Therefore you have to add the created view to
	 * a container before calling this method again. Otherwise the view will be deleted and the pointer
	 * points to deleted memory.
	 *
	 * First template argument: The view you want to create. Must be derived From GTK_View.
	 * Second template argument: The presenter you want to use. Must be derived from IViewPresenter.
	 *
	 * @param manager the manager to use
	 * @param type the view type of the first template argument
	 *
	 * @return the created view
	 */
	template <class T,class F>
	typename std::enable_if<std::is_base_of<GTK_View, T>::value&&std::is_base_of<IViewPresenter,F>::value,
	         T*>::type
	static  createView(IGUIManager& manager,ViewType type) {
		auto presenter=std::make_unique<F>();

		//The static is kind of a hack to prevent the builder from getting destroyed
		//and the view with it. For some reason i dont get the ownership of the
		//pointer im requesting... To be honest i think this is a bug in gtkmm.
		static Glib::RefPtr<Gtk::Builder> builder;
		builder=GTK_BuilderFactory::getBuilder(GladeFile::getFile(type));

		T* view=nullptr;
		builder->get_widget_derived("view", view);

		presenter->setView(*view);
		view->setPresenter(std::move(presenter));
		view->setGUIManager(manager);

		return view;
	}

};

}//namespace erebus
