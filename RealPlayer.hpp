#include "Player.hpp"
#include "PongScore.hpp"

class RealPlayer : public Player {       

public:
	using Player::Player;
	bool update( const osgGA::GUIEventAdapter& ea, osg::Group* root );

	void setPlayerNumber ( const int number ) { _number = number; }
	void resetScore();
	void incrScore();
	const int getScore();

protected:
	PongScore _score;
	int _number;
};
