#include "match.h"

using namespace std;

const string match_batting(const string first_batting_team, const string second_batting_team, const string matchToken)
{
    // The First Match
    match_inning objInning1(first_batting_team, false, 0);
    objInning1.show_score_board();

    if(matchToken == "Group A") objInning1.write_score_file(GROUP_A_TEAM_1);
    if(matchToken == "Group B") objInning1.write_score_file(GROUP_B_TEAM_1);
    if(matchToken == "Final Match") objInning1.write_score_file(FINAL_TEAM_1);

    const int xTarget = objInning1.get_team_score()+1;

    // The second Match
    match_inning objInning2(second_batting_team, true, xTarget);
    objInning2.show_score_board();

    if(matchToken == "Group A") objInning2.write_score_file(GROUP_A_TEAM_2);
    if(matchToken == "Group B") objInning2.write_score_file(GROUP_B_TEAM_2);
    if(matchToken == "Final Match") objInning2.write_score_file(FINAL_TEAM_2);

    const int yTarget = objInning2.get_team_score();

    if(yTarget >= xTarget)
    {
        string tmp = second_batting_team;
        return tmp;
    }
    else if(xTarget > yTarget)
    {
        string tmp = first_batting_team;
        return tmp;
    }
    else return "MATCH_TIE";

}

const string match_screen(const string team1, const string team2, const string active_group)
{
    char initToss('0');
    char decideToss('0');
    char initBAT('0');
    while(!(initToss == '1')) {
        /* Clear Screen */
        // system("cls");
	ClearScreen();

        /* Print Statements */
        cout << MATCH_SRC_STRIP << endl;
        cout << "\t" << team1 << " " << MATCH_SCR_HEADLINE << " " << team2 << "\t" << endl;
        cout << MATCH_SRC_STRIP << endl;
        cout << endl;
        cout << endl;
        cout << " " << MATCH_SCR_TOSS << " ";
        cin.ignore(100,'\n');
        cin.get(initToss);
    }
    cout << endl;
    string toss[] = {team1,team2};
    string toss_wining_team = pick_random(toss, sizeof(toss)/sizeof(toss[0]));
    cout << " HEAD : " << toss_wining_team << "\t";
    cout << MATCH_SELECT_BAT << " " << toss_wining_team << "." <<endl;
    cout << endl;
    while(!((decideToss == '1') || (decideToss == '2'))) {
        cout << " " << MATCH_ENTER_BAT << " : ";
        cin.ignore(100,'\n');
        cin.get(decideToss);
    }
    cout << endl;
    string batting_team("");
    string bowling_team("");
    if(decideToss == '1' && toss_wining_team == team1)
    {
        batting_team = team1;
        bowling_team = team2;
        cout << " \"" << batting_team << " " << MATCH_SCR_TEAM << "\"" << endl;
    }
    else if(decideToss == '2' && toss_wining_team == team1)
    {
        batting_team = team2;
        bowling_team = team1;
        cout << " \"" << batting_team << " " << MATCH_SCR_TEAM << "\"" << endl;
    }
    else if(decideToss == '1' && toss_wining_team == team2)
    {
        batting_team = team2;
        bowling_team = team1;
        cout << " \"" << batting_team << " " << MATCH_SCR_TEAM << "\"" << endl;
    }
    else if(decideToss == '2' && toss_wining_team == team2)
    {
        batting_team = team1;
        bowling_team = team2;
        cout << " \"" << batting_team << " " << MATCH_SCR_TEAM << "\"" << endl;
    }

    cout << endl;
    while(!(initBAT == '1')) {
        cout << " " << MATCH_SCR_BATTING << " : ";
        cin.ignore(100,'\n');
        cin.get(initBAT);
    }
    cout << endl;
    cout << " " << MATCH_PRE_ENV;
    // Sleep(1000);
    return match_batting(batting_team, bowling_team, active_group);
}

string welcome_screen()
{
    char choice;
    while (!((choice == '1') || (choice == '2'))) {
        /* Clear Screen */
        // system("cls");
	ClearScreen();

        /* Print Statements */
        cout << WELCOME_SRC_STRIP << endl;
        cout << "\t" << WELCOME_SCR_HEADLINE << "\t" << endl;
        cout << WELCOME_SRC_STRIP << endl;
        cout << endl;
        cout << endl;
        cout << " " << WELCOME_SCR_TOPIC << endl;
        cout << endl;
        cout << endl;
        cout << "  " << WELCOME_SCR_MATCH_1 << endl;
        cout << endl;
        cout << "  " << WELCOME_SCR_MATCH_2 << endl;
        cout << endl;
        cout << "  " << WELCOME_SCR_MATCH_3 << endl;
        cout << endl;
        cout << endl;
        cout << " " << WELCOME_SCR_INPUT << " : ";
        cin.get(choice);
    }
    switch(choice)
    {
        case '1' : return string("Group A"); break;
        case '2' : return string("Group B"); break;
        default: return string(""); break;
    }
}

