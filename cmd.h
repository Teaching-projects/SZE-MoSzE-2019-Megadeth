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

	//Parancs bekérése
	void getCmd();

	//Exit check
	bool exit_chck() const;

	//Parancs ellenõrzése 
	void cmd_chck();

	//Gyökér létrehozása
	void gykr();

	//Mkdir parancs
	void mkdir();

	//LS parancs
	void ls();

	//CD parancs
	void cd();

	//RM parancs
	void rm();

	//Aktuális pozíció kiírása
	void kiir() const;

private:

	struct mappa
	{

		//Folder adatok
		string mappa_nev;
		string mappa_szulo;

	};

	//Mappák útvonala
	vector<mappa> rout;

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




