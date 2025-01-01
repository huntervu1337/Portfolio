#ifndef HEX_GRAPH_H
#define HEX_GRAPH_H

#include <vector>

class HexBoard;

class HexGraph {
public:
    HexGraph(const HexBoard& board, int n);
    void addCornerList(int x);
    void addLeftEdgeList(int x);
    void addRightEdgeList(int x);
    void addTopEdgeList(int x);
    void addBottomEdgeList(int x);
    void addInternalList(int x);
    void printAdList(int x) const;
    friend class HexBoard;
private:
    int boardRowSize;
    int graphSize;
    std::vector<std::vector<int>> adList;
};

#endif