#include "test.h"

bool testPickRandom()
{
    string stringArray[] = MATCH_POSSIBLE_RUNS;
    //string stringArray[] = {"Head","Tail"};
    int arraySize = sizeof(stringArray)/sizeof(stringArray[0]);

    /* Sequential cout behaviour */
    cout << pick_random(stringArray,arraySize) << "\t"
         << pick_random(stringArray,arraySize) << "\t"
         << pick_random(stringArray,arraySize) << "\t"
         << pick_random(stringArray,arraySize) << "\t"
         << pick_random(stringArray,arraySize) << endl;


    /* fixed loop behaviour */
    for(int i=0; i<5; i++)
    {
        cout << pick_random(stringArray,arraySize) << "\t";
    }
    return true;
}

bool test_player_class()
{
    string players[] = TEAM_IN_PLAYERS;
    string status[] = PLAYER_STATUS;
    team_player Player1, Player2;

    Player1.setName(players[0]);
    Player1.setStatus(status[0]);
    Player2.setName(players[1]);
    Player2.setStatus(players[1]);

    cout << Player1.getPlayerName() << "\t" << Player1.getCurrentStatus() << endl
         << Player2.getPlayerName() << "\t" << Player2.getCurrentStatus() << endl;

    Player1.setRuns(24);
    for(int i=0; i<5; i++)
    {
        Player1.incrementBalls();
    }
    Player1.setStatus("NOT OUT");

    Player2.setRuns(17);
    for(int i=0; i<9; i++)
    {
        Player2.incrementBalls();
    }
    Player2.setStatus("PLAYING");

    cout << endl << endl;

    cout << Player1.getPlayerName() << "\t" << Player1.getCurrentStatus() << "\t" << Player1.getTotalRuns() << "\t" << Player1.getTotalBalls() << endl
         << Player2.getPlayerName() << "\t" << Player2.getCurrentStatus() << "\t" << Player2.getTotalRuns() << "\t" << Player2.getTotalBalls() << endl;

    return true;
}

bool test_match_class()
{
    string pTeams[] = PARTICIPATING_TEAMS;
    match_inning obj(pTeams[3], true, 9);
    // match_inning obj("BD", false, 0);
    obj.show_score_board();
    obj.write_score_file("match1.txt");

    return true;
}
