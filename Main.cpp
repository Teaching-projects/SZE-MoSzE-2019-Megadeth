#include<iostream>
#include<vector>
#include<string>
#include"cmd.h"


using namespace std;





int main() {
	
	cmds mappa;

	//Gy�k�r l�trehoz�sa
	mappa.gykr();

	do {
		
		//Akrtu�lis folder ki�r�sas
		mappa.kiir();

		//Parancs bek�r�se
		mappa.getCmd();

		//Parancs ellen�rz�se
		mappa.cmd_chck();



	} while (mappa.exit_chck());
	
	return 0;
}