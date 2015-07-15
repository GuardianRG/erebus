#include <view/gui_manager.h>
#include <model.h>

int main(int argc, char *argv[]) {

	erebus::Model* model=new erebus::Model;
	erebus::GUIManager* m=erebus::GUIManager::create(model,argc,argv);
	m->runGUI();

	delete model;

	return 0;
}