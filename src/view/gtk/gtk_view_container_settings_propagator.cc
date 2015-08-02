#include <gtk_view_container_settings_propagator.h>

#include <gtkmm.h>

#include <gtk_view_container.h>

namespace erebus {

/*GTK_ViewContainerSettingsPropagator::GTK_ViewContainerSettingsPropagator(GTK_ViewContainer& container) {
	container_=container;
}

GTK_ViewContainerSettingsPropagator::
GTK_ViewContainerSettingsPropagator( GTK_ViewContainerSettingsPropagator&& obj):container_(obj.container_) {

}


GTK_ViewContainerSettingsPropagator::~GTK_ViewContainerSettingsPropagator() {

}*/

void GTK_ViewContainerSettingsPropagator::propagateSetting_always_show_tabs(
    bool showTabs) {
	/*auto nb=container_.notebook_.get();
	if(nb->get_n_pages()>=1)
		nb->show_tabs(true);
	else
		nb->show_tabs(showTabs);
	*/
}

}//namespace erebus