#include <iostream>
#include "HexBoard.h"
#include "HexGame.h"
using namespace std;
int main()
{
    cout << "Input board size: " << endl;
    int size;
    cin >> size;
    HexGame hex(size);
    hex.startGame();
    return 0;
}