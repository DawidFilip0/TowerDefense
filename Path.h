#ifndef Path
#define Path

class Path {
private:
    
    int colour;
    int **route;
	const int MAX_TURNS;
public:

    Path(int points[][2]);
    ~Path();
  
};

#endif
