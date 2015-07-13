#pragma once

#include <string>

#include <presenter/interfaces/i_empty_view_presenter.h>

#include <gtk_empty_view.h>

namespace erebus {

class GTK_ViewContainer;

/**
 * This class build the different views.
 */
class GTK_ViewBuilder {
	GTK_ViewBuilder();
  public:
	/**
	 * Destructor.
	 */
	~GTK_ViewBuilder() {}

	/**
	 * Builds an empty view.
	 *
	 * @param container the container the view will be in.
	 * @param title the title of the view.
	 */
	static GTK_EmptyView* buildEmptyView(GTK_ViewContainer* container,std::string title);

	/**
	 * Builds an empty view.
	 *
	 * @param container the container the view will be in.
	 * @param presenter the presneter the view shall use
	 * @param title the title of the view.
	 */
	static GTK_EmptyView* buildEmptyView(GTK_ViewContainer* container,IEmptyViewPresenter* presenter, std::string title);

};

}//namespace erebus