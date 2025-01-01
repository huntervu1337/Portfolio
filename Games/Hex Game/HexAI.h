#ifndef HEX_AI
#define HEX_AI

#include "Player.h"

#include <vector>

enum class AIMode { RANDOM, MONTECARLO, MACHINELEARNING};

class HexGame;

class AIPlayer {
public:
    AIPlayer() {}
    AIMode mode;
    Player side;
    void action(HexGame& hex, std::vector<int>&, std::vector<int>&);
    void randomMove(HexGame& hex, std::vector<int>&, std::vector<int>&);
    friend class HexGame;
};
#endif // HEX_AI