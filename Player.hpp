
#include <osg/MatrixTransform>
#include <osgGA/GUIEventAdapter>

#define RAND(min, max) ((min) + (float)rand()/(RAND_MAX) * ((max)-(min)))

class Player : public osg::MatrixTransform
{
public:
    Player();
    Player( float width, float height );
    
    float width() const { return _size[0]; }
    float height() const { return _size[1]; }
    
    void setSpeedVector( const osg::Vec3& sv ) { _speedVec = sv; }
    const osg::Vec3& getSpeedVector() const { return _speedVec; }
    
    enum PlayerType
    {
        INVALID=0, PLAYER1, PLAYER2, BALL
    };
    void setPlayerType( PlayerType t ) { _type = t; }
    PlayerType getPlayerType() const { return _type; }
    
    bool isBall() const { return _type==BALL; }
    
    bool update( const osgGA::GUIEventAdapter& ea, osg::Group* root );

// these two make no sense except for a ball. Use polymorphism at some point.
    bool reboundH( const osgGA::GUIEventAdapter& ea, osg::Group* root );
    bool reboundV( const osgGA::GUIEventAdapter& ea, osg::Group* root );

    bool intersectsWith( Player* player ) const;
    
protected:
    osg::Vec2 _size;
    osg::Vec3 _speedVec;
    PlayerType _type;
};

