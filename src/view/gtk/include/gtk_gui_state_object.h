#include <view/interfaces/i_gui_state_object.h>

#include <gtkmm.h>

namespace erebus {

/**
 * This class saves variables for the concrete gui.
 * Since the gui managers class definition is purely
 * abstract there is no way the gui manager can save important
 * states which are needed among different methods.
 *
 * All instance variables are public.
 * The reason behind this is because the gui manager
 * is the only one who has a pointer to this class
 * anyways and getters and setters would just
 * complicate the whole process.
 */
class GTK_GUIStateObject: public IGUIStateObject {
  public:
	/**
	 * Saves the pointer to the application.
	 */
	Glib::RefPtr<Gtk::Application> application_;


	/**
	 * Destructor.
	 */
	~GTK_GUIStateObject() {}

	/**
	 * Casts the given IGUIStateObject to the concrete GTK_GUIStateObject.
	 *
	 * @return the concrete GTK_GUIStateObject
	 */
	static GTK_GUIStateObject* getState(IGUIStateObject *obj) {
		return static_cast<GTK_GUIStateObject*>(obj);
	}

};
}//namespace erebus
