/*
  ==============================================================================

    Vizualizer.cpp
    Created: 14 Jun 2018 8:15:21pm
    Author:  Ben

  ==============================================================================
*/

#include "Vizualizer.h"



CurveViewer::CurveViewer(PhysicsCC * pcc) :
	pcc(pcc)
{
	pcc->addAsyncContainerListener(this);
	pcc->script.addAsyncScriptListener(this);
}

CurveViewer::~CurveViewer()
{
	pcc->removeAsyncContainerListener(this);
	pcc->script.removeAsyncScriptListener(this);
}

void CurveViewer::paint(Graphics & g)
{
	g.fillAll(BG_COLOR.darker(.2f));

	float maxTime = pcc->simTime->floatValue(); //simulation sur 5seconds
	g.setColour(BG_COLOR.brighter(.2f));

	for (int i = 1; i < maxTime; i++)
	{
		float tx = i * getWidth() / maxTime;
		g.drawLine(tx, 0, tx, getHeight());
	}

	for (int i = ceil(pcc->minVal); i < floor(pcc->maxVal) && i < pcc->minVal + 10; i++)
	{
		float ty = jmap<float>(i, pcc->minVal, pcc->maxVal, getHeight(), 0);
		g.drawLine(0, ty, getWidth(), ty);
	}


	g.setColour(GREEN_COLOR.withAlpha(.7f));
	float j0 = jmap<float>(0, pcc->minJerk, pcc->maxJerk, getHeight(), 0);
	g.drawLine(0, j0, getWidth(), j0);
	g.strokePath(jerkPath, PathStrokeType(1));

	g.setColour(BLUE_COLOR.withAlpha(.7f));
	float a0 = jmap<float>(0, pcc->minAcc, pcc->maxAcc, getHeight(), 0);
	g.drawLine(0, a0, getWidth(), a0);
	g.strokePath(accPath, PathStrokeType(1));

	g.setColour(RED_COLOR.withAlpha(.7f));
	float s0 = jmap<float>(0, pcc->minSpeed, pcc->maxSpeed, getHeight(), 0);
	g.drawLine(0, s0, getWidth(), s0);
	g.strokePath(speedPath, PathStrokeType(1));

	g.setColour(Colours::white.withAlpha(.8f));
	g.strokePath(simPath, PathStrokeType(2));
}

void CurveViewer::resized()
{
	generateSim();
}

void CurveViewer::generateSim()
{
	pcc->generateSim();

	simPath.clear();
	simPath.startNewSubPath(0, getHeight());

	speedPath.clear();
	speedPath.startNewSubPath(0, getHeight());

	accPath.clear();
	accPath.startNewSubPath(0, getHeight());

	jerkPath.clear();
	jerkPath.startNewSubPath(0, getHeight());


	int numValues = pcc->positions.size();
	for (int i = 0; i < numValues; i++)
	{
		float rel = i * 1.0f / numValues;

		float tPos = jmap<float>(pcc->positions[i], pcc->minVal, pcc->maxVal, 0, 1);
		float sPos = jmap<float>(pcc->speeds[i], pcc->minSpeed, pcc->maxSpeed, 0, 1);
		float aPos = jmap<float>(pcc->accelerations[i], pcc->minAcc, pcc->maxAcc, 0, 1);
		float jPos = jmap<float>(pcc->jerks[i], pcc->minJerk, pcc->maxJerk, 0, 1);

		float tx = 0 + rel * getWidth();
		float tpy = getHeight() - tPos * getHeight();
		float tsy = getHeight() - sPos * getHeight();
		float tay = getHeight() - aPos * getHeight();
		float tjy = getHeight() - jPos * getHeight();

		if (!isnan(tPos) && !isinf(tPos))
		{
			if (i == 0) simPath.startNewSubPath(tx, tpy);
			else simPath.lineTo(tx, tpy);
		}

		if (!isnan(sPos) && !isinf(sPos))
		{
			if (i == 0) speedPath.startNewSubPath(tx, tsy);
			else speedPath.lineTo(tx, tsy);
		}

		if (!isnan(aPos) && !isinf(aPos))
		{
			if (i == 0) accPath.startNewSubPath(tx, tay);
			else accPath.lineTo(tx, tay);
		}

		if (!isnan(jPos) && !isinf(jPos))
		{
			if (i == 0) jerkPath.startNewSubPath(tx, tjy);
			else jerkPath.lineTo(tx, tjy);
		}
	}


	repaint();

}

void CurveViewer::mouseDown(const MouseEvent & e)
{
	pcc->selectThis();
}

void CurveViewer::newMessage(const ContainerAsyncEvent & e)
{
	if (e.type == ContainerAsyncEvent::ControllableFeedbackUpdate)
	{
		generateSim();
	}
}

void CurveViewer::newMessage(const Script::ScriptEvent & e)
{
	generateSim();
}


Vizualizer::Vizualizer(const String &name) :
	ShapeShifterContentComponent(name),
	cv(PhysicsCC::getInstance()),
	simCurveUI(&PhysicsCC::getInstance()->simCurve)
{
	addAndMakeVisible(&cv);
	addAndMakeVisible(&simCurveUI);
	setInterceptsMouseClicks(true, true);

	resized();
}

Vizualizer::~Vizualizer()
{
}

void Vizualizer::mouseDown(const MouseEvent & e)
{
	PhysicsCC::getInstance()->selectThis();
	ShapeShifterContentComponent::mouseDown(e);
}

void Vizualizer::resized()
{
	Rectangle<int> r = getLocalBounds();
	r.reduce(8,8);
	simCurveUI.setBounds(r.removeFromTop(r.getHeight() / 3));
	
	r.removeFromTop(2);
	cv.setBounds(r);
}
