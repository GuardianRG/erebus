#pragma once

namespace erebus {
class IViewContainerSettingsPropagator {
  public:
	virtual ~IViewContainerSettingsPropagator() {}

	virtual void propagateSetting_always_show_tabs(bool showTabs)=0;
};
}//namespace erebus
