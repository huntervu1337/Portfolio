#include "HexGame.h"
#include "HexAI.h"

#include <iostream>
using namespace std;

void HexGame::chooseMode() {
    cout << "Choose game mode: single player is 0, local co-op is 1" << endl;
    int i;
    cin >> i;
    gameMode = static_cast<GameMode>(i);
}

void HexGame::chooseSide() {
    cout << "Choose side: blue is 0, red is 1" << endl;
    int i;
    cin >> i;
    if (i == 0) {
        player1 = Player::BLUE;
        AI.side = Player::RED;
    }
    else {
        player1 = Player::RED;
        AI.side = Player::BLUE;
    }
}

void HexGame::chooseAIMode() {
    cout << "Choose AI mode: Random is 0, Monte Carlo is 1, Machine Learning is 2" << endl;
    int i;
    cin >> i;
    AI.mode = static_cast<AIMode>(i);
}

void HexGame::startGame() {
    chooseMode();
    if (gameMode == GameMode::LOCALCOOP) coopModeTurn();
    else if (gameMode == GameMode::SINGLEPLAYER) {
        chooseSide();
        chooseAIMode();
        singleModeTurn();
    }
}

void HexGame::singleModeTurn() {
    vector<int> lastPlacedPieceRow;
    vector<int> lastPlacedPieceCol;
    while(!isOver()) {
        int i = 0, j = 0;
        bool undoAction = false;
        cout << (isBlueTurn() ? "Blue" : "Red") << " turn:" << endl;
        if (isPlayerTurn(player1)) {
            cin >> i;
            if (i == -1) undoAction = true;
            else cin >> j;
            if (undoAction) {
                if (turnCount > 0) {
                    // Undo the last move
                    placePiece(lastPlacedPieceRow.back(), lastPlacedPieceCol.back(), '.');
                    lastPlacedPieceRow.pop_back();
                    lastPlacedPieceCol.pop_back();
                    placePiece(lastPlacedPieceRow.back(), lastPlacedPieceCol.back(), '.');
                    lastPlacedPieceRow.pop_back();
                    lastPlacedPieceCol.pop_back();
                    board.printBoard();
                    turnCount -= 2;
                }
                else cout << "No more redo!" << endl;
            } else if (!undoAction) {
                // Validate and place the piece
                while (!isLegal(i, j)) {
                    cout << "Illegal move, please retry:" << endl;
                    cin >> i >> j;
                }
                placePiece(i, j, isBlueTurn() ? 'X' : 'O');
                lastPlacedPieceRow.push_back(i);
                lastPlacedPieceCol.push_back(j);
                cout << (isBlueTurn() ? "Blue" : "Red") << " placed (" << i << ", " << j << ")" << endl;
                board.printBoard();
                turnCount++;
            }
        }
        else if (!isPlayerTurn(player1)) {
            AI.action(*this, lastPlacedPieceRow, lastPlacedPieceCol);
            cout << (isBlueTurn() ? "Blue" : "Red") << " placed (" << i << ", " << j << ")" << endl;
            board.printBoard();
            turnCount++;
        }
    }
}

void HexGame::coopModeTurn() {
    vector<int> lastPlacedPieceRow;
    vector<int> lastPlacedPieceCol;
    while (!isOver()) {
        int i = 0, j = 0;
        bool undoAction = false;
        cout << (isBlueTurn() ? "Blue" : "Red") << " turn:" << endl;
        cin >> i;
        if (i == -1) undoAction = true;
        else cin >> j;
        if (undoAction) {
            if (turnCount > 0) {
                // Undo the last move
                placePiece(lastPlacedPieceRow.back(), lastPlacedPieceCol.back(), '.');
                lastPlacedPieceRow.pop_back();
                lastPlacedPieceCol.pop_back();
                board.printBoard();
                turnCount--;
            }
            else cout << "No more redo!" << endl;
        } else if (!undoAction) {
            // Validate and place the piece
            while (!isLegal(i, j)) {
                cout << "Illegal move, please retry:" << endl;
                cin >> i >> j;
            }
            placePiece(i, j, isBlueTurn() ? 'X' : 'O');
            lastPlacedPieceRow.push_back(i);
            lastPlacedPieceCol.push_back(j);
            cout << (isBlueTurn() ? "Blue" : "Red") << " placed (" << i << ", " << j << ")" << endl;
            board.printBoard();
            turnCount++;
        }
    }
}


void HexGame::placePiece(int i, int j, char c) {
    board.placePiece(i, j, c);
}

bool HexGame::isOver() const {
    if (board.isBlueWin()) {
        cout << "Blue wins" << endl;
        return true;
    }
    if (board.isRedWin()) {
        cout << "Red wins" << endl;
        return true;
    }
    return false;
}