void init_match(const string pteam[])
{
    const string matchToken[] = MATCH_TOKEN;
    bool grpA_Played, grpB_played = false;
    string firstMatchWinner("");
    string secondMatchWinner("");
    string finalMatchWinner("");

    /* Display Welcome Screen */
    string active_grp(welcome_screen());

    /* Clear Input Buffer */
    cin.clear();

    /* Selecting Group to Startwith */
    if(active_grp == matchToken[0])
    {
        firstMatchWinner = match_screen(pteam[0], pteam[1], active_grp);
        grpA_Played = true;
    }
    else if(active_grp == matchToken[1])
    {
        firstMatchWinner = match_screen(pteam[2], pteam[3], active_grp);
        grpB_played = true;
    }

    // system("cls");
	ClearScreen();
    cout << endl << endl << endl << "\t";
    cout << firstMatchWinner << " won the match!";
    cout << endl << endl << endl << "\t";
    cout << "Press 1 to PLAY next match : ";
    char tempCH1; cin >> tempCH1;

    /* Starting Second Match */
    if(grpA_Played) secondMatchWinner = match_screen(pteam[2], pteam[3], matchToken[1]);
    else if(grpB_played) secondMatchWinner = match_screen(pteam[0], pteam[1], matchToken[0]);

    /* clear screen */
    // system("cls");
	ClearScreen();
    cout << endl << endl << endl << "\t";
    cout << secondMatchWinner << " won the match!";
    cout << endl << endl << endl << "\t";
    cout << "Press 1 to PLAY final match : ";
    char tempCH2; cin >> tempCH2;

    /* Starting Final Match */
    finalMatchWinner = match_screen(firstMatchWinner, secondMatchWinner, matchToken[2]);

    /* clear screen */
    // system("cls");
	ClearScreen();
    cout << endl << endl << endl << "\t";
    cout << finalMatchWinner << " won the SERIES!";
    cout << endl << endl << endl << "\t";
    cout << "Press 1 to view SUMMARY : ";
    char tempCH3; cin >> tempCH3;

    // and FINALLY...
    summary_screen();
}
void summary_screen()
{
    /* parse files generated and create summary  */

    const string matchToken[] = MATCH_TOKEN;

    string line("");
    ifstream in1(GROUP_A_TEAM_1);
    getline(in1, line);
    vector<string> GROUP_A_TEAM_1_strArray = split(line, '#');
    in1.close();

    /* clear screen */
    // system("cls");
	ClearScreen();

    cout << "*****************************" << endl
         << "\t" << matchToken[0] << endl
         << "*****************************" << endl;
    cout << endl
         << " " << GROUP_A_TEAM_1_strArray[0] << " | "
         << " " << GROUP_A_TEAM_1_strArray[1] << " | "
         << " " << GROUP_A_TEAM_1_strArray[2] << " | "
         << " " << GROUP_A_TEAM_1_strArray[3] << endl;

    ifstream in2(GROUP_A_TEAM_2);
    getline(in2, line);
    vector<string> GROUP_A_TEAM_2_strArray = split(line, '#');
    in2.close();

    cout << endl
         << " " << GROUP_A_TEAM_2_strArray[0] << " | "
         << " " << GROUP_A_TEAM_2_strArray[1] << " | "
         << " " << GROUP_A_TEAM_2_strArray[2] << " | "
         << " " << GROUP_A_TEAM_2_strArray[3] << endl;

    cout << endl << endl;

    ifstream in3(GROUP_B_TEAM_1);
    getline(in3, line);
    vector<string> GROUP_B_TEAM_1_strArray = split(line, '#');
    in3.close();

    cout << "*****************************" << endl
         << "\t" << matchToken[1] << endl
         << "*****************************" << endl;
    cout << endl
         << " " << GROUP_B_TEAM_1_strArray[0] << " | "
         << " " << GROUP_B_TEAM_1_strArray[1] << " | "
         << " " << GROUP_B_TEAM_1_strArray[2] << " | "
         << " " << GROUP_B_TEAM_1_strArray[3] << endl;

    ifstream in4(GROUP_B_TEAM_2);
    getline(in4, line);
    vector<string> GROUP_B_TEAM_2_strArray = split(line, '#');
    in4.close();

    cout << endl
         << " " << GROUP_B_TEAM_2_strArray[0] << " | "
         << " " << GROUP_B_TEAM_2_strArray[1] << " | "
         << " " << GROUP_B_TEAM_2_strArray[2] << " | "
         << " " << GROUP_B_TEAM_2_strArray[3] << endl;

    cout << endl << endl;

    ifstream in5(FINAL_TEAM_1);
    getline(in5, line);
    vector<string> FINAL_TEAM_1_strArray = split(line, '#');
    in5.close();

    cout << "*****************************" << endl
         << "\t" << matchToken[2] << endl
         << "*****************************" << endl;
    cout << endl
         << " " << FINAL_TEAM_1_strArray[0] << " | "
         << " " << FINAL_TEAM_1_strArray[1] << " | "
         << " " << FINAL_TEAM_1_strArray[2] << " | "
         << " " << FINAL_TEAM_1_strArray[3] << endl;

    ifstream in6(FINAL_TEAM_2);
    getline(in6, line);
    vector<string> FINAL_TEAM_2_strArray = split(line, '#');
    in6.close();

    cout << endl
         << " " << FINAL_TEAM_2_strArray[0] << " | "
         << " " << FINAL_TEAM_2_strArray[1] << " | "
         << " " << FINAL_TEAM_2_strArray[2] << " | "
         << " " << FINAL_TEAM_2_strArray[3] << endl;

    cout << endl << endl << endl << " " << "GAME OVER..!" << endl;
}
