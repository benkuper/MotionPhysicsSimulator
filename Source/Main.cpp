/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"


class MPSEngine :
	public Engine
{
public:
	MPSEngine() : Engine("MPS File", "mps")
	{
		mainEngine = this;
		PhysicsCC::getInstance();
	}

	~MPSEngine()
	{
		PhysicsCC::deleteInstance();
	}
};
//==============================================================================
class MotionPhysicsSimulatorApplication  : public OrganicApplication
{
public:
    //==============================================================================
    MotionPhysicsSimulatorApplication() :
	OrganicApplication("Motion Physics Simulator")
	{}

    //==============================================================================
	void initialiseInternal(const String& commandLine) override
	{
		engine = new MPSEngine();
		mainComponent = new MainComponent();

	}

};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (MotionPhysicsSimulatorApplication)
