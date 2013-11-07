#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

/* Header Files Required */

#include <iostream>             /* Standard I/O */
#include <fstream>              /* File I/O */
#include <iomanip>              /* format manipulation */
#include <string>               /* string operations */
#include <sstream>
#include <vector>               /* vector operations */
#include <cstdlib>

#include "match.h"
#include "tools.h"
#include "test.h"
#include "innings.h"

/* Team INDIA */

#define TEAM_IN_PLAYERS        {"Sachin Tendulkar","Mahendra S Dhoni","Virat Kohli","Yuvraj Singh","Virender Sehwag"}

/* Team PAKISTAN */

#define TEAM_PK_PLAYERS        {"Shahid Afridi","Misbah-ul-Haq","Saeed Ajmal","Mohammad Hafeez","Umar Akmal  "}

/* Team SRI LANKA */

#define TEAM_SL_PLAYERS        {"Kumar Sangakkara","Mahela Jayawardene","Tillakaratne D","Lasith Malinga","Angelo Mathews"}

/* Team BANGLADESH */

#define TEAM_BD_PLAYERS        {"Shakib Al Hasan","Tamim Iqbal","Mushfiqur Rahim","Mohammad Ashraful","Mashrafe Mortaza"}

/* General Rules */

#define PLAYERS_PER_TEAM        5
#define MATCH_TOTAL_OVERS       5.0
#define MATCH_POSSIBLE_RUNS     {"0", "1","2","3","OUT","4","6"}
#define PARTICIPATING_TEAMS     {"INDIA", "PAKISTAN", "SRI LANKA", "BANGLADESH"}
#define PLAYER_STATUS           {"NOT OUT", "PLAYING", "OUT"}
#define MATCH_TOKEN             {"Group A", "Group B", "Final Match"}

/* File Names */
#define GROUP_A_TEAM_1          "GroupA_Team_1.txt"
#define GROUP_B_TEAM_1          "GroupB_Team_1.txt"
#define GROUP_A_TEAM_2          "GroupA_Team_2.txt"
#define GROUP_B_TEAM_2          "GroupB_Team_2.txt"
#define FINAL_TEAM_1            "Final_Team_1.txt"
#define FINAL_TEAM_2            "Final_Team_2.txt"

#endif // MAIN_H_INCLUDED
