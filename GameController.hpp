
class GameController : public osgGA::GUIEventHandler
{
public:
    GameController( osg::Group* root );

    virtual bool handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa );
    
protected:
    osg::observer_ptr<osg::Group> _root;
    float _direction;
    float _distance;
};
