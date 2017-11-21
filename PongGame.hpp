
#include <osgViewer/Viewer>
#include <osg/Node>
#include <osgText/Font>
#include <osgText/Text>

// TODO: compose with GameController
class PongGame
{
public:
	PongGame() {}; //TODO: write a better constructor

	osg::ref_ptr<osg::Node> createGameScene();
	
private:
	osg::ref_ptr<osg::Node> createGameGroup();
	osg::ref_ptr<osg::Node> createTitleGroup();
	osg::ref_ptr<osg::Node> createScoreGroup();

protected:
    osg::observer_ptr<osg::Group> _root;
    float _direction;
    float _distance;
};
