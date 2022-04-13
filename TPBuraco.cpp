#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <iomanip>
#include <locale.h>
using namespace std;

/*N-99-B = Onde:
N  -> Naipe (1-Copas / 2-Paus / 3-Ouro / 4-Espada)
99 -> Número da carta (01-Ás / 13-Rei)
B  -> Baralho (1 ou 2)
11 cartas para 4 jogadores */

int main()
{
	setlocale(LC_ALL, "Portuguese");
	cout << "Projeto Buraco" << endl << endl;

	bool ***carta;

	carta = new bool**[2];

	for(int i = 0; i < 2; i++)
	{
		carta[i] = new bool*[4];

		for(int j = 0; j < 4; j++)
		{
			carta[i][j] = new bool[13];

			for(int k = 0; k < 13; k++)
			{
				carta[i][j][k] = false;
			}
		}
	}

	for (int numJogador = 0; numJogador < 4; numJogador++)
	{
		cout << " Jogador " << numJogador << endl;

		for(int numCarta = 0; numCarta < 12;  numCarta++)
		{
			int baralho;
			int naipe;
			int valorCarta;

			do
			{
				baralho = rand() % ( 2 + 1 - 1) + 0;
				naipe = rand() % ( 4 + 1 - 1) + 0;
				valorCarta = rand() % ( 13 + 1 - 1) + 0;
			}
			while(carta[baralho][naipe][valorCarta]);

			carta[baralho][naipe][valorCarta] = true;

			cout << "  (" << naipe + 1 << "-" << setfill('0') << setw(2) << valorCarta + 1 << "-" << baralho + 1 << ")";
		}
		cout << endl;
	}

	return 0;
}
