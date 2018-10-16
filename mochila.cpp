#include <iostream>  
#include <algorithm> 
#include <fstream>
#include <stdlib.h>
using namespace std;

/*
	n= NUMERO DE ELEMENTOS
    	M = CAPACIDADE DA MOCHILA
    	peso[] ARRAY COM O PESO DE CADA PRODUTO
	valores[] ARRAY COM O VALOR DE CADA PRODUTO
*/


int MochilaInt(int n, int M, int pesos[], int valores[])
{
    int A[n+1][M+1]; 

   for (int i=0;i<= n;i++)  { 
       for (int j=0;j<=M;j++)   { 
           if (i==0||j==0) A[i][j] = 0; //condição inicial não temos nada na mochila
           else if (pesos[i-1]<=j) A[i][j] = max(A[i-1][j],valores[i-1] + A[i-1][j-pesos[i-1]]); //ainda dá pra add item na mochila 
           																	//temos 2 condiões: ainda tem espaço ou tentamos retirar um item da mochila pra trocar                                                               
           else A[i][j] = A[i-1][j];  //mochila cheia                                                                                               
       }
   }

for(int x = 0; x <= n; x++){ //exibir a tabela preenchida
	for(int z = 0; z <= M; z++){
		printf("%d\t", A[x][z]);
	}
puts("\n");	

}

return A[n][M]; //final da matriz (melhor valor)
}

int main(void)
{   

	int ord[1000000];
	string teste;
	cout << "Arquivo de teste: ";
	cin >> teste;
	ifstream in(teste.c_str());
	char num[10];
	int fim = 0;
	while(!in.eof()){
		in >> num;
		ord[fim] = atoi(num);
		fim++;
	}
	
	int n = ord[0];
	int M = ord[1];
	int pesos[n];
	int valores[n];
	int count = 0;

	for (int i=2; i < 2*n+2; i = i+2)
	{
		pesos[count] = ord[i];
		valores[count] = ord[i+1];
		count++;
	}

    cout << "Valor ótimo: " <<  MochilaInt(n,M,pesos,valores) << endl;
    return 0;
}
