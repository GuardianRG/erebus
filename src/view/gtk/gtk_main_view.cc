#include <gtkmm.h>

#include <gtk_main_view.h>
#include <string>
#include <assert.h>

#include <interfaces/i_main_view.h>
#include <interfaces/i_presenter.h>

namespace erebus {

GtkMainView::GtkMainView(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder) : Gtk::Window(cobject) {
	refBuilder->get_widget("menu_file_open",menu_file_open_);
	menu_file_open_->signal_activate().connect(sigc::mem_fun(*this,&GtkMainView::on_menu_file_open_click));


	setPreferredSize(800,600);
	maximize();
}

GtkMainView::~GtkMainView() {

}

void GtkMainView::on_menu_file_open_click() {
	assert(presenter_!=nullptr);

	Gtk::FileChooserDialog dialog("Please choose a file",
	                              Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	//Add response buttons the the dialog:
	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("_Open", Gtk::RESPONSE_OK);

	int result = dialog.run();

	//Handle the response:
	if(result==Gtk::RESPONSE_OK) {
		try {
			presenter_->loadFile(dialog.get_filename());
		} catch(...) {
			presenter_->showErrorMessage("Error while loading file!");
		}
	}

}

void GtkMainView::maximize() {
	Gtk::Window::maximize();
}

void GtkMainView::unmaximize() {
	Gtk::Window::unmaximize();
}

void GtkMainView::setPreferredSize(int width,int height) {
	set_default_size(width,height);
}

void GtkMainView::setTitle(std::string title) {
	set_title(title);
}

void GtkMainView::setPresenter(IPresenter* presenter) {
	presenter_=dynamic_cast<IMainViewPresenter*>(presenter);
	assert(presenter_!=nullptr);
}

void GtkMainView::showErrorMessage(std::string errorMsg) {
	Gtk::MessageDialog dialog("Error",false,Gtk::MESSAGE_ERROR,Gtk::BUTTONS_OK,false);
	dialog.set_secondary_text( errorMsg);
	dialog.run();
}

}//namespace erebus