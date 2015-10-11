#include <iostream>
#include <vector>

using namespace std;
enum CurveDirection {Left = 0x0000000f, Right = 0x000000f0,
                     Up = 0x00000f00, Down = 0x0000f000};

struct Letter
{
    //1-10
    int difficulty;
    int startX, startY;
    int endX,endY;

    CurveDirection direction;
};



int main(int argc, char const *argv[])
{
    vector<Letter> letters = 
    {
        { 1, -1, -1, -1, 1, Right}, //diff, sx, sy, ex, ey, direction
        { 1, 1, -1, 1, 1, Right}, //diff, sx, sy, ex, ey, direction
        { 1, 0, 1, 0, -1, Down}, //diff, sx, sy, ex, ey, direction
        { 3, -1, 1, 1, 0, Right}, //diff, sx, sy, ex, ey, direction
        { 1, 1, 1, -1, -1, Right | Up}, //diff, sx, sy, ex, ey, direction
        { 1, -1, 1, 1, -1, Right | Down}, //diff, sx, sy, ex, ey, direction
        { 2, -1, 1, 1, -1, Right}, //diff, sx, sy, ex, ey, direction
        { 3, -1, -1, 1, 1, Right}, //diff, sx, sy, ex, ey, direction
        { 2, -1, 1, 1, -1, Down}, //diff, sx, sy, ex, ey, direction
        { 3, -1, -1, 1, 1, Up}, //diff, sx, sy, ex, ey, direction
        { 3, -1, 0, 0, 1, Right}, //diff, sx, sy, ex, ey, direction
        { 3, 0, 1, 1, 0, Right}, //diff, sx, sy, ex, ey, direction
        { 4, 0, -1, 1, 0, Right}, //diff, sx, sy, ex, ey, direction
        { 3, -1, 0, 0, -1, Down}, //diff, sx, sy, ex, ey, direction
        { 2, -1, 1, 1, 1, Right | Up}, //diff, sx, sy, ex, ey, direction
        { 2, -1, -1, 1, -1, Right | Down}, //diff, sx, sy, ex, ey, direction
        { 2, -1, 1, -1, -1, }, //diff, sx, sy, ex, ey, direction
        { 2, 1, 1, 1, -1, }, //diff, sx, sy, ex, ey, direction
        { 4, -1, 1, 0, -1, }, //diff, sx, sy, ex, ey, direction
        { 4, -1, 1, 1, -1, }, //diff, sx, sy, ex, ey, direction
        { 4, 0, 1, -1, -1, }, //diff, sx, sy, ex, ey, direction
        { 4, 0, 1, 1, -1, }, //diff, sx, sy, ex, ey, direction
        { 5, -1, 1, 1, 1, }, //diff, sx, sy, ex, ey, direction
        { 4, 0, 1, 1, 0, }, //diff, sx, sy, ex, ey, direction
        { 6, -1, 1, 1, -1, }, //diff, sx, sy, ex, ey, direction
        { 4, -1, 1, 1, 0, }, //diff, sx, sy, ex, ey, direction
        { 4, -1, 0, 1, -1, }, //diff, sx, sy, ex, ey, direction
        { 5, 0, 1, 1, -1, }, //diff, sx, sy, ex, ey, direction
        { 2, -1, 0, 1, 1, }, //diff, sx, sy, ex, ey, direction
        { 3, -1, 0, 1, -1, }, //diff, sx, sy, ex, ey, direction
        { 3, -1, 1, 1, -1, }, //diff, sx, sy, ex, ey, direction
        { 2, -1, 1, -1, -1, }, //diff, sx, sy, ex, ey, direction
        { 2, 1, 1, 1, -1, }, //diff, sx, sy, ex, ey, direction
    };
}