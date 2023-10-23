#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct baseDados {
    char referencia[100];
    char periodo[100];
    char valor[100];
    char status[100];
    char unidade[100];
    char magnitude[100];
    char assunto[100];
    char grupo[100];
    char titulo1[100];
    char titulo2[100];
    char titulo3[100];
    char titulo4[100];
    char titulo5[100];
};

void imprime (fstream& arquivo, int pos){ 
	baseDados* base = new baseDados;
	arquivo.seekg((pos)*sizeof(baseDados), ios::beg);
	arquivo.read ((char*) base, int(sizeof(baseDados)));
	cout << "Referencia: " << base->referencia << endl << "Periodo: " << base->periodo 
	<< endl << "Valor: " << base->valor << endl << "Status: " << base->status << endl 
	<< "Unidade: " << base->unidade << endl << "Magnitude: " << base->magnitude << endl
	<< "Assunto: "<< base->assunto << endl << "Grupo: "<< base->grupo << endl <<"Titulo1: "
	<< base->titulo1 << endl << "Titulo2: " << base->titulo2 << endl << "Titulo3: " << base->titulo3
	<< endl << "Titulo4: " << base->titulo4 << endl << "Titulo5: " << base->titulo5 <<endl;
	delete base;
}

void inserirNaPosicao(fstream& arq, int& tamanho, int posicao, const baseDados& novoRegistro) {

	arq.seekp(0, std::ios::end); 
	int cont = 1;
	baseDados aux;
	while((tamanho - cont) >= posicao){
		arq.seekg((tamanho - cont)*sizeof(baseDados));
		arq.read((char *) (&aux), sizeof(baseDados));

		arq.seekp((tamanho - cont +1 )*sizeof(baseDados));
		arq.write((const char *) (&aux), sizeof(baseDados));

		cont++;      
	}


	arq.seekp(posicao * sizeof(baseDados), std::ios::beg);
	arq.write(reinterpret_cast<const char*>(&novoRegistro), sizeof(baseDados));

	tamanho++;
	
	cout << "Item adicionado com sucesso!" << endl;
	cout<< "O tamanho atual da base de dados é: " << tamanho << endl;
	arq.seekg(0, std::ios::beg);
		
}

void troca (fstream& arq, int tamanho){
	int p1, p2;
	cout << "Insira as posições dos dados que você deseja trocar (a primeira posição é 0 e a última é " << tamanho-1 << "): ";
	cin >> p1 >> p2;
	cout << endl;
	if (p1>=0 and p1<tamanho and p2>=0 and p2<tamanho and p1!=p2){
		baseDados* aux1 = new baseDados;
		baseDados* aux2 = new baseDados;
		arq.seekg((p1)*sizeof(baseDados), ios::beg);
		arq.read ((char*) aux1, int(sizeof(baseDados)));
		arq.seekg((p2)*sizeof(baseDados), ios::beg);
		arq.read ((char*) aux2, int(sizeof(baseDados)));
		arq.seekp((p1)*sizeof(baseDados), ios::beg);
		arq.write ((char*) aux2, int(sizeof(baseDados)));
		arq.seekp((p2)*sizeof(baseDados), ios::beg);
		arq.write ((char*) aux1, int(sizeof(baseDados)));
		cout << "Troca realizada com sucesso!" << endl;
		cout << "Posição " << p1 << ": " << endl;
		imprime(arq, p1);
		cout << endl << "Posição " << p2 << ": " << endl;
		imprime(arq, p2);
		delete aux1;
		delete aux2;
	}else if (p1>=0 and p1<tamanho and p2>=0 and p2<tamanho and p1==p2){
		cout << "Posições iguais!" << endl;
	}else{
		cout << "Posições inválidas" << endl;
	}
}

void visualizaPosicoes(int x,int y,fstream& arq){
	baseDados* temp = new baseDados;
		for (int i=x; i<=y; i++){
			cout << "Posição: " << i << endl;
			arq.seekg (i*sizeof(baseDados), ios::beg);
			arq.read ((char*) (temp), sizeof(baseDados));
			imprime(arq,i);
			cout << endl;
		}
		delete temp;
}

void alteraElemento(fstream& arq, int tamanho, int x, const baseDados& aux) {
    if (x >= 0 and x < tamanho) {
        arq.seekp(x * sizeof(baseDados), ios::beg);
        arq.write(reinterpret_cast<const char*>(&aux), sizeof(baseDados));
        cout << "Elemento na posição " << x << " alterado com sucesso!" << endl;
    } else {
        cout << "Posição inválida." << endl;
    }
}

