/*
  ==============================================================================

    PhysicsCC.h
    Created: 14 Jun 2018 10:28:02pm
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"



class PhysicsCC :
	public ControllableContainer
{
public:

	juce_DeclareSingleton(PhysicsCC, true)

	PhysicsCC();
	~PhysicsCC();

	FloatParameter * simTime;
	FloatParameter * simFrame;

	Automation simCurve;

	const Identifier processFrameId = "processFrame";

	Script script;



	float minVal;
	float maxVal;
	float minSpeed;
	float maxSpeed;
	float minAcc;
	float maxAcc;
	float minJerk;
	float maxJerk;

	Array<float> positions;
	Array<float> speeds;
	Array<float> accelerations;
	Array<float> jerks;


	void generateSim();
};