/*
 *  LightningBolt.cpp
 *  lightning
 *
 *  Created by rockabit on 15-06-10.
 *  Copyright 2010 Random. All rights reserved.
 *
 */

#include "LightningBolt.h"

LightningBolt::LightningBolt() {
	
}

void LightningBolt::setup(float aFromX, float aFromY, float aToX, float aToY, int aNumIterations, float aMaxOffset, float aBranchingProbability) {
	
	fromX = aFromX;
	fromY = aFromY;
	toX = aToX;
	toY = aToY;
	numIterations = aNumIterations;
	
	deviation = aMaxOffset;
	branchingProbability = aBranchingProbability;
	branchAngleMultiplier = 1.3;//1.6;
	branchScale = 0.8;
	branchIntensityFactor = 0.7;//0.5;
}

void LightningBolt::parse() {
	
	// start with one segment
	segments.clear();
	segments.push_back(Segment(ofxVec2f(fromX, fromY), ofxVec2f(toX, toY), 1.0));
	
	currentDeviation = deviation;
	
	// for each iteration
	for (int i = 0; i < numIterations; i++)
	{
		// remove segments from list
		vector<Segment> segmentsCopy = segments;
		segments.clear();
		
		// for each segment
		int max = segmentsCopy.size();
		for (int j = 0; j < max; j++) {
			
			// find midpoint between start and end
			ofxVec2f midPoint = segmentsCopy[j].getMidPoint();
			
			// offset midpoint perpendicularly to segment with a random number with max amplitude
			float offset = ofRandom(0.0, 1.0) < 0.5 ? -currentDeviation : currentDeviation;
			midPoint.x += cos(segmentsCopy[j].getRadians() - 0.25 * PI) * offset;
			midPoint.y += sin(segmentsCopy[j].getRadians() - 0.25 * PI) * offset;
			
			// add two new segments to list
			Segment a(segmentsCopy[j].start, midPoint, segmentsCopy[j].intensity);
			Segment b(midPoint, segmentsCopy[j].end, segmentsCopy[j].intensity);
			segments.push_back(a);
			segments.push_back(b);
			
			if (ofRandom(0.0, 1.0) < branchingProbability)
			{
				// add branch:
				float branchAngle = a.getRadians() * branchAngleMultiplier;
				ofxVec2f branchEnd(midPoint.x + cos(branchAngle) * branchScale * a.getLength(),
								   midPoint.y + sin(branchAngle) * branchScale * a.getLength());
				Segment branch(midPoint, branchEnd, branchIntensityFactor * a.intensity);
				segments.push_back(branch);
			}
		}
		
		// halve max offset amplitude
		currentDeviation *= 0.5;
	}
}

void LightningBolt::draw() {
	
	glBegin(GL_LINES);
	
	int max = segments.size();
	for (int i = 0; i < max; i++)
	{
		float brightness = segments[i].intensity * 255;
		ofSetColor(brightness, brightness, brightness);
		//ofLine(segments[i].start.x, segments[i].start.y, segments[i].end.x, segments[i].end.y);
		glVertex2f(segments[i].start.x, segments[i].start.y);
		glVertex2f(segments[i].end.x, segments[i].end.y);
	}
	
	glEnd();
}