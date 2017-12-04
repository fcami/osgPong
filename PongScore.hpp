
#ifndef PONGSCORE
#define PONGSCORE

#include <osgText/Font>
#include <osgText/Text>

class PongScore : public osgText::Text
{
public:
    PongScore();
    enum ScoreSide
    {
        INVALID=0, LEFT, RIGHT
	};
    bool setScoreSide( ScoreSide side );
        
protected:
	ScoreSide _side;
};

#endif
