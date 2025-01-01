#include "HexGraph.h"
#include "HexBoard.h"

#include <iostream>

HexGraph::HexGraph(const HexBoard& board, int n): graphSize(n * n), boardRowSize(n), adList(graphSize) {
    for (int x = 0; x < graphSize; ++x) {
        if (board.isCorner(x)) addCornerList(x);
        else if (board.isLeftEdge(x)) addLeftEdgeList(x);
        else if (board.isRightEdge(x)) addRightEdgeList(x);
        else if (board.isTopEdge(x)) addTopEdgeList(x);
        else if (board.isBottomEdge(x)) addBottomEdgeList(x);
        else addInternalList(x);
    }
}

void HexGraph::addCornerList(int x) {
    if (x == 0) {
        adList[x].emplace_back(x + 1);
        adList[x].emplace_back(x + boardRowSize);
    }
    else if (x == boardRowSize - 1) {
        adList[x].emplace_back(x - 1);
        adList[x].emplace_back(x + boardRowSize);
        adList[x].emplace_back(x + boardRowSize - 1);
    }
    else if (x == (boardRowSize - 1) * boardRowSize) {
        adList[x].emplace_back(x + 1);
        adList[x].emplace_back(x - boardRowSize);
        adList[x].emplace_back(x - boardRowSize + 1);
    }
    else if (x == boardRowSize * boardRowSize - 1) {
        adList[x].emplace_back(x - 1);
        adList[x].emplace_back (x - boardRowSize);
    }
}

void HexGraph::addLeftEdgeList(int x) {
    adList[x].emplace_back(x - boardRowSize);
    adList[x].emplace_back(x - boardRowSize + 1);
    adList[x].emplace_back(x + 1);
    adList[x].emplace_back(x + boardRowSize);
}

void HexGraph::addRightEdgeList(int x) {
    adList[x].emplace_back(x - boardRowSize);
    adList[x].emplace_back(x - 1);
    adList[x].emplace_back(x + boardRowSize - 1);
    adList[x].emplace_back(x + boardRowSize);
}

void HexGraph::addTopEdgeList(int x) {
    adList[x].emplace_back(x - 1);
    adList[x].emplace_back(x + 1);
    adList[x].emplace_back(x + boardRowSize - 1);
    adList[x].emplace_back(x + boardRowSize);
}

void HexGraph::addBottomEdgeList(int x) {
    adList[x].emplace_back(x - 1);
    adList[x].emplace_back(x + 1);
    adList[x].emplace_back(x - boardRowSize);
    adList[x].emplace_back(x - boardRowSize + 1);
}

void HexGraph::addInternalList(int x) {
    adList[x].emplace_back(x - boardRowSize);
    adList[x].emplace_back(x - boardRowSize + 1);
    adList[x].emplace_back(x - 1);
    adList[x].emplace_back(x + 1);
    adList[x].emplace_back(x + boardRowSize - 1);
    adList[x].emplace_back(x + boardRowSize);
}

void HexGraph::printAdList(int x) const {
    for (auto i : adList[x]) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
}








