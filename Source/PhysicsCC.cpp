/*
  ==============================================================================

    PhysicsCC.cpp
    Created: 14 Jun 2018 10:28:02pm
    Author:  Ben

  ==============================================================================
*/

#include "PhysicsCC.h"

juce_ImplementSingleton(PhysicsCC)

PhysicsCC::PhysicsCC() :
	ControllableContainer("Physics CC"),
	minVal(0), maxVal(1), minSpeed(0), maxSpeed(1), minAcc(0), maxAcc(1), minJerk(0), maxJerk(1)
{
	simTime = addFloatParameter("Simulation Time", "Time of the simulated curve", 5, 1, 20);
	simFrame = addFloatParameter("Frame time", "Time between each simulated frame", 0.03f, 0.005f, .5f);

	simCurve.hideInEditor = true;
	simCurve.addItem(0, 0);
	simCurve.addItem(.2f, .5f);
	simCurve.addItem(.6f, .5f);
	simCurve.addItem(.75f, 0);
	simCurve.items[0]->setEasing(Easing::HOLD);

	addChildControllableContainer(&script);

	addChildControllableContainer(&simCurve);
}

PhysicsCC::~PhysicsCC()
{
}

void PhysicsCC::generateSim()
{
	minVal = 0;
	maxVal = 1;
	minSpeed = 0;
	maxSpeed = .001f;
	minAcc = 0;
	maxAcc = .001f;
	minJerk = 0;
	maxJerk = .001f;

	positions.clear();
	speeds.clear();
	accelerations.clear();
	jerks.clear();

	float lastTime = 0;
	float lastPos = 0;
	float lastSpeed = 0;
	float lastAcc = 0;

	script.callFunction("reset",Array<var>());


	for (float t = 0; t < simTime->floatValue() + simFrame->floatValue(); t += simFrame->floatValue())
	{
		t = jmin(t, simTime->floatValue());
		float  deltaTime = t - lastTime;

		float targetPos = simCurve.getValueForPosition(t / simTime->floatValue());

		Array<var> params;
		params.add(t);
		params.add(deltaTime);
		params.add(targetPos);
		params.add(lastPos);
		params.add(lastSpeed);
		params.add(lastAcc);

		Result result = Result::ok();
		var resultData = script.callFunction(processFrameId, params, &result);
		if (result == Result::ok() && resultData.isArray() && resultData.size() >= 4)
		{
			float pos = resultData[0];
			float speed = resultData[1];
			float accel = resultData[2];
			float jerk = resultData[3];


			positions.add(pos);
			speeds.add(speed);
			accelerations.add(accel);
			jerks.add(jerk);

			minVal = jmin(minVal, pos);
			maxVal = jmax(maxVal, pos);
			minSpeed = jmin(minSpeed, speed);
			maxSpeed = jmax(maxSpeed, speed);
			minAcc = jmin(minAcc, accel);
			maxAcc = jmax(maxAcc, accel);
			minJerk = jmin(minJerk, jerk);
			maxJerk = jmax(maxJerk, jerk);


			lastPos = pos;
			lastSpeed = speed;
			lastAcc = accel;

		} else
		{
			break;
		}
	}

	//float tw = (float)getWidth();
	//float maxTime = pcc->simTime->floatValue(); //simulation sur 5seconds
	//float lastTime = 0;

	//float lastPos = 0;
	//float lastSpeed = 0;

	//const int steps = 3;
	//for (int i = 0; i < tw; i += steps)
	//{
	//	float rel = (i * 1.0f / tw);
	//	float targetPos = pcc->testMotion.getValueForPosition(rel);
	//	float curTime = rel * maxTime;
	//	float deltaTime = curTime - lastTime;


	//	float p = targetPos;
	//	float s = (targetPos - lastPos)*deltaTime;
	//	float a = (s - lastSpeed)*deltaTime;

	//	lastSpeed = s;
	//	lastPos = p;

	//	positions.add(p);
	//	speeds.add(s);
	//	accelerations.add(a);
	//	jerks.add(0);


	//	minVal = jmin(minVal, p);
	//	maxVal = jmax(maxVal, p);
	//	minSpeed = jmin(minSpeed, s);
	//	maxSpeed = jmax(maxSpeed, s);
	//	minAcc = jmin(minAcc, a);
	//	maxAcc = jmax(maxAcc, a);

	//	lastTime = curTime;
	//}
}