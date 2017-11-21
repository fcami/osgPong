#include "Player.hpp"

#include <osg/MatrixTransform>
#include <osgGA/GUIEventAdapter>

#define RAND(min, max) ((min) + (float)rand()/(RAND_MAX) * ((max)-(min)))

class Ball : public Player {

public:
	using Player::Player;

	bool update( const osgGA::GUIEventAdapter& ea, osg::Group* root );

    bool reboundH( const osgGA::GUIEventAdapter& ea, osg::Group* root );
    bool reboundV( const osgGA::GUIEventAdapter& ea, osg::Group* root );
    int heightTarget(Player* player);

	int side();

};

