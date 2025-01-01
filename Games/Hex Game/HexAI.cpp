#include "HexGame.h"
#include "HexAI.h"

#include <cstdlib>
#include <ctime>

void AIPlayer::action(HexGame& hex, std::vector<int>& lastPlacePieceRow, std::vector<int>& lastPlacePieceCol) {
    switch (mode) {
        case AIMode::RANDOM: randomMove(hex, lastPlacePieceRow, lastPlacePieceCol); break;
    }
}

void AIPlayer::randomMove(HexGame& hex, std::vector<int>& lastPlacePieceRow, std::vector<int>& lastPlacePieceCol) {
    srand(time(0));
    int size = hex.getBoardSize();
    int row = -1, col = -1, randomNode = -1;
    while (!hex.isLegal(row, col)) {
        randomNode = rand() % (size * size);
        row = randomNode / size;
        col = randomNode % size;
    }
    if (side == Player::BLUE) hex.placePiece(row, col, 'X');
    else hex.placePiece(row, col, 'O');
    lastPlacePieceRow.push_back(row);
    lastPlacePieceCol.push_back(col);
}