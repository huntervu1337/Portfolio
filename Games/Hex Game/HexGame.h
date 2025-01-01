#ifndef HEX_GAME_H
#define HEX_GAME_H

#include "HexBoard.h"
#include "Player.h"
#include "GameMode.h"
#include "HexAI.h"

class HexGame {
public:
    HexGame(int size = 7): board(size), turnCount(0) {}
    void chooseMode();
    void chooseSide();
    void chooseAIMode();
    void startGame();
    inline bool isBlueTurn() const;
    inline bool isPlayerTurn(Player playerSide) const;
    inline bool isPlayer2Turn(Player playerSide) const;
    void singleModeTurn();
    void coopModeTurn();
    inline bool isLegal(int i, int j) const;
    void placePiece(int i, int j, char c);
    bool isOver() const;
    int getBoardSize() { return board.size;}
    friend class AIPlayer;
private:
    HexBoard board;
    GameMode gameMode;
    Player player1; // default player
    AIPlayer AI;
    int turnCount;
};

bool HexGame::isBlueTurn() const {
    return (turnCount % 2 == 0);
}

bool HexGame::isPlayerTurn(Player playerSide) const {
    if (playerSide == Player::BLUE) {
        return isBlueTurn();
    }
    else return !isBlueTurn();
}

bool HexGame::isPlayer2Turn(Player playerSide) const {
    if (playerSide == Player::BLUE) {
        if (turnCount % 2 == 0) return true;
        return false;
    }
    else {
        if (turnCount % 2 != 0) return true;
        return false;
    }
}

bool HexGame::isLegal(int i, int j) const {
    if (i >= 0 && i < board.size && j >= 0 && j < board.size && board.isEmpty(i, j)) return true;
    return false;
}
#endif // HEX_GAME_H
