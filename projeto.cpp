#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct dado2{
	char referencia[20];
	char period[20];
	char dataValue[20];
	char status[20];
	char unidade[20];
	char magnitude[10];
	char subject[100];
	char grupo[100];
	char titulo1[100];
	char titulo2[100];
	char titulo3[100];
	char titulo4[100];
	char titulo5[100];
};

int main(){
	
	ifstream arquivo2 ("lms-jun22qtr-csv.csv");
	ofstream arqb ("binario.dat", ios::binary);
	string lixo;
	dado2* dadO=new dado2;
	getline(arquivo2, lixo, '\n');
	while (!arquivo2.eof()){
		arquivo2.getline(dadO->referencia, sizeof(char[20]), ',');
		
		arquivo2.getline(dadO->period, sizeof(char[20]), ',');
		
		arquivo2.getline(dadO->dataValue, sizeof(char[20]), ',');
		
		arquivo2.getline(dadO->status, sizeof(char[20]), ',');
		
		arquivo2.getline(dadO->unidade, sizeof(char[20]), ',');
		
		arquivo2.getline(dadO->magnitude, sizeof(char[10]), ',');
		
		arquivo2.getline(dadO->subject, sizeof(char[100]), ',');
		
		arquivo2.getline(dadO->grupo, sizeof(char[100]), ',');
		
		arquivo2.getline(dadO->titulo1, sizeof(char[100]), ',');
		
		arquivo2.getline(dadO->titulo2, sizeof(char[100]), ',');
		
		arquivo2.getline(dadO->titulo3, sizeof(char[100]), ',');
		
		arquivo2.getline(dadO->titulo4, sizeof(char[100]), ',');
		
		arquivo2.getline(dadO->titulo5, sizeof(char[100]), '\n');
		
		arqb.write ((char*) dadO, int(sizeof(dado2)));
	}

	delete dadO;
	
	return 0;
}
