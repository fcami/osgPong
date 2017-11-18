
#include <osgViewer/Viewer>

#include "GameController.hpp"
#include "Player.hpp"
#include "FindNamedNode.hpp"

#include <iostream>
using namespace std;

GameController::GameController( osg::Group* root ) : _root(root), _direction(0.1f), _distance(0.0f) {}

bool GameController::handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa )
{
	FindNamedNode findPlayer1("player1");
	_root->accept(findPlayer1);
	osg::ref_ptr<Player> player1 = static_cast<Player*> (findPlayer1.getNode());
	player1->update(ea, _root.get());

	FindNamedNode findBall("ball");
	_root->accept(findBall);
	osg::ref_ptr<Player> ball = static_cast<Player*> (findBall.getNode());
	ball->update(ea, _root.get());

	FindNamedNode findPlayer2("player2");
	_root->accept(findPlayer2);
	osg::ref_ptr<Player> player2 = static_cast<Player*> (findPlayer2.getNode());
	player2->update(ea, _root.get());
	
	// WIP: collision detection, 	
	if ( ball->intersectsWith(player1) || ball->intersectsWith(player2) )
	{
		ball->reboundH(ea, _root.get());
	}
}
