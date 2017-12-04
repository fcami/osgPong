#include "Player.hpp"
#include "PlayerScore.hpp"
//#include "PongScore.hpp"

class RealPlayer : public Player {       

public:
	using Player::Player;
//	RealPlayer ( float width, float height );
	bool update( const osgGA::GUIEventAdapter& ea, osg::Group* root );
	bool setPlayerNumber ( const int number );
	void resetScore();
	void incrScore();
	const int getScore();

protected:
	PlayerScore _score;
//	PongScore _scoreText;
	int _number;
};
