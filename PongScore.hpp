
class PongScore
{
public:
	PongScore(); 
	const int getScore();
	void incrScore();
	void resetScore();
	
protected:
    int _score;
};

