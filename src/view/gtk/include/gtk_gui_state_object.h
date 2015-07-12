#include <view/interfaces/i_gui_state_object.h>

#include <gtkmm.h>

namespace erebus {
class GTK_GUIStateObject: public IGUIStateObject {
  public:
	~GTK_GUIStateObject() {}

	Glib::RefPtr<Gtk::Application> application_;

	static GTK_GUIStateObject* getState(IGUIStateObject *obj) {
		return static_cast<GTK_GUIStateObject*>(obj);
	}

};
}