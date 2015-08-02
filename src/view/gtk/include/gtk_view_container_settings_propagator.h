#include <view/interfaces/i_view_container_settings_propagator.h>

namespace erebus {
class GTK_ViewContainerSettingsPropagator:public
	IViewContainerSettingsPropagator {
	//GTK_ViewContainer&	container_;
  public:
	/**
	 * Constructor.
	 */
	//GKT_ViewContainerSettingsPropagator(GTK_ViewContainer& container);

	/**
	 * Copy constructor.
	 *
	 * Cant be copied.
	 */
	//GTK_HexView(const GTK_HexView &obj)=delete;

	/**
	 * Move Constructor.
	 */
	//GTK_HexView( GTK_HexView&& );

	/**
	 * Copy assignment operator.
	 *
	 * Cant be copied.
	 */
	//GTK_HexView& operator=(const GTK_HexView&)=delete;

	/**
	 * Move assignment operator.
	 *
	 * Cant be moved assigned.
	 */
	//GTK_HexView& operator=(GTK_HexView&&)=delete;

	/**
	 * Destructor.
	 */
	//~GTK_ViewContainerSettingsPropagator();

	void propagateSetting_always_show_tabs(bool showTabs)override;
};
}//namespace erebus