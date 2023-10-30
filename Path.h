#ifndef Path_h
#define Path_h

class Path {
private:
    
    int colour;
	int MAX_TURNS;
public:
	int **route;
    Path(int points[][2]);
    ~Path();
    int getPointX(int s);
    int getPointY(int s);
  
};

#endif
