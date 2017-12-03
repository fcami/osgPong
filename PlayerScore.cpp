
#include "PlayerScore.hpp"

#include <iostream>

using namespace std;

PlayerScore::PlayerScore()
:   _score(0)
{
}

const int PlayerScore::getScore()
{
	return _score;
}

void PlayerScore::incrScore()
{
	_score++;
}

void PlayerScore::resetScore()
{
	_score = 0;
}

