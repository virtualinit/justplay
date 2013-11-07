#include "innings.h"

/* definitions for team_player class */

team_player::team_player()
{
    playerName = "";
    currentStatus = "";
    totalRuns = 0;
    totalBalls = 0;
}
team_player::~team_player(){}

int team_player::getTotalRuns() const
{
    return totalRuns;
}
int team_player::getTotalBalls() const
{
    return totalBalls;
}
string team_player::getCurrentStatus() const
{
    return currentStatus;
}
string team_player::getPlayerName() const
{
    return playerName;
}
void team_player::setName(const string pName)
{
    playerName = pName;
}
void team_player::setStatus(const string status)
{
    currentStatus = status;
}
void team_player::setRuns(const int run)
{
    totalRuns += run;
}
void team_player::incrementBalls()
{
    totalBalls += 1;
}

/* definitions for match_inning class */

string match_inning::IN_teamPlayers[PLAYERS_PER_TEAM] = TEAM_IN_PLAYERS;
string match_inning::PK_teamPlayers[PLAYERS_PER_TEAM] = TEAM_PK_PLAYERS;
string match_inning::SL_teamPlayers[PLAYERS_PER_TEAM] = TEAM_SL_PLAYERS;
string match_inning::BD_teamPlayers[PLAYERS_PER_TEAM] = TEAM_BD_PLAYERS;
string match_inning::playerStatus[3] = PLAYER_STATUS;
int match_inning::balls_count = MATCH_TOTAL_OVERS*6;

