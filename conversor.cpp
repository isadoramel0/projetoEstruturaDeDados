#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct baseDados {
    char referencia[100];
    char period[100];
    char dataValue[100];
    char status[100];
    char unidade[100];
    char magnitude[100];
    char subject[100];
    char grupo[100];
    char titulo1[100];
    char titulo2[100];
    char titulo3[100];
    char titulo4[100];
    char titulo5[100];
};

int main(){
	cout << "Espere um momento, o arquivo está sendo convertido..." << endl << endl;

	ifstream arquivo2 ("lms-jun22qtr-csv.csv");
	if (arquivo2){
		ofstream arqb ("binario.dat", ios::binary);
		int tamanho = 0;
		int qt = 0;
		int cont; //Percorre cada linha lida
		string lixo; //Armazena o cabeçalho
		char lixo2; //Armazena aspas e vírgulas não lidas
		getline(arquivo2, lixo, '\n'); //Leitura do cabeçalho
		string linha; //Lê cada linha do arquivo
		int cont2; //Percorre cada atributo
		
		baseDados* dadO=new baseDados; //Armazena os dados para escrever no arquivo
		while (!arquivo2.eof()){
			qt++;
			cont = 0;
			getline(arquivo2, linha);
			tamanho = linha.size();
			
			cont2=0;
			if (linha[cont]=='"'){
				cont++; //Começa a ler a partir do caracter sem aspas
				while (linha[cont]!='"'){
					dadO->referencia[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont]; //Armazena as aspas finais
				cont++;
				lixo2 = linha[cont]; //Armazena a vírgula
				cont++;
			}else{
				while (linha[cont]!=','){
					dadO->referencia[cont2]=linha[cont];
					cont++;
					cont2++;
				}

				lixo2 = linha[cont]; //Armazena a vírgula
				cont++;
			}
			dadO->referencia[cont2] = '\0'; //Determina o fim do vetor de char
			cont2 = 0;
			if (linha[cont]=='"'){
				cont++;
				while (linha[cont]!='"'){
					dadO->period[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
				lixo2 = linha[cont];
				cont++;
			}else{
				while (linha[cont]!=','){
					dadO->period[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
			}
			dadO->period[cont2] = '\0';
			
			cont2 = 0;
			if (linha[cont]=='"'){
				cont++;
				while (linha[cont]!='"'){
					dadO->dataValue[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
				lixo2 = linha[cont];
				cont++;
			}else{
				while (linha[cont]!=','){
					dadO->dataValue[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
			}
			dadO->dataValue[cont2] = '\0';
			
			cont2 = 0;
			if (linha[cont]=='"'){
				cont++;
				while (linha[cont]!='"'){
					dadO->status[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
				lixo2 = linha[cont];
				cont++;
			}else{
				while (linha[cont]!=','){
					dadO->status[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
			}
			dadO->status[cont2] = '\0';
			
			cont2 = 0;
			if (linha[cont]=='"'){
				cont++;
				while (linha[cont]!='"'){
					dadO->unidade[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
				lixo2 = linha[cont];
				cont++;
			}else{
				while (linha[cont]!=','){
					dadO->unidade[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
			}
			dadO->unidade[cont2] = '\0';
			
			cont2 = 0;
			if (linha[cont]=='"'){
				cont++;
				while (linha[cont]!='"'){
					dadO->magnitude[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
				lixo2 = linha[cont];
				cont++;
			}else{
				while (linha[cont]!=','){
					dadO->magnitude[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
			}
			dadO->magnitude[cont2] = '\0';
			
			cont2 = 0;
			if (linha[cont]=='"'){
				cont++;
				while (linha[cont]!='"'){
					dadO->subject[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
				lixo2 = linha[cont];
				cont++;
			}else{
				while (linha[cont]!=','){
					dadO->subject[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
			}
			dadO->subject[cont2] = '\0';
			
			cont2 = 0;
			if (linha[cont]=='"'){
				cont++;
				while (linha[cont]!='"'){
					dadO->grupo[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
				lixo2 = linha[cont];
				cont++;
			}else{
				while (linha[cont]!=','){
					dadO->grupo[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
			}
			dadO->grupo[cont2] = '\0';
			
			cont2 = 0;
			if (linha[cont]=='"'){
				cont++;
				while (linha[cont]!='"'){
					dadO->titulo1[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
				lixo2 = linha[cont];
				cont++;
			}else{
				while (linha[cont]!=','){
					dadO->titulo1[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
			}
			dadO->titulo1[cont2] = '\0';
			
			cont2 = 0;
			if (linha[cont]=='"'){
				cont++;
				while (linha[cont]!='"'){
					dadO->titulo2[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
				lixo2 = linha[cont];
				cont++;
			}else{
				while (linha[cont]!=','){
					dadO->titulo2[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
			}
			dadO->titulo2[cont2] = '\0';
			
			cont2 = 0;
			if (linha[cont]=='"'){
				cont++;
				while (linha[cont]!='"'){
					dadO->titulo3[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
				lixo2 = linha[cont];
				cont++;
			}else{
				while (linha[cont]!=','){
					dadO->titulo3[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
			}
			dadO->titulo3[cont2] = '\0';
			
			cont2 = 0;
			if (linha[cont]=='"'){
				cont++;
				while (linha[cont]!='"'){
					dadO->titulo4[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
				lixo2 = linha[cont];
				cont++;
			}else{
				while (linha[cont]!=','){
					dadO->titulo4[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
			}
			dadO->titulo4[cont2] = '\0';
			
			cont2 = 0;
			if (linha[cont]=='"'){
				cont++;
				while (linha[cont]!='"'){
					dadO->titulo5[cont2]=linha[cont];
					cont++;
					cont2++;
				}
				lixo2 = linha[cont];
				cont++;
			}else{
				while (cont<tamanho){ //Enquanto não acabar a linha
					dadO->titulo5[cont2]=linha[cont];
					cont++;
					cont2++;
				}
			}
			dadO->titulo5[cont2-1] = '\0';
			arqb.write ((char*) dadO, int(sizeof(baseDados)));
		}
		delete dadO;
		cout << "Conversão realizada com sucesso!" << endl << "Seu arquivo está salvo como binario.dat" << endl;
		cout << "Quantidade de dados: " << qt-1 << endl; //O conversor escreve uma linha a mais em branco
			
			
	}else{
		cout << "O arquivo .csv não foi aberto corretamente" << endl;
	}
	
	return 0;
}
	
