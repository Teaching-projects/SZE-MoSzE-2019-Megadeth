#include"cmd.h"


//Konstruktor
cmds::cmds() {

	cmd_frst, cmd_scnd, cmd = "";
	folder_numbers = 0;
	
}


//Parancs bekérése
void cmds::getCmd() {

	bool frst = true;

	cmd = "";
	cmd_frst = "";
	cmd_scnd = "";

	getline(cin, cmd);

	for (int i = 0; i < size(cmd); i++) {
		if (frst) {
			if (cmd[i] == ' ') {
				frst = false;
			}
			else {
				cmd_frst += cmd[i];
			}
		}
		else if (frst == false) {
			cmd_scnd += cmd[i];
		}
	}

}

//Exit check
bool cmds::exit_chck() const {
	
	if (cmd_frst == "exit") {
		return false;
	}
	else {
		return true;
	}

}

//Parancs ellenõrzése
void cmds::cmd_chck() {

	if (cmd_frst == "mkdir") {
		mkdir();
	}
	else if (cmd_frst == "ls") {
		ls();
	}
	else if (cmd_frst == "cd") {
		cd();
	}
	else if (cmd_frst == "exit") {
	}
	else {
		cout << "Rossz parancs!" << endl;
	}

}

//Gyökér létrehozása
void cmds::gykr() {

	rout.push_back(mappa());

	rout[0].mappa_nev = "root";
	akt_folder = "root";

	folder_numbers += 1;
	
}

//MKDIR parancs 
void cmds::mkdir() {

	exist = false;

	for (int i = 0; i < size(rout); i++) {
		if (rout[i].mappa_nev == cmd_scnd) {
			exist = true;
		}
	}

	if (exist == false) {

		rout.push_back(mappa());

		rout[folder_numbers].mappa_nev = cmd_scnd;
		rout[folder_numbers].mappa_szulo = akt_folder;

		folder_numbers += 1;

	}
	else if (exist == true) {
		cout << "Az adott mappa letezik mar!" << endl;
	}
	
}

//Ls parancs
void cmds::ls() {

	cout << endl;

	for (int i = 0; i < size(rout); i++) {
		if (rout[i].mappa_szulo == akt_folder) {
			cout << rout[i].mappa_nev << endl;
		}
	}
}

void cmds::cd() {

	exist = false;

	for (int i = 0; i < size(rout); i++) {
		if (rout[i].mappa_nev == cmd_scnd) {
			exist = true;
		}
	}

	//Ugrás a gyökérbe
	if (cmd_scnd == "..") {

		akt_folder = "root";

	}
	//Ugrás megadott directoryba
	else if (cmd_scnd != "..") {

		if (exist) {

			akt_folder = cmd_scnd;

		}
		else if (exist == false) {

			cout << "A megadott folder nem letezik!" << endl;

		}

	}
	
}

//Kiíratás
void cmds::kiir() const{

	cout << endl << " - Aktualis directory: " << akt_folder << endl;
	cout << " - Parancs: ";

}