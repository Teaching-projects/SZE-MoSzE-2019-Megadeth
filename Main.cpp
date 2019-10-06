#include<iostream>
#include<vector>
#include<string>
#include"cmd.h"


using namespace std;





int main() {
	
	cmds mappa;

	//Gyökér létrehozása
	mappa.gykr();

	do {
		
		//Akrtuális folder kiírásas
		mappa.kiir();

		//Parancs bekérése
		mappa.getCmd();

		//Parancs ellenõrzése
		mappa.cmd_chck();



	} while (mappa.exit_chck());
	
	return 0;
}