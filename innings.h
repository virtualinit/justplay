#ifndef INNINGS_H_INCLUDED
#define INNINGS_H_INCLUDED

/* Include Header Files */

#include "main.h"

using namespace std;

/* define class */

class team_player
{
public:
    team_player();
    ~team_player();

    /* getters funstions */
    int getTotalRuns() const;
    int getTotalBalls() const;
    string getPlayerName() const;
    string getCurrentStatus() const;

    /* setters functions */
    void setName(const string);
    void setStatus(const string);
    void setRuns(const int);
    void incrementBalls();

private:
    string playerName;
    string currentStatus;
    int totalRuns;
    int totalBalls;
};


class match_inning
{
private:
    string active_Team;
    bool secondInning;
    int target;

protected:
    team_player* teamPlayerObj[];

public:
    static string IN_teamPlayers[];
    static string PK_teamPlayers[];
    static string SL_teamPlayers[];
    static string BD_teamPlayers[];
    static string playerStatus[];
    static int balls_count;

    match_inning(string, bool, int);
    ~match_inning();

    void play(const int, const bool, const int);
    int get_team_score();
    int get_team_wickets();
    float get_team_overs();
    bool show_score_board();
    void write_score_file(const char* filename);
};



#endif // INNINGS_H_INCLUDED
