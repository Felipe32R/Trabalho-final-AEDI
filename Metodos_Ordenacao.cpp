#include <iostream>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <time.h>


using namespace std;

void SELECIONE(int X[], int N);
void INSERCAO (int X[], int N);
void BOLHA (int X[], int N);
void QUICK (int X[], int I, int N);
void HEAP(int X[], int N);
void SHELL(int X[] , int N);

int main()
{
setlocale (LC_ALL, "Portuguese");							
int N, Z, P=0;
N = 10000;						// Onde N é o tamanho do vetor.
int A, B, OP, X[N];				// Onde A e B são índices, OP para o Switch e X[N] é o vetor onde serão gravados os números para ordenação.
clock_t inicio, fim;
float tempo;	
		
	
	
	
	do
	{
		system("cls");
		
		for (A=0; A<N; A++)
		X[A] = rand();
		
		for (int C=0; C<N; C++){
		cout << " " << X[C] << "\t";
		Z++;
			if (Z == 10){
				cout << endl;
				Z = 0;
			}
		}
	cout << endl << endl;
		
	cout << "\t\t\t\t" << "Escolha a opção de ordenação para o vetor: " << "\n" << " \t1 - Selectionsort;\n \t2 - Insertionsort;\n"
		 << " \t3 - Bubblesort;\n \t4 - Quicksort;\n \t5 - Heapsort; \n \t6 - Shellsort. \n ";
	cin >> OP;
	
	
	
	switch (OP)
	{
			case 1:
				inicio = clock();
				SELECIONE (X,N);
				fim = clock();
				tempo = fim - inicio;
				cout << endl << " " << tempo / 1000.0 << " segundos.";
				break;
			case 2:
				inicio = clock();
				INSERCAO (X, N);
				fim = clock();
				tempo = fim - inicio;
				cout << endl << " " << tempo / 1000.0 << " segundos.";
				break;	
			case 3:
				inicio = clock();
				BOLHA (X, N);
				fim = clock();
				tempo = fim - inicio;
				cout << endl << " " << tempo / 1000.0 << " segundos.";
				break;
			case 4:
				inicio = clock();
				QUICK (X, 0, N);
				Z = 0;
				for (int C=0; C<N; C++){
					cout << " " << X[C] << "\t";
					Z++;
					
					if (Z == 10){
						cout << endl;
						Z = 0;
					}
				}
				fim = clock();
				tempo = fim - inicio;
				cout << endl << " " << tempo / 1000.0 << " segundos.";
				break;
            case 5:
            	tempo = clock();
                HEAP (X, N);
                Z = 0;
				  for (int C=0; C<N; C++){
				      cout << " " << X[C] << "\t";
					  Z++;
					
					  if (Z == 10){
					     cout << endl;
						 Z = 0;
					}
				}
				fim = clock();
				tempo = fim - inicio;
				cout << endl << " " << tempo / 1000.0 << " segundos.";
                break;
			case 6:
				tempo = clock();
				SHELL (X, N);
				fim = clock();
				tempo = fim - inicio;
				for (int C=0; C<N; C++){
				      cout << " " << X[C] << "\t";
					  Z++;
					
					  if (Z == 10){
					     cout << endl;
						 Z = 0;
					}
				}
				cout << endl << " " << tempo / 100.0 << " segundos.";
				break;
	}		
	
	cout << "\n\n\tDeseja ordenar por outro método?\n\t1 - Sim\n\t2 - não.\n";
	cin >> P;
	
	}while(P==1);

getch();
}


void SELECIONE (int X[], int N) //N -> Tamanho do vetor
{
int AA, BB, MV, AUX, Z;			// AA e BB são índices, MV (Menor valor) é a variável que guardará o menor valor em comparação.
Z = 0;

	    for (AA=0; AA<N ; AA++) 
		{
    		int MV = AA;
       			for (BB=AA+1; BB<N; BB++) 
				{
        			if (X[BB] < X[MV]) 
					{
        		 		MV = BB;
        			}
        		}
        	AUX = X[AA];
       		X[AA] = X[MV];
        	X[MV] = AUX;    	    	
    	}
	for (int C=0; C<N; C++){
		cout << " " << X[C] << "\t";
		Z++;
			if (Z == 10){
				cout << endl;
				Z = 0;
			}
	}
}


void INSERCAO (int X[], int N)		
{
int AA, BB, MV, AUX, Z;
AA = 0;
BB = 1;
AUX = 0;
Z = 0;

	while (BB < N)
	{
		AUX = X[BB];
		AA = BB - 1;
			while ((AA>=0) && (X[AA] > AUX))
			{
				X[AA+1] = X[AA];
				AA = AA - 1;
			}
		X[AA+1] = AUX;
		BB = BB + 1;	
	}
		
	for (int C=0; C<N; C++){
		cout << " " << X[C] << "\t";
		Z++;
			if (Z == 10){
				cout << endl;
				Z = 0;
			}
	}		
}


void BOLHA (int X[], int N)
{
int AA, BB, AUX, Z;
Z = 0;

	for (AA= N-1; AA>0; --AA) { 
		for (BB = 0; BB < AA; ++BB) { 
			if (X[BB] > X[BB+1]) { 
				AUX = X[BB]; 
				X[BB] = X[BB+1]; 
				X[BB+1] = AUX; 
			} 
		}  
	}
	for (int C=0; C<N; C++){
		cout << " " << X[C] << "\t";
		Z++;
			if (Z == 10){
				cout << endl;
				Z = 0;
			}
	}
}


void QUICK(int X[], int I , int N)   // N = final ou end
{
	int AA, BB, ESC, AUX, Z;		// ESC = Pivot
	AA = I;
	BB = N-1;
	ESC = X[(I + N) / 2];
	Z = 0;
	
	while(AA <= BB){
		while(X[AA] < ESC && AA < N)
			AA++;
		
		while(X[BB] > ESC && BB > I)
			BB--;
		
		if(AA <= BB){
			AUX = X[AA];
			X[AA] = X[BB];
			X[BB] = AUX;
			AA++;
			BB--;
		}
	}
	if(I < BB)
		QUICK(X, I, BB+1);
	if(AA < N)
		QUICK(X, AA, N);
}


void HEAP(int X[], int N) 
{
   int AA = N / 2, PAI, FILHO, T;
   while(true) {
      if (AA > 0) {
          AA--;
          T = X[AA];
      } 
      else {
          N--;
          if (N <= 0) return;
          T = X[N];
          X[N] = X[0];
      }
      PAI = AA;
      FILHO = AA * 2 + 1;
      while (FILHO < N) {
          if ((FILHO + 1 < N)  &&  (X[FILHO + 1] > X[FILHO]))
              FILHO++;
          if (X[FILHO] > T) {
             X[PAI] = X[FILHO];
             PAI = FILHO;
             FILHO = PAI * 2 + 1;
          } 
          else {
             break;
          }
      }
      X[PAI] = T;
   }
}   


void SHELL(int X[] , int N) {
    int AA , BB , AUX;
 
    int h = 1;
    while(h < N) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(AA= h; AA < N; AA++) {
            AUX = X[AA];
            BB = AA;
            while (BB > h-1 && AUX <= X[BB - h]) {
                X[BB] = X [BB - h];
                BB = BB - h;
            }
            X [BB] = AUX;
        }
        h = h/3;
    }
}











