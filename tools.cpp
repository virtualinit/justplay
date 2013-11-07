#include "tools.h"

using namespace std;

/* randomly pick an element from string array */
string pick_random(const string strArray[], const int elements)
{
    int r1 = (rand()-1)/rand();            /* Using Multiple Randoms */
    unsigned int r2 = rand()+r1;
    return strArray[r2%elements];
}

/* convert balls to overs */
float balls2over(const int no_of_balls)
{
    float first_part(0.0);
    float second_part(0.0);
    if(no_of_balls > 0)
    {
        first_part = int(no_of_balls/6);
        second_part = (no_of_balls-(first_part*6))/10;
    }
    return float(first_part + second_part);
}

int getRun(const string strRun)
{
    if(strRun == "1") return 1;
    if(strRun == "2") return 2;
    if(strRun == "3") return 3;
    if(strRun == "4") return 4;
    if(strRun == "6") return 6;
    else return 0;
}

string getNextTeam(const string teams[], const string first_team)
{
    if(first_team == teams[0])
    {
        return teams[1];
    }
    else
    {
        return teams[0];
    }
}

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

void ClearScreen()
{
    cout << string( 100, '\n' );
}
