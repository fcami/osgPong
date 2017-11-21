
#include "Player.hpp"
#include "RealPlayer.hpp"
#include "Ball.hpp"

#include "PongGame.hpp"

#include <iostream>
using namespace std;

osg::ref_ptr<osg::Node> PongGame::createGameGroup()
{
	osg::ref_ptr<osg::Group> gameGroup = new osg::Group;
	gameGroup->setName( "gameGroup" );
	
	// TODO: remove duplicated code
	
    osg::ref_ptr<RealPlayer> player1 = new RealPlayer(1.0f, 5.0f);
    player1->setMatrix( osg::Matrix::translate(2.0f, 45.0f, 0.0f) );
    player1->setPlayerNumber( 1 );
	player1->setName( "player1" );

    osg::ref_ptr<RealPlayer> player2 = new RealPlayer(1.0f, 5.0f);
    player2->setMatrix( osg::Matrix::translate(158.0f, 45.0f, 0.0f) );
    player2->setPlayerNumber( 2 );
	player2->setName( "player2" );

    osg::ref_ptr<Ball> ball = new Ball(1.0f, 1.0f);
	ball->setMatrix( osg::Matrix::translate(80.0f, 45.0f, 0.0f) );
	ball->setName( "ball" );

    gameGroup->addChild( player1.get() );
    gameGroup->addChild( player2.get() );
	gameGroup->addChild( ball.get() );    

	return gameGroup.get();
}

osg::ref_ptr<osg::Node> PongGame::createTitleGroup()
{
	osg::ref_ptr<osg::Group> titleGroup = new osg::Group;

	return titleGroup.get();
}

osg::ref_ptr<osg::Node> PongGame::createScoreGroup()
{
	osg::ref_ptr<osg::Group> scoreGroup = new osg::Group;
    osg::ref_ptr<osgText::Text> score = new osgText::Text;
    score->setFont("fonts/times.ttf");
    score->setAxisAlignment(osgText::Text::XY_PLANE);
    score->setText("0   0");
	score->setName("score");
	score->setPosition(osg::Vec3(25.0f,50.0f,0.0f)); // TODO: un-hardcode placement
	scoreGroup->addChild( score.get() );    
	return scoreGroup.get();
}

osg::ref_ptr<osg::Node> PongGame::createGameScene()
{
	osg::ref_ptr<osg::Switch> gameSwitch = new osg::Switch;
	gameSwitch->setName("gameSwitch");

    gameSwitch->addChild( createGameGroup(), true );
    gameSwitch->addChild( createScoreGroup(), true );
    gameSwitch->addChild( createTitleGroup(), false );
	
	return gameSwitch.get();
	
}