int main() {
	fstream arq ("binario.dat", ios::in|ios::ate|ios::out|ios::binary);
	arq.seekg(0, ios::end);
	int tamanho = arq.tellg()/sizeof(baseDados);
	arq.seekg((tamanho-1)*sizeof(baseDados));
	baseDados* teste = new baseDados;
	arq.read ((char*) (teste), sizeof(baseDados));
	if (strlen(teste->referencia)==0 or strlen(teste->periodo)==0){ //Testa se a última linha está em branco
		tamanho--;
	}
	delete teste;
	
	if (arq){
		arq.seekg (0, ios::beg);
		int n; //Variável usada como condição nos blocos condicionais principais.
			
		cout << "Projeto: ESTRUTURA DE DADOS - 2023/2" << endl;
		do{
			cout << "Quantidade de dados: " << tamanho << endl << endl;
			cout << "O que você está buscando?" << endl << "Para adicionar em uma posição específica, digite 1." << endl << "Para visualizar itens especificos da base de dados, digite 2." <<
			endl << "Para alterar algum item da base de dados, digite 3." << endl << "Para realizar uma troca de itens na base de dados, digite 4." << endl << "Para visualizar todos os itens, digite 5"<<endl; //Alterar depois
			cin >> n;
			if (cin.fail()){  
				cin.clear();
				cin.ignore();
			}
			if (n==1){
				cout << "Insira a posição que deseja adicionar novos itens(a primeira posição é 0 e a ultima é" << " " <<tamanho-1 << "):" ;
				int novapos;
					cin>>novapos;
					cin.ignore();
					baseDados novo;
					cout << "Insira a Referência: ";
					cin.getline(novo.referencia,100);
					cout << "Insira o Período: ";
					cin.getline(novo.periodo,100);
					cout << "Insira o Valor: ";
					cin.getline(novo.valor,100);
					cout << "Insira o Status: ";
					cin.getline(novo.status,100);
					cout << "Insira a Unidade: ";
					cin.getline(novo.unidade,100);
					cout << "Insira a Magnitude: ";
					cin.getline(novo.magnitude,100);
					cout<< "Insira o Assunto: ";
					cin.getline(novo.assunto,100);
					cout<< "Insira o Grupo: ";
					cin.getline(novo.grupo,100);
					cout<<"Insira o Título 1: ";
					cin.getline(novo.titulo1,100);
					cout<<"Insira o Título 2: ";
					cin.getline(novo.titulo2,100);
					cout<<"Insira o Título 3: ";
					cin.getline(novo.titulo3,100);
					cout<<"Insira o Título 4: ";
					cin.getline(novo.titulo4,100);
					cout<<"Insira o Título 5: ";
					cin.getline(novo.titulo5,100);
					cout << endl << "Espere um momento..." << endl << endl;
				inserirNaPosicao(arq,tamanho,novapos,novo);
			}
			if(n==2){
				int x,y;
				cout << "Insira a posicao inicial de visualização." << endl;
				cin >> x;
					if(x<0 or x>=tamanho){
						cout << "Posição inválida" << endl;
					}
				cout << "Insira a posição final de visualização." << endl;
				cin >> y;
					if (y<x or y>=tamanho){
							cout << "Posição inválida." << endl;
					}
					if(y==x){
							cout << "As posições inicial e final devem ser diferentes." << endl;
					}
					else{
						visualizaPosicoes(x,y,arq);
						}
					
				}
			if(n==3){
				int x;
				cout << "Em qual posição você deseja fazer a alteração?" << endl;
				cin >> x;
				cin.ignore();
				if(x<0 or x>=tamanho){
					cout << "Posição inválida." << endl;
				}
				else{
				baseDados aux;
					cout << "Insira o novo campo 'Referência'" << endl;
					cin.getline(aux.referencia,100);
					cout << "Insira o novo campo 'Período'" << endl;
					cin.getline(aux.periodo,100);
					cout << "Insira o novo campo 'Valor'" << endl;
					cin.getline(aux.valor,100);
					cout << "Insira o novo campo 'Status'" << endl;
					cin.getline(aux.status,100);
					cout << "Insira o novo campo 'Unidade'" << endl;
					cin.getline(aux.unidade,100);
					cout << "Insira o novo campo 'Magnitude'" << endl;
					cin.getline(aux.magnitude,100);
					cout << "Insira o novo campo 'Assunto'" << endl;
					cin.getline(aux.assunto,100);
					cout << "Insira o novo campo 'Grupo'" << endl;
					cin.getline(aux.grupo,100);
					cout << "Insira o novo campo 'Título 1'" << endl;
					cin.getline(aux.titulo1,100);
					cout << "Insira o novo campo 'Título 2'" << endl;
					cin.getline(aux.titulo2,100);
					cout << "Insira o novo campo 'Título 3'" << endl;
					cin.getline(aux.titulo3,100);
					cout << "Insira o novo campo 'Título 4'" << endl;
					cin.getline(aux.titulo4,100);
					cout << "Insira o novo campo 'Título 5'" << endl;
					cin.getline(aux.titulo5,100);
	
					alteraElemento(arq,tamanho,x,aux);
				}
			}
			
			if (n==4){
				troca (arq, tamanho);
			}
			
			if(n==5){
				visualizaPosicoes(0,tamanho-1,arq);
			}
			cout << "Se você deseja voltar para o menu inicial, digite 1." << endl <<
		"Se desejar fechar o programa, digite qualquer outro número ou letra." << endl;
		cin >> n;
		cout << endl;
		
		}while (n==1);
	}
		
	return 0;
}

