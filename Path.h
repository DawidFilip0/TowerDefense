#ifndef Path_h
#define Path_h
#include <vector>

class Path {
private:
    int half_width;
    int colour;
	int MAX_TURNS;
public:
	int no_turns;
	std::vector<std::vector<int>> pathEdges;
	int **route;
    Path(int points[][2],int number_of_turns);
    ~Path();
    int getPointX(int s);
    int getPointY(int s);
    void calculatePathEdges();
  
};

#endif
