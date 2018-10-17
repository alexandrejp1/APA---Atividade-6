#include <iostream>  
#include <algorithm> 
#include <fstream>
#include <stdlib.h>
using namespace std;

#include <sys/time.h>  //libs pra stack memory
#include <sys/resource.h>
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

   	cout << pesos[i] << endl; 
    
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

int main(void){   

	const rlim_t kStackSize = 64L * 1024L * 1024L;   // min stack size = 64 Mb
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }



	int ord[1000000];
	string teste;
	cout << "Digite o arquivo de teste, exemplo: 'mochila01.txt'" << endl;
	cin >> teste;
	ifstream in(teste.c_str());
	char num[1000000];
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
	int j = 0;

	for (int i=2; i < 2*n+2; i = i+2){
		pesos[j] = ord[i];
		valores[j] = ord[i+1];
		j++;
	}

    cout << "Valor ótimo: " <<  MochilaInt(n,M,pesos,valores) << endl;
    return 0;








}
