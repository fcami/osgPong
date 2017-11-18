
#include <osg/Geometry>
#include <osg/Geode>

#include "Player.hpp"

#include <iostream>

using namespace std;


Player::Player()
:   _type(INVALID)
{
}

Player::Player( float width, float height )
:   _type(INVALID)
{
    _size.set( width, height );

    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    
    osg::ref_ptr<osg::Drawable> quad = osg::createTexturedQuadGeometry(
        osg::Vec3(-width*0.5f, -height*0.5f, 0.0f),
        osg::Vec3(width, 0.0f, 0.0f), osg::Vec3(0.0f, height, 0.0f) );
    
    geode->addDrawable( quad.get() );
    addChild( geode.get() );
    
    _speedVec = osg::Vec3(0.0f, 0.0f, 0.0f);
}

bool Player::update( const osgGA::GUIEventAdapter& ea, osg::Group* root )
{
    bool accelBall = false;
	osg::Vec3 pos = getMatrix().getTrans();
    float halfW = width() * 0.5f, halfH = height() * 0.5f;
    switch ( _type )
    {
// TODO (maybe) declare update virtual and use polymorphism
    case PLAYER1:
        if ( ea.getEventType()==osgGA::GUIEventAdapter::KEYDOWN )
        {
            switch ( ea.getKey() )
            {
// TODO: 0.2 should not be harcoded, but a property of the game class
            case osgGA::GUIEventAdapter::KEY_Up:
                _speedVec = osg::Vec3(0.0f, 0.2f, 0.0f);
                break;
            case osgGA::GUIEventAdapter::KEY_Down:
                _speedVec = osg::Vec3(0.0f, -0.2f, 0.0f);
                break;
// TODO: implement accelBall
            case osgGA::GUIEventAdapter::KEY_Space:
                accelBall = true;
                break;
            default: break;
            }
        }
        else if ( ea.getEventType()==osgGA::GUIEventAdapter::KEYUP )
            _speedVec = osg::Vec3();
            
		if ( pos.x()+ _speedVec.x() <halfW || pos.x()+ _speedVec.x() >160-halfW ) // TODO: remove hardcoded 160
		{
			return false;
		}

		if ( pos.y()+ _speedVec.y() <halfH || pos.y()+ _speedVec.y() >90-halfH ) // TODO: remove harcoded 90
		{
			return false;
		}

        break;
// TODO: implement Player2 movement
    case PLAYER2:
        break;
    case BALL:
		if ( _speedVec.normalize() == 0 ) // start detection
		{
			_speedVec = osg::Vec3(0.3f, 0.1f, 0.0f); // TODO: randomize start vector
		}
		else
		{	
			if ( pos.y()<halfH || pos.y()>90-halfH ) // TODO: remove harcoded 90
			{
				_speedVec = osg::Vec3( _speedVec[0], -1 * _speedVec[1], _speedVec[2]);
			}
			else if ( pos.x()<halfW || pos.x()>160-halfW ) // TODO: remove hardcoded 160
			// WIP - this should be replaced by score management instead
			{
				_speedVec = osg::Vec3( -1 * _speedVec[0], _speedVec[1], _speedVec[2]);
			}

		}
		break;
	
    default: break;
    }
    
    // only update for new frames
    if ( ea.getEventType() !=osgGA::GUIEventAdapter::FRAME ) 
        return true;
	pos += _speedVec;
	setMatrix( osg::Matrix::translate(pos) );
	return true;

    
}

bool Player::reboundH( const osgGA::GUIEventAdapter& ea, osg::Group* root )
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

bool Player::reboundV( const osgGA::GUIEventAdapter& ea, osg::Group* root )
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




bool Player::intersectsWith( Player* player ) const
{
    osg::Vec3 pos = getMatrix().getTrans();
    osg::Vec3 pos2 = player->getMatrix().getTrans();
    return fabs(pos[0] - pos2[0]) < (width() + player->width()) * 0.5f &&
           fabs(pos[1] - pos2[1]) < (height() + player->height()) * 0.5f;
}
