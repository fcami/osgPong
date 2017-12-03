
#include "PongScore.hpp"

PongScore::PongScore()
:   _side(INVALID)
{
	setFont("fonts/times.ttf");
	setAxisAlignment(osgText::Text::XY_PLANE);
	setText("0");
	setDrawMode(osgText::Text::TEXT | osgText::Text::ALIGNMENT | osgText::Text::BOUNDINGBOX);
	setAlignment(osgText::Text::CENTER_BOTTOM);	

}


bool PongScore::setScoreSide( ScoreSide side )
{
	_side = side;
	if ( _side == LEFT )
	{
		setName("scorep1");
		setPosition(osg::Vec3(25.0f,50.0f,0.0f));
		return true;	
	} 
	else if ( _side == RIGHT )
	{
		setName("scorep2");
		setPosition(osg::Vec3(130.0f,50.0f,0.0f));
		return true;	
	}
	else
		return false;
}
