
class PlayerScore
{
public:
	PlayerScore(); 
	const int getScore();
	void incrScore();
	void resetScore();
	
protected:
    int _score;
};

