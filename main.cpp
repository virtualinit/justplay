#include "main.h"

using namespace std;

void startProgram()
{
    string team[PLAYERS_PER_TEAM] = PARTICIPATING_TEAMS;
    init_match(team);
}

void testModule()
{
    // testPickRandom();
    // test_player_class();
    // test_match_class();
    // summary_screen();
}

int main()
{
    startProgram();
    // testModule();
    return 0;
}
