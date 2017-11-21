
#include <osg/Geometry>
#include <osg/Geode>

#include "Player.hpp"

Player::Player() {}

Player::Player( float width, float height )
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

bool Player::intersectsWith( Player* player ) const
{
    osg::Vec3 pos = getMatrix().getTrans();
    osg::Vec3 pos2 = player->getMatrix().getTrans();
    return fabs(pos[0] - pos2[0]) < (width() + player->width()) * 0.5f &&
           fabs(pos[1] - pos2[1]) < (height() + player->height()) * 0.5f;
}
