/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
}

MainComponent::~MainComponent()
{
	
}

void MainComponent::init()
{
	ShapeShifterFactory::getInstance()->defs.add(new ShapeShifterDefinition("Vizualizer", &Vizualizer::create));
	ShapeShifterManager::getInstance()->setLayoutInformations("mpsLayout", "MPS/layouts");
	ShapeShifterManager::getInstance()->setDefaultFileData(BinaryData::default_mpsLayout);
	ShapeShifterManager::getInstance()->loadDefaultLayoutFile();

	OrganicMainContentComponent::init();

	PhysicsCC::getInstance()->selectThis();
}
