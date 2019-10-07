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
	

	//Mapp�k �tvonala
	vector<data> rout;

	//A parancs, darabokra szedve
	vector<string> cmd_;

	//A parancs, nem darabolva 
	string cmd;

	//Aktu�lis adatok
	string akt_folder;

	//Mapp�k sz�ma
	int folder_numbers;

	//MKDIR mappa l�tezik-e
	bool exist;

};




