#pragma once

#include<iostream>
#include<vector>
#include<string>

using namespace std;


class cmds
{
public:

	cmds();

	void getCmd();

	bool exit_chck() const;

	void cmd_chck() ;

	void gykr();

	void mkdir();

	void ls() const;

	void cd();

	void rm();

	void touch();

	void kiir() const;


private:

	struct data
	{

		//Adatok
		string nev;
		string szulo;
		string tipus;

	};
	

	//Mappák útvonala
	vector<data> rout;

	//A parancs, darabokra szedve
	vector<string> cmd_;

	//A parancs, nem darabolva 
	string cmd;

	//Aktuális adatok
	string akt_folder;

	//Mappák száma
	int folder_numbers;

	//MKDIR mappa létezik-e
	bool exist;

};




