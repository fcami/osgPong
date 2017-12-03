
#include "Ball.hpp"

#include <iostream>

using namespace std;

bool Ball::update( const osgGA::GUIEventAdapter& ea, osg::Group* root )
{
	bool fall = false;
	osg::Vec3 pos = getMatrix().getTrans();
    float halfW = width() * 0.5f, halfH = height() * 0.5f;

	if ( _speedVec.normalize() == 0 ) // start detection
	{
		_speedVec = osg::Vec3(0.3f, 0.1f, 0.0f); // TODO: randomize start vector
	}
	else
	{	
		if ( _speedVec.y() + pos.y()<halfH || _speedVec.y() + pos.y()>90-halfH ) // TODO: remove harcoded 90
		{
			_speedVec = osg::Vec3( _speedVec[0], -1 * _speedVec[1], _speedVec[2]);
		}
//			else if ( _speedVec.x() + pos.x() < halfW || _speedVec.x() + pos.x()>160-halfW ) // TODO: remove hardcoded 160
		else if ( _speedVec.x() + pos.x()>160-halfW ) // TODO: remove hardcoded 160
		{
			_speedVec = osg::Vec3( -1 * _speedVec[0], _speedVec[1], _speedVec[2]);
//			_speedVec = osg::Vec3(0.0f, 0.0f, 0.0f);
			fall = true;
			return fall;
		}
		else if ( _speedVec.x() + pos.x() < halfW )
		{
			_speedVec = osg::Vec3(0.0f, 0.0f, 0.0f);
			fall = true;
			return fall;
		}
	}
    
    // only update for new frames
    if ( ea.getEventType() !=osgGA::GUIEventAdapter::FRAME ) 
        return false;
	pos += _speedVec;
	setMatrix( osg::Matrix::translate(pos) );
	return fall;
}


bool Ball::reboundH( const osgGA::GUIEventAdapter& ea, osg::Group* root )
{
	_speedVec = osg::Vec3( -1 * _speedVec[0], _speedVec[1], _speedVec[2]);	
    osg::Vec3 pos = getMatrix().getTrans();
    // DUP
    if ( ea.getEventType() !=osgGA::GUIEventAdapter::FRAME ) 
        return false;
	pos += _speedVec;
	setMatrix( osg::Matrix::translate(pos) );
	return true;
}

bool Ball::reboundV( const osgGA::GUIEventAdapter& ea, osg::Group* root )
{
	_speedVec = osg::Vec3( _speedVec[0], -1 * _speedVec[1], _speedVec[2]);	
    osg::Vec3 pos = getMatrix().getTrans();
    // DUP
    if ( ea.getEventType() !=osgGA::GUIEventAdapter::FRAME ) 
        return false;
	pos += _speedVec;
	setMatrix( osg::Matrix::translate(pos) );
	return true;
}

// kludge, for scorekeeping
int Ball::side()
{
	osg::Vec3 pos = getMatrix().getTrans();
	if ( pos.x() < 10 )
		return 1;
	else if ( pos.x() > 150 )
		return 2;
	else
		return pos.x();
}

int heightTarget(Player* player)
{
	// obvious TODO
}
