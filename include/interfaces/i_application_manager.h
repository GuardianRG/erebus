#pragma once

namespace erebus {

/**
 * Manages the gui of an applictaion.
 */
class IApplicationManager {
  public:
	/**
	 * Destructor.
	 */
	virtual ~IApplicationManager() {}

	/**
	 * Starts the application.
	 */
	virtual void run()=0;
};
}