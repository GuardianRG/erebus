#pragma once



namespace erebus {
class IPresenter;

class IView {
public:
	virtual ~IView() {}
	
	virtual void setPresenter(IPresenter* presenter)=0;
};

}