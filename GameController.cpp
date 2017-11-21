
#include <osgViewer/Viewer>

#include "GameController.hpp"
#include "FindNamedNode.hpp"

#include "Ball.hpp"
#include "RealPlayer.hpp"

#include <iostream>
using namespace std;

GameController::GameController( osg::Group* root ) : _root(root), _direction(0.1f), _distance(0.0f) {}

bool GameController::handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa )
{
	// candidate for threading
	FindNamedNode findPlayer1("player1");
	_root->accept(findPlayer1);
	osg::ref_ptr<RealPlayer> player1 = static_cast<RealPlayer*> (findPlayer1.getNode());
	player1->update(ea, _root.get());

	FindNamedNode findBall("ball");
	_root->accept(findBall);
	osg::ref_ptr<Ball> ball = static_cast<Ball*> (findBall.getNode());
	bool fall = ball->update(ea, _root.get());

	FindNamedNode findPlayer2("player2");
	_root->accept(findPlayer2);
	osg::ref_ptr<RealPlayer> player2 = static_cast<RealPlayer*> (findPlayer2.getNode());
	player2->update(ea, _root.get());
	
	// end threads
	
	// WIP: collision detection, 	
	if ( ball->intersectsWith(player1) || ball->intersectsWith(player2) )
	{
		ball->reboundH(ea, _root.get());
	}
	
	if ( fall )
	{
		int loser = ball->side();
		cout << "loser is " << loser << endl;
		if ( loser == 1)
		{
			ball->setMatrix( osg::Matrix::translate(80.0f, 45.0f, 0.0f) );
			player2->incrScore();
		}
		else if ( loser == 2)
		{
			// ball->setMatrix( osg::Matrix::translate(80.0f, 45.0f, 0.0f) );
			player1->incrScore();
		}
		cout << "score: player1: " << player1->getScore() << " player2: " << player2->getScore() << endl;
	}
}