match_inning::match_inning(string activeTeam, bool is_second_inning = false, int targetRuns = 0)
{
    string teams[] = PARTICIPATING_TEAMS;
    if(activeTeam == teams[0])
    {
        active_Team = teams[0];
        for(int i=0; i<PLAYERS_PER_TEAM; i++)
        {
            teamPlayerObj[i] = new team_player();
            teamPlayerObj[i]->setName(IN_teamPlayers[i]);
            teamPlayerObj[i]->setStatus(playerStatus[0]);
        }
    }
    if(activeTeam == teams[1])
    {
        active_Team = teams[1];
        for(int i=0; i<PLAYERS_PER_TEAM; i++)
        {
            teamPlayerObj[i] = new team_player();
            teamPlayerObj[i]->setName(PK_teamPlayers[i]);
            teamPlayerObj[i]->setStatus(playerStatus[0]);
        }
    }
    if(activeTeam == teams[2])
    {
        active_Team = teams[2];
        for(int i=0; i<PLAYERS_PER_TEAM; i++)
        {
            teamPlayerObj[i] = new team_player();
            teamPlayerObj[i]->setName(SL_teamPlayers[i]);
            teamPlayerObj[i]->setStatus(playerStatus[0]);
        }
    }
    if(activeTeam == teams[3])
    {
        active_Team = teams[3];
        for(int i=0; i<PLAYERS_PER_TEAM; i++)
        {
            teamPlayerObj[i] = new team_player();
            teamPlayerObj[i]->setName(BD_teamPlayers[i]);
            teamPlayerObj[i]->setStatus(playerStatus[0]);
        }
    }

    secondInning = is_second_inning;
    target = targetRuns;
    balls_count = MATCH_TOTAL_OVERS*6;
}
match_inning::~match_inning()
{
    delete teamPlayerObj;
}
int match_inning::get_team_score()
{
    int score(0);
    for(int i=0; i<PLAYERS_PER_TEAM; i++)
    {
        score += teamPlayerObj[i]->getTotalRuns();
    }
    return score;
}
int match_inning::get_team_wickets()
{
    int wickets(0);
    for(int i=0; i<PLAYERS_PER_TEAM; i++)
    {
        if(teamPlayerObj[i]->getCurrentStatus() == playerStatus[2]) wickets++;
    }
    return wickets;
}
float match_inning::get_team_overs()
{
    int balls(0);
    for(int i=0; i<PLAYERS_PER_TEAM; i++)
    {
        balls += teamPlayerObj[i]->getTotalBalls();
    }
    return balls2over(balls);
}
bool match_inning::show_score_board()
{
    /* Clear Screen */
    // system("cls");
	ClearScreen();

    /* Print Statements */
    cout << MATCH_SRC_STRIP << endl;
    cout << " " << " BATTING : " << active_Team << " | SCORE BOARD " << endl;
    cout << MATCH_SRC_STRIP << endl;
    cout << endl;

    if(secondInning)
    {
        cout << endl;
        cout << " " << "Second Innings";
        if(target-get_team_score()>0) cout << "  |  " << target-get_team_score() << " runs required to win in " << balls2over(balls_count) << " overs." << endl;
    }
    else
    {
        cout << endl;
        cout << " " << "First Innings  |  " << get_team_score() << " runs in " << get_team_overs() << " overs." << endl;
    }

    cout << endl << endl;

    /* Displaying Players List */
    for(int i=0; i<PLAYERS_PER_TEAM; i++)
    {
        cout << " " << "[" << i+1 << "]" << " "
             << teamPlayerObj[i]->getPlayerName() << "\t\t"
             << teamPlayerObj[i]->getCurrentStatus() << "\t\t"
             << teamPlayerObj[i]->getTotalRuns() << " runs in "
             << teamPlayerObj[i]->getTotalBalls() << " balls." << endl;
        cout << endl;
    }
    cout << endl;

    /* check every player is out? */
    if((get_team_wickets() == PLAYERS_PER_TEAM) || (get_team_overs() == MATCH_TOTAL_OVERS) || (get_team_score()>=target && secondInning==true))
    {
        /* HANDLE MATCH OVER SCENARIO HERE */
        cout << " TEAM SCORE: " << get_team_score() << "/" << get_team_wickets() << " (" << get_team_overs() << " Overs)" << endl;
        cout << endl;
        cout << " Inning Over! Press 1 to continue : ";
        char press_one;
        cin >> press_one;

        /* CONNECT HERE */
        return true;
    }

    char initBAT('0');
    int ia(0);
    while(!((initBAT == '1' )||(initBAT == '2')||(initBAT == '3')||(initBAT == '4')||(initBAT == '5')))
    {
        cout << " Select a player to start BATTING (1-5): ";
        cin >> initBAT;
        ia = initBAT - '0';

        if(teamPlayerObj[ia-1]->getCurrentStatus() == playerStatus[2])
        {
            cout << endl << " " << teamPlayerObj[ia-1]->getPlayerName() << " is " << teamPlayerObj[ia-1]->getCurrentStatus() << "." << endl;
            cout << endl;
            initBAT = '0';
        }
    }
    play(ia-1, secondInning, target);
    return false;
}
void match_inning::play(const int batsman, const bool isFollowUp, const int targetRuns)
{
    /* Clear Screen */
    //system("cls");
	ClearScreen();

    /* Print Statements */
    cout << MATCH_SRC_STRIP << endl;
    cout << " " << " BATTING : " << teamPlayerObj[batsman]->getPlayerName() << endl;
    cout << MATCH_SRC_STRIP << endl;
    cout << endl;
    cout << " No. of balls remaining: " << balls_count << endl;

    teamPlayerObj[batsman]->setStatus(playerStatus[1]);
    string possible_runs[] = MATCH_POSSIBLE_RUNS;

    for(int i=1; i<=balls_count; i++)
    {
        if(isFollowUp)
        {
            if(get_team_score()>=targetRuns) break;
        }

        cout << endl << " Enter 1 to play " << i << " ball : ";
        char ch; cin >> ch;
        int arraySize = sizeof(possible_runs)/sizeof(possible_runs[0]);
        string value = pick_random(possible_runs,arraySize);

        /* increment balls_counter and player_balls */
        balls_count--;
        teamPlayerObj[batsman]->incrementBalls();

        cout << endl << "\t";
        cout << value << endl << endl;

        if(value == "OUT")
        {
            teamPlayerObj[batsman]->setStatus(playerStatus[2]);
            break;
        }
        else
        {
            int run = getRun(value);
            teamPlayerObj[batsman]->setRuns(run);
        }
    }
    show_score_board();
}
void match_inning::write_score_file(const char* filename)
{
    const char delimiter('#');
    ofstream out(filename);

    out << "Team " << active_Team
        << delimiter
        << "Score " << get_team_score()
        << delimiter
        << "Wickets " << get_team_wickets()
        << delimiter
        << "Overs " << get_team_overs()
        << '\n';

    for(int i=0; i<PLAYERS_PER_TEAM; i++)
    {
        out << teamPlayerObj[i]->getPlayerName()
            << delimiter
            << teamPlayerObj[i]->getCurrentStatus()
            << delimiter
            << teamPlayerObj[i]->getTotalRuns()
            << " runs in "
            << teamPlayerObj[i]->getTotalBalls()
            << " balls."
            << '\n';
    }
}


