
#include "RealPlayer.hpp"

#include <iostream>

using namespace std;

bool RealPlayer::update( const osgGA::GUIEventAdapter& ea, osg::Group* root )
{
    bool accelBall = false;
	osg::Vec3 pos = getMatrix().getTrans();
    float halfW = width() * 0.5f, halfH = height() * 0.5f;
    switch ( _number )
    {
// TODO 
    case 1:
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
    case 2:
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
