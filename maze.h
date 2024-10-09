// .h file for my haunted house which i called maze for short

#include "myutil.h"
#include <vector>


class Maze {
private:
    vector<vector<char>> layout;  // 2D array or vector to represent the maze structure
    int rows, cols;               // Dimensions of the maze
    int currentRow, currentCol;    // Attendee's position in the maze
    int startRow, startCol;        // Starting point
    int endRow, endCol;            // End point of the maze

public:
    // Constructor to initialize maze size and layout
    Maze(int rows, int cols);
    Maze();
    ~Maze();
    Maze(Maze& aMaze);

    // Movement functions
    bool moveForward();
    bool turnLeft();
    bool turnRight();

    // Check for features like dead ends or traps
    bool isDeadEnd() const;
    bool isTrap() const;

    // Display maze structure
    void displayMaze() const;

   
};
