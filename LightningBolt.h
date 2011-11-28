/*
 *  LightningBolt.h
 *  lightning
 *
 *  Created by rockabit on 15-06-10.
 *  Copyright 2010 Random. All rights reserved.
 *
 */

#ifndef LIGHTNING_BOLT_H
#define LIGHTNING_BOLT_H

#include "ofMain.h"
#include "Segment.h"
#include "ofxVectorMath.h"

/*
 *	A simple lightning renderer. Specify a start and end location to create one.
 *	
 *	Usage:
 *	bolt.setup(ofxVec2f(0, 0), ofxVec2f(mouseX, mouseY), 6, ofRandom(80, 100), 0.04);
 *	bolt.parse();
 *	bolt.draw();
 */
class LightningBolt {

public:
	
	vector<Segment> segments;
	LightningBolt();
	void setup(float fromX, float fromY, float toX, float toY, int aNumIterations=6, float aMaxOffset=120.0, float aBranchingProbability=.4);
	void parse();
	void draw();
	
protected:
	float fromX;
	float fromY;
	float toX;
	float toY;
	int numIterations;
	float deviation;
	float currentDeviation;
	float branchingProbability;
	float branchAngleMultiplier;
	float branchScale;
	float branchIntensityFactor;
	
};

#endif