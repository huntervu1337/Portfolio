#include "HexBoard.h"

#include <iostream>
using namespace std;
HexBoard::HexBoard(int n): board(n, std::vector<char>(n, '.')), graph(*this, n), size(n) {
	cout << "Board is initialized\nBlue goal is connect W-E; Red goal is connect N-S\nBlue goes first" << endl;
	cout << "Legal move is between (0, 0) and (" << size - 1 << ", " << size - 1 << ")" << endl;
	printBoard();
	cout << "To redo move, type in: -1" << endl;
}
void HexBoard::printBoard() const {
	for (int i = 0; i < size; ++i) {
		// Print leading spaces
		for (int spaceCount = 0; spaceCount < i * 2; ++spaceCount) cout << " ";

		// Print row elements
		for (int j = 0; j < size; ++j) {
			cout << board[i][j];
			if (j < size - 1) cout << " - ";
		}
		cout << endl;

		// Print connecting lines
		if (i < size - 1) {
			for (int spaceCount = 0; spaceCount < i * 2 + 1; ++spaceCount) cout << " ";
			for (int k = 0; k < size - 1; ++k) cout << "\\ / ";
			cout << "\\" << endl;
		}
	}
}

void HexBoard::placePiece(int i, int j, char c) {
	board[i][j] = c;
}

bool HexBoard::isFullRow() const {
	int count = 0;
	for (const auto& row : board) {
		count = 0;
		for (const auto& elem : row) {
			if (elem == '.' || elem == 'O') break;
			count++;
		}
		if (count == size) return true;
	}
	return false;
}

bool HexBoard::isFullCol() const {
	int count = 0;
	for (int j = 0; j < size; ++j) {
		count = 0;
		for (int i = 0; i < size; ++i) {
			if (board[i][j] == '.' || board[i][j] == 'X') break;
			count++;
		}
		if (count == size) return true;
	}
	return false;
}

void HexBoard::printList(int x) const {
	graph.printAdList(x);
}

char HexBoard::accessConverter(int x) const {
	int i = x / size;
	int j = x % size;
	return board[i][j];
}

bool HexBoard::findBluePath(vector<bool>& visited,const int x) const {
	if (x % size == size - 1) { // Reached right edge
		return true;
	}

	visited[x] = true;
	for (int neighbor : graph.adList[x]) {
		if (!visited[neighbor] && accessConverter(neighbor) == 'X') {
			if (findBluePath(visited, neighbor)) {
				return true;
			}
		}
	}
	return false;
}

bool HexBoard::isBlueWin() const {
	vector<bool> visited(graph.graphSize, false);

	// Start DFS from all left-edge nodes (Blue's starting edge)
	for (int i = 0; i < size; ++i) {
		int startNode = i * size;
		if (accessConverter(startNode) == 'X' && !visited[startNode]) {
			if (findBluePath(visited, startNode)) {
				return true;
			}
		}
	}
	return false;
}

bool HexBoard::findRedPath(vector<bool>& visited,const int x) const {
	if (x / size == size - 1) { // Reached bottom edge
		return true;
	}

	visited[x] = true;
	for (int neighbor : graph.adList[x]) {
		if (!visited[neighbor] && accessConverter(neighbor) == 'O') {
			if (findRedPath(visited, neighbor)) {
				return true;
			}
		}
	}
	return false;
}

bool HexBoard::isRedWin() const {
	vector<bool> visited(graph.graphSize, false);

	// Start DFS from all top-edge nodes (Red's starting edge)
	for (int i = 0; i < size; ++i) {
		int startNode = i;
		if (accessConverter(startNode) == 'O' && !visited[startNode]) {
			if (findRedPath(visited, startNode)) {
				return true;
			}
		}
	}
	return false;
}