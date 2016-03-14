#pragma once
#ifndef SCORE_H_
#define SCORE_H_

class Score {
	int position;
	int winnerNumSteps;
	int numSteps;
	int dirtCollected;
	int sumDirtInHouse;
	bool isBackInDocking;
public:
	Score();
	virtual ~Score();
	int calcResult();
	// should add operator overloading for <
};

#endif /* SCORE_H_ */

