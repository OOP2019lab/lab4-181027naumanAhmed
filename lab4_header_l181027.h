#include<string>
#include<iostream>
#include<fstream>
using namespace std;


class CricketTeam
{

	string * membernames;
	int no_of_members;
	char *teamName;
	int Scoreinlast10matches[10];
	int Rank;
	string captain;

public:

	//constructors
	CricketTeam();
	CricketTeam(string, int);
	CricketTeam(string);


	//setter functions

	void setCaptain(string capt);
	void setRank(int);
	void setTeamName(string);
	void setNoOfMembers(int);

	//getter functions

	string getCaptain();
	int getRank();
	char* getTeamName();
	int getNoOfMembers();

	//other functions

	double CricketTeam::average();
	void CricketTeam::latestScore();
	void CricketTeam::printTeam();
	bool CricketTeam::compareTeams(CricketTeam diff);
	CricketTeam::~CricketTeam();

};

