#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED

/* Header Files Required */

#include "main.h"

using namespace std;

/* Welcome Screen */

#define WELCOME_SRC_STRIP       "**************************************"
#define WELCOME_SCR_HEADLINE    "Welcome to Asia CUP"
#define WELCOME_SCR_TOPIC       "Matches"
#define WELCOME_SCR_MATCH_1     "1. (Group A) INDIA vs PAKISTAN"
#define WELCOME_SCR_MATCH_2     "2. (Group B) SRI LANKA vs BANGLADESH"
#define WELCOME_SCR_MATCH_3     "3. Group A Winner vs Group B Winner"
#define WELCOME_SCR_INPUT       "Press 1 (Group A) or 2 (Group B) to start MATCH"

/* Match Screen */

#define MATCH_SRC_STRIP       "**************************************"
#define MATCH_SCR_HEADLINE    "vs"
#define MATCH_SCR_TOSS        "Press 1 to TOSS"
#define MATCH_SELECT_BAT      "Select 1.BAT or 2.BALL for"
#define MATCH_ENTER_BAT       "Enter 1 or 2"
#define MATCH_SCR_TEAM        "elected to BAT first!"
#define MATCH_SCR_BATTING     "Press 1 to start BATTING"
#define MATCH_PRE_ENV         "Preparing Match Environment..."

/* Function Declarations */

void init_match(const string[]);
string welcome_screen();
const string match_screen(const string, const string, const string);
const string match_batting(const string, const string, const string);
void summary_screen();

#endif // MATCH_H_INCLUDED
