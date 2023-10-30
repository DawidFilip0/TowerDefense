#ifndef Path
#define Path

class Path {
private:
    
    int colour;
    int **route;
	static const int MAX_TURNS;
public:

    Path(int points[][2]);
    ~Path(); // Destructor to release dynamically allocated memory
    // Add member functions or other public members as needed
};

#endif
