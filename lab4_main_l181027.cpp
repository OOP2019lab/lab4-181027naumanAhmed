#include   "CricketTeam.h"



int main()
{

	string fileName = "Pakistan.txt";

	CricketTeam teamOne(fileName);   // CricketTeam from file

	CricketTeam teamTwo;

	string str;
	int temp = 0;

	cout << "Enter team name: ";
	getline(cin, str);
	teamTwo.setTeamName(str);
	

	cout << "Enter no of members in this team: ";
	cin >> temp;
	teamTwo.setNoOfMembers(temp);

	cout << "Enter team rank: ";
	cin >> temp;
	teamTwo.setRank(temp);

	/*cin.ignore();*/
	cout << "Enter name of captain: ";
	getline(cin, str);
	teamTwo.setCaptain(str);
	


	cout << "\nThe better of both teams is:\n\n";

	if (teamOne.compareTeams(teamTwo))
	{
		teamOne.printTeam();  // prints pakistan if it is better team
	}
	else
	{
		teamTwo.printTeam();  // prints other team if it is better
	}


}