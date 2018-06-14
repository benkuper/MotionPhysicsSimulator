/*
  ==============================================================================

    Vizualizer.h
    Created: 14 Jun 2018 8:15:21pm
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#include "PhysicsCC.h"

class CurveViewer :
	public Component,
	public ContainerAsyncListener,
	public Script::AsyncListener
{
public:
	CurveViewer(PhysicsCC * pcc);
	~CurveViewer();

	PhysicsCC * pcc;

	Path simPath;
	Path speedPath;
	Path accPath;
	Path jerkPath;

	
	void paint(Graphics &g) override;

	void resized() override;
	void generateSim();

	void mouseDown(const MouseEvent &e) override;

	void newMessage(const ContainerAsyncEvent &e) override;
	void newMessage(const Script::ScriptEvent &e) override;
}; 

class Vizualizer :
	public ShapeShifterContentComponent
{
public:
	Vizualizer(const String &name);
	~Vizualizer();

	AutomationUI simCurveUI;

	CurveViewer cv;

	void mouseDown(const MouseEvent &e) override;
	void resized() override;

	static Vizualizer * create(const String &name) { return new Vizualizer(name); }
};

