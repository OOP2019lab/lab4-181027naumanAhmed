#include "CricketTeam.h"

//value initialization constructor
CricketTeam::CricketTeam()
{
	membernames = nullptr;
	no_of_members = 0;
	teamName = nullptr;
	for (int i = 0; i <10; i++)
	{
		Scoreinlast10matches[i] = 0;
	}

	Rank = 0;
	captain = "\0";
}

// constructor with 2 parameters
CricketTeam::CricketTeam(string teamName, int no_of_members)
{
	int size = 0;
	size = teamName.length();

	CricketTeam::teamName = new char[strlen(teamName.c_str())];
	strcpy_s(CricketTeam::teamName, sizeof(teamName), teamName.c_str());

	CricketTeam::no_of_members = no_of_members;

}

// file reading constructor
CricketTeam::CricketTeam(string fileName)
{

	ifstream fin;
	fin.open(fileName);

	if (fin)
	{
		string str;
		getline(fin, str, ':');
		getline(fin, str, '\n');

		teamName = new char[sizeof(str)];
		strcpy_s(teamName, sizeof(str), str.c_str());      // function to copy string while also converting to char array

		cout << teamName << endl;

		getline(fin, str, ':');
		fin >> no_of_members;

		cout << no_of_members << endl;

		fin.ignore();

		membernames = new string[no_of_members];

		for (int i = 0; i < no_of_members; i++)
		{
			getline(fin, membernames[i]);
			cout << membernames[i] << endl;
		}

		getline(fin, str, ':');
			fin >> Rank;
			cout << Rank << endl;

		getline(fin, str, ':');
			getline(fin, captain);
			cout << captain << endl;

		getline(fin, str, ':');

		for (int i = 0; i < 10; i++)
		{
			fin >> Scoreinlast10matches[i];
			cout << Scoreinlast10matches[i] << " ";
		}

		cout << endl << endl;
	}

	

	else
		cout << "Error opening File!!\n";

}

//4 setter functions

void CricketTeam::setCaptain(string capt)
{
	captain = capt;

}

void CricketTeam::setRank(int rank)
{
	Rank = rank;
}

void CricketTeam::setTeamName(string str)
{
	int size = 0;
	strlen(str.c_str());
	size++;

	teamName = new char[size];

	strcpy_s(teamName, size, str.c_str());
}

void CricketTeam::setNoOfMembers(int members)
{
	no_of_members = members;
}


//4 getter functions

string CricketTeam::getCaptain()
{
	return captain;
}

int CricketTeam::getRank()
{
	return Rank;
}

char* CricketTeam::getTeamName()
{
	return teamName;
}

int CricketTeam::getNoOfMembers()
{
	return no_of_members;
}


//calculates average
double CricketTeam::average()
{
	double sum = 0.0;
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		if (Scoreinlast10matches[i] != 0)
		{
			sum += Scoreinlast10matches[i];
			count++;
		}
	}

	return sum / count;
}


//calculates latest score 

void CricketTeam::latestScore() // printing latest score of the team with team name and captain name
{
	if (Scoreinlast10matches[9])
	{
		cout << "Team name: " << teamName;
		cout << "\nCaptain name: " << captain;
		cout << "\nLatest score: " << Scoreinlast10matches[9] << endl;
	}

}


//prints all details of CricketTeam

void CricketTeam::printTeam()
{
	cout << "Team name: " << teamName;
	cout << "\nCaptain name: " << captain;
	cout << "\nTotal members: " << no_of_members;
	cout << "\nRank: " << Rank << endl;


	for (int i = 0; i < 10; i++)
	{
		if (Scoreinlast10matches[i] != 0)
			cout << Scoreinlast10matches[i] << " ";
	}

	cout << endl << endl;
}

// compares two teams based on average score

bool CricketTeam::compareTeams(CricketTeam diff)
{
	double fisrtAverage = average();
	double secondAverage = diff.average();

	if (fisrtAverage > secondAverage)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// destructor 

CricketTeam::~CricketTeam()
{
	delete[]teamName;
	teamName = nullptr;
}