#ifndef PLAYER
#define PLAYER

#include <osg/MatrixTransform>
#include <osgGA/GUIEventAdapter>

class Player : public osg::MatrixTransform
{
public:
    Player();
    
    explicit Player( float width, float height );
    
    float width() const { return _size[0]; }
    float height() const { return _size[1]; }
    
    void setSpeedVector( const osg::Vec3& sv ) { _speedVec = sv; }
    const osg::Vec3& getSpeedVector() const { return _speedVec; }
            
    virtual bool update( const osgGA::GUIEventAdapter& ea, osg::Group* root ) = 0;

    bool intersectsWith( Player* player ) const;
    
protected:
    osg::Vec2 _size;
    osg::Vec3 _speedVec;
};

#endif
