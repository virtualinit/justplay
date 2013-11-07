#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

/* Header Files Required */

#include "main.h"

using namespace std;

string pick_random(const string[], const int);
float balls2over(const int);
int getRun(const string);
string getNextTeam(const string[], const string);
vector<string> split(const string &, char);
void ClearScreen();

#endif // TOOLS_H_INCLUDED
