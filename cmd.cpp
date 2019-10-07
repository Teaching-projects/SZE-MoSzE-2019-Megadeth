#include"cmd.h"


cmds::cmds() {

	for (int i = 0; i < 3; i++) {
		cmd_.push_back("");
	}
	cmd = "";
	folder_numbers = 0;
	
}


// Parancs bekérése
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

// Exit check
bool cmds::exit_chck() const {
	
	if (cmd_[0] == "exit") {
		return false;
	}
	else {
		return true;
	}

}

// Parancs ellenõrzése
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
	else if (cmd_[0] == "rm") {

		rm();

	}
	else if (cmd_[0] == "touch") {

		touch();

	}
	else if (cmd_[0] == "exit") {
	}
	else {
		cout << "Rossz parancs!" << endl;
	}

}

// Gyökér létrehozása
void cmds::gykr() {

	rout.push_back(data());

	rout[0].nev = "root";
	akt_folder = "root";

	folder_numbers += 1;
	
}

// MKDIR parancs 
void cmds::mkdir() {

	exist = false;

	if (size(cmd_) == 1 || (cmd_[1] == "")) {

		cout << "Parancs keves!" << endl;

	}
	else {

		for (int i = 0; i < size(rout); i++) {

			if (rout[i].nev == cmd_[1] && akt_folder == rout[i].szulo && rout[i].tipus == "Folder") {
				exist = true;
			}

		}

		if (exist == false) {

			rout.push_back(data());

			rout[folder_numbers].nev = cmd_[1];
			rout[folder_numbers].szulo = akt_folder;
			rout[folder_numbers].tipus = "Folder";

			folder_numbers += 1;

		}
		else if (exist == true) {

			cout << "Az adott nevu mappa letezik mar!" << endl;

		}

	}

}

// LS parancs
void cmds::ls() const{

	cout << endl;

	for (int i = 0; i < size(rout); i++) {
		if (rout[i].szulo == akt_folder) {
			cout << rout[i].tipus << " - " << rout[i].nev << endl;
		}
	}
}

// CD parancs
void cmds::cd() {

	exist = false;

	if (size(cmd_) == 1 || cmd_[1] == "") {

		cout << "folder neve hianyzik!" << endl;

	}
	else {

		for (int i = 0; i < size(rout); i++) {
			if (rout[i].nev == cmd_[1] && rout[i].tipus == "Folder") {
				exist = true;
			}
		}

		// Ugrás a gyökérbe
		if (cmd_[1] == "..") {

			akt_folder = "root";

		}
		// Ugrás megadott directoryba
		else if (cmd_[1] != "..") {

			if (exist) {

				akt_folder = cmd_[1];

			}
			else if (exist == false) {

				cout << "Az adott nevu folder nem letezik!" << endl;

			}

		}

	}
	
}

// Kiíratás
void cmds::kiir() const{

	cout << endl << " - Aktualis directory: " << akt_folder << endl;
	cout << " - Parancs: ";

}

// RM parancs
void cmds::rm() {

	exist = false;

	for (int i = 0; i < size(rout); i++) {

		if (rout[i].nev == cmd_[1] && rout[i].tipus == "File") {

			exist = true;

		}

	}

	if (exist) {

		// -RF parancs
		if (cmd_[1] == "-rf") {

			for (int i = 0; i < size(rout); i++) {

				if (rout[i].nev == cmd_[2]) {
					rout[i].nev.erase();
					rout[i].szulo.erase();
					rout[i].tipus.erase();
				}

			}

		}
		// Alap parancs
		else if(size(cmd_) == 2)
		{

			for (int i = 0; i < size(rout); i++) {

				if (rout[i].nev == cmd_[1] && rout[i].tipus == "File") {
					rout[i].nev.erase();
					rout[i].szulo.erase();
					rout[i].tipus.erase();
				}

			}

		}

	}
	else {

		cout << "A torolni kivant file nem letezik!" << endl;

	}

}

// TOUCH parancs
void cmds::touch() {

	exist = false;

	if (size(cmd_) == 1 || (cmd_[1] == "")) {

		cout << "Parancs keves!" << endl;

	}
	else {

		for (int i = 0; i < size(rout); i++) {

			if (rout[i].nev == cmd_[1] && akt_folder == rout[i].szulo && rout[i].tipus == "File") {
				exist = true;
			}

		}

		if (exist == false) {

			rout.push_back(data());

			rout[folder_numbers].nev = cmd_[1];
			rout[folder_numbers].szulo = akt_folder;
			rout[folder_numbers].tipus = "File";

			folder_numbers += 1;

		}
		else if (exist == true) {

			cout << "Az adott nevu file letezik mar!" << endl;

		}

	}

}