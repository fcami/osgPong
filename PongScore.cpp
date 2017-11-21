
#include "PongScore.hpp"

#include <iostream>

using namespace std;

PongScore::PongScore()
:   _score(0)
{
}

const int PongScore::getScore()
{
	return _score;
}

void PongScore::incrScore()
{
	_score++;
}

void PongScore::resetScore()
{
	_score = 0;
}

