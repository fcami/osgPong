
#include "Player"
#include "PongGame"

#include <iostream>
using namespace std;

osg::ref_ptr<osg::Node> PongGame::createGameGroup()
{
	osg::ref_ptr<osg::Group> gameGroup = new osg::Group;
	gameGroup->setName( "gameGroup" );
	
	// TODO: remove duplicated code
	
    osg::ref_ptr<Player> player1 = new Player(1.0f, 5.0f);
    player1->setMatrix( osg::Matrix::translate(2.0f, 45.0f, 0.0f) );
    player1->setPlayerType( Player::PLAYER1 );
//	player1->addDescription("player1");
	player1->setName( "player1" );

    osg::ref_ptr<Player> player2 = new Player(1.0f, 5.0f);
    player2->setMatrix( osg::Matrix::translate(158.0f, 45.0f, 0.0f) );
    player2->setPlayerType( Player::PLAYER2 );
//	player2->addDescription("player2");
	player2->setName( "player2" );

    osg::ref_ptr<Player> ball = new Player(1.0f, 1.0f);
	ball->setMatrix( osg::Matrix::translate(80.0f, 45.0f, 0.0f) );
	ball->setPlayerType( Player::BALL );
//	ball->addDescription("ball");
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

	return scoreGroup.get();
}

osg::ref_ptr<osg::Node> PongGame::createGameScene()
{
	osg::ref_ptr<osg::Switch> gameSwitch = new osg::Switch;
	gameSwitch->setName("gameSwitch");

    gameSwitch->addChild( createGameGroup(), true );
    gameSwitch->addChild( createScoreGroup(), false );
    gameSwitch->addChild( createTitleGroup(), false );
	
	return gameSwitch.get();
	
}

