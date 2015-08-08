#pragma once

#include <gtkmm/adjustment.h>
#include <gtkmm/notebook.h>
#include <glibmm/refptr.h>

#include <memory>

#include <i_view_container_presenter.h>
#include <gtk_view_container.h>
#include <i_gui_manager.h>

namespace erebus {

/**
 * This class creates View Containers.
 */
class GTK_ViewContainerFactory {
	GTK_ViewContainerFactory();

  public:
	/**
	 * Destructor.
	 */
	~GTK_ViewContainerFactory();

	/**
	 * Creates a view container.
	 *
	 * template argument: the view container presenter to use. must be derived from IViewContainerPresenter.
	 *
	 * @param manager the manager to use
	 * @param h_adjustment the horizontal adjustment
	 * @param v_adjustment the vertical adjustment
	 * @param notebook the notbook to use
	 */
	template <class T>
	typename std::enable_if<std::is_base_of<IViewContainerPresenter, T>::value, std::unique_ptr<GTK_ViewContainer>>::type
	        static  createViewContainer(IGUIManager& manager,
	                                    Glib::RefPtr<Gtk::Adjustment> h_adjustment,
	                                    Glib::RefPtr<Gtk::Adjustment> v_adjustment,
	std::unique_ptr<Gtk::Notebook> notebook=std::unique_ptr<Gtk::Notebook>(nullptr)) {

		auto presenter=std::unique_ptr<IViewContainerPresenter>(std::make_unique<T>());

		auto viewContainer=std::make_unique<GTK_ViewContainer>(h_adjustment,v_adjustment,
		                   std::move(notebook),manager);
		presenter->setViewContainer(viewContainer.get());
		viewContainer->setPresenter(std::move(presenter));

		return std::move(viewContainer);
	}

};

}//namespace erebus
