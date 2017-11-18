#include <osg/Geometry>
#include <osg/NodeVisitor>
#include <osg/Node>
#include <osgViewer/Viewer>

#include "FindNamedNode.hpp"
#include "Camera.hpp"
#include "GameController.hpp"
#include "PongGame.hpp"

#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
	PongGame* game = new PongGame();
    osg::ref_ptr<HUDCamera> hudCamera = new HUDCamera(0, 160, 0, 90);

    hudCamera->addChild( game->createGameScene() );
    
    osgViewer::Viewer viewer;
    viewer.getCamera()->setClearColor( osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f) );
    viewer.addEventHandler( new GameController( hudCamera.get() ) );
    viewer.setSceneData( hudCamera.get() );

    return viewer.run();
}
