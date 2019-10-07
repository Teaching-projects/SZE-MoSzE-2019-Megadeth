#pragma once

#include<iostream>
#include<vector>
#include<string>

using namespace std;


class cmds
{
public:

	//Konstruktor
	cmds();

	//Parancs bek�r�se
	void getCmd();

	//Exit check
	bool exit_chck() const;

	//Parancs ellen�rz�se 
	void cmd_chck();

	//Gy�k�r l�trehoz�sa
	void gykr();

	//Mkdir parancs
	void mkdir();

	//LS parancs
	void ls();

	//CD parancs
	void cd();

	//RM parancs
	void rm();

	//Aktu�lis poz�ci� ki�r�sa
	void kiir() const;

private:

	struct mappa
	{

		//Folder adatok
		string mappa_nev;
		string mappa_szulo;

	};

	//Mapp�k �tvonala
	vector<mappa> rout;

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




