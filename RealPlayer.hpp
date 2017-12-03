#include "Player.hpp"
#include "PlayerScore.hpp"

//#include <osgText/Font>
//#include <osgText/Text>

class RealPlayer : public Player {       

public:
	using Player::Player;
	bool update( const osgGA::GUIEventAdapter& ea, osg::Group* root );
	void setPlayerNumber ( const int number ) { _number = number; }
	void resetScore();
	void incrScore();
	const int getScore();

protected:
	PlayerScore _score;
//	osg::ref_ptr<osgText::Text> scoreText;
	int _number;
};
