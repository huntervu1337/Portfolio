#ifndef HEX_BOARD_H
#define HEX_BOARD_H

#include "HexGraph.h"

#include <vector>

class HexBoard {
public:
    HexBoard(int n = 7);
    void printBoard() const;
    inline bool isEmpty(int i, int j) const;
    void placePiece(int i, int j, char c);
    inline bool isCorner(int x) const;
    inline bool isLeftEdge(int x) const;
    inline bool isRightEdge(int x) const;
    inline bool isVerticalEgde(int x) const;
    inline bool isTopEdge(int x) const;
    inline bool isBottomEdge(int x) const;
    inline bool isHorizontalEdge(int x) const;
    bool isFullRow() const;
    bool isFullCol() const;
    bool isBlueWin() const;
    bool isRedWin() const;
    bool findBluePath(std::vector<bool>& k,const int x) const;
    bool findRedPath(std::vector<bool>& k,const int x) const;
    char accessConverter(int x) const;
    friend class HexGame;
    void printList(int x) const;
private:
    // MUST PUT size BEFORE graph OTHERWISE size WILL HAVE NO VALUE AT THE TIME graph IS BEING CONSTRUCTED
    // WHICH LEAD TO isTopEdge and isBottomEdge UNEXPECTING BEHAVIOUR
    int size;
    std::vector<std::vector<char>> board;
    HexGraph graph;
};

bool HexBoard::isEmpty(int i, int j) const {
    if (board[i][j] == '.') return true;
    return false;
}

bool HexBoard::isCorner(int x) const {
    return (x == 0 || x == size - 1 || x == (size - 1) * size || x == size * size - 1);
}

bool HexBoard::isLeftEdge(int x) const {
    for (int i = 0; i < size; ++i) {
        if (x == i * size) return true;
    }
    return false;
}

bool HexBoard::isRightEdge(int x) const {
    for (int i = 0; i < size; ++i) {
        if (x == i * size + size - 1) return true;
    }
    return false;
}

bool HexBoard::isVerticalEgde(int x) const {
    return isLeftEdge(x) || isRightEdge(x);
}

bool HexBoard::isTopEdge(int x) const {
    return (x >= 0 && x < size);
}

bool HexBoard::isBottomEdge(int x) const {
    return (x >= (size - 1) * size && x < size * size);
}
bool HexBoard::isHorizontalEdge(int x) const {
    return isTopEdge(x) || isBottomEdge(x);
}

#endif // HEX_BOARD_H
