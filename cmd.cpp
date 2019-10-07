#include"cmd.h"


//Konstruktor
cmds::cmds() {

	for (int i = 0; i < 3; i++) {
		cmd_.push_back("");
	}
	cmd = "";
	folder_numbers = 0;
	
}


//Parancs bekérése
void cmds::getCmd() {

	cmd_.clear();

	int j = 0;

	cmd_.push_back("");

	getline(cin,cmd);

	for (int i = 0; i < size(cmd); i++) {
		if (cmd[i] == ' ') {

			j += 1;

			cmd_.push_back("");

		}
		else if (cmd[i] != ' ') {
			cmd_[j] += cmd[i];
		}
	}

}

//Exit check
bool cmds::exit_chck() const {
	
	if (cmd_[0] == "exit") {
		return false;
	}
	else {
		return true;
	}

}

//Parancs ellenõrzése
void cmds::cmd_chck() {

	if (cmd_[0] == "mkdir") {
		mkdir();
	}
	else if (cmd_[0] == "ls") {
		ls();
	}
	else if (cmd_[0] == "cd") {
		cd();
	}
	else if (cmd_[0] == "exit") {
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

	if (size(cmd_) == 1 || (cmd_[1] == "")) {

		cout << "Parancs keves!" << endl;

	}
	else {

		for (int i = 0; i < size(rout); i++) {

			if (rout[i].mappa_nev == cmd_[1] && akt_folder == rout[i].mappa_szulo) {
				exist = true;
			}

		}

		if (exist == false) {

			rout.push_back(mappa());

			rout[folder_numbers].mappa_nev = cmd_[1];
			rout[folder_numbers].mappa_szulo = akt_folder;

			folder_numbers += 1;

		}
		else if (exist == true) {

			cout << "Az adott mappa letezik mar!" << endl;

		}

	}

}

//LS parancs
void cmds::ls() {

	cout << endl;

	for (int i = 0; i < size(rout); i++) {
		if (rout[i].mappa_szulo == akt_folder) {
			cout << rout[i].mappa_nev << endl;
		}
	}
}

//CD parancs
void cmds::cd() {

	exist = false;

	if (size(cmd_) == 1 || cmd_[1] == "") {

		cout << "folder neve hianyzik!" << endl;

	}
	else {

		for (int i = 0; i < size(rout); i++) {
			if (rout[i].mappa_nev == cmd_[1]) {
				exist = true;
			}
		}

		//Ugrás a gyökérbe
		if (cmd_[1] == "..") {

			akt_folder = "root";

		}
		//Ugrás megadott directoryba
		else if (cmd_[1] != "..") {

			if (exist) {

				akt_folder = cmd_[1];

			}
			else if (exist == false) {

				cout << "A megadott folder nem letezik!" << endl;

			}

		}

	}
	
}

//Kiíratás
void cmds::kiir() const{

	cout << endl << " - Aktualis directory: " << akt_folder << endl;
	cout << " - Parancs: ";

}

void cmds::rm() {

}