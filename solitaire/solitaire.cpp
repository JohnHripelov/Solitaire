#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	char output[2048];
	int code[54], code_service[54], orig[2048], gamma_sequence[2048], gamma, cypher[2048], l, i, j, a[54], b[54], c[54], now, control, jok1, jok2, low, high;
	cout << "Choose the operation: \n 1. Encrypt \n 2. Decrypt" << endl;
	cin >> control;
	cout << endl;

	cout << "Enter code sequence (Clubs = n, diamonds = n+13, hearts = n+26, spades = n+39, jokers - 53 and 54)" << endl;
	for (i = 0; i <= 53; i++)
	{
		cin >> code[i];
	}

	cout << "Enter text (do not use spaces, numbers or any specific letters)" << endl;
	cin.ignore();
	getline(cin, input);
	cout << endl << "Result: " << endl;
	l = input.length();
	
	for (i = 0; i < l; i++) //перевод букв входного текста в числа
	{
		switch (input[i]) 
		{
		case 'a':
			orig[i] = 1;
			break;
		case 'b':
			orig[i] = 2;
			break;
		case 'c':
			orig[i] = 3;
			break;		
		case 'd':
			orig[i] = 4;
			break;
		case 'e':
			orig[i] = 5;
			break;
		case 'f':
			orig[i] = 6;
			break;
		case 'g':
			orig[i] = 7;
			break;
		case 'h':
			orig[i] = 8;
			break;
		case 'i':
			orig[i] = 9;
			break;
		case 'j':
			orig[i] = 10;
			break;
		case 'k':
			orig[i] = 11;
			break;
		case 'l':
			orig[i] = 12;
			break;
		case 'm':
			orig[i] = 13;
			break;
		case 'n':
			orig[i] = 14;
			break;
		case 'o':
			orig[i] = 15;
			break;
		case 'p':
			orig[i] = 16;
			break;
		case 'q':
			orig[i] = 17;
			break;
		case 'r':
			orig[i] = 18;
			break;
		case 's':
			orig[i] = 19;
			break;
		case 't':
			orig[i] = 20;
			break;
		case 'u':
			orig[i] = 21;
			break;
		case 'v':
			orig[i] = 22;
			break;
		case 'w':
			orig[i] = 23;
			break;
		case 'x':
			orig[i] = 24;
			break;
		case 'y':
			orig[i] = 25;
			break;
		case 'z':
			orig[i] = 26;
			break;
		}
	}

	for (j = 0; j < l; j++) //генерация гамм
	{
		do
		{
			i = 0; //обработка первого джокера
			for (i = 0; i < 54; i++)
			{
				now = code[i];
				code_service[i] = now;
				if (now == 53)
				{
					code_service[i] = code[i + 1];
					code_service[i + 1] = 53;
					jok1 = i + 1;
					i++;
				}
				if (i == 53 && now == 53)
				{
					code_service[53] = code_service[0];
					code_service[0] = 53;
					jok1 = 0;
				}
			}
			for (i = 0; i < 54; i++)
			{
				code[i] = code_service[i];
			}

			for (i = 0; i < 54; i++)
			{
				now = code[i];
				code_service[i] = now;
				if (now == 54)
				{
					code_service[i] = code[i + 1];
					code_service[i + 1] = code[i + 2];
					code_service[i + 2] = 54;
					jok2 = i + 2;
					i = i + 2;
				}
				if (now == 54 && i == 53)
				{
					code_service[53] = code[0];
					code_service[0] = code[1];
					code_service[1] = 54;
					jok2 = 1;
					i = 54;
				}
				if (now == 54 && i == 52)
				{
					code_service[52] = code[53];
					code_service[53] = code[0];
					code_service[0] = 54;
					jok2 = 0;
					i = 54;
				}
			}
			for (i = 0; i < 54; i++)
			{
				code[i] = code_service[i];
			}

			if (jok2 < jok1) //"тройной разрез"
			{
				int g = jok1;
				jok1 = jok2;
				jok2 = g;
			}
			
			for (i = 0; i < 54; i++)
			{
				a[i] = 0;
				b[i] = 0;
				c[i] = 0;
			}

			int g = 0;

			for (i = 0; i < jok1; i++)
			{ 
				a[i] = code[i];
			}
			for (i = jok1; i <= jok2; i++)
			{
				b[g] = code[i];
				g++;
			}
			g = 0;
			for (i = jok2+1; i < 54; i++)
			{
				c[g] = code[i];
				g++;
			}
			
			i = 0;
			do 
			{
				code_service[i] = c[i];
				i++;
			} while (c[i] != 0);
			g = 0;
			do
			{
				code_service[i] = b[g];
				i++;
				g++;
			} while (b[g] != 0);
			g = 0;
			do 
			{
				code_service[i] = a[g];
				i++;
				g++;
			} while (a[g] != 0);
			
			for (i = 0; i < 54; i++)
			{
				code[i] = code_service[i];
			}

			now = 52; //перенос части колоды вниз
			low = code[53];
			if (code[53] == 54)
			{
				low = 53;
			}
			for (i = low - 1; i >= 0; i--)
			{
				code_service[now] = code[i];
				now--;
			}
			for (i = 52; i <= low; i--)
			{
				code_service[now] = code[i];
				now--;
			}
			for (i = 0; i <= 53; i++)
			{
				code[i] = code_service[i];
				if (code[i] == 54)
				{
					code[i] = 53;
				}
			}

			high = code[0]; //нахождение гаммы

		} while (code[high] == 53);

		if (code[high] >= 27 && code[high] <= 52)
		{
			gamma = code[high] - 26;
		}
		else
		{
			gamma = code[high];
		}
		gamma_sequence[j] = gamma;
	}

	switch (control) //формирование шифротекста
	{
	default:
		cout << "Error" << endl;
		break;
	case 1:
		for (i = 0; i < l; i++)
		{
			cypher[i] = orig[i] + gamma_sequence[i];
			if (cypher[i] > 26)
			{
				cypher[i] -= 26;
			}
		}
		break;
	case 2:
		for (i = 0; i < l; i++)
		{
			cypher[i] = orig[i] - gamma_sequence[i];
			if (cypher[i] <= 0)
			{
				cypher[i] += 26;
			}
		}
		break;
	}

	for (i = 0; i < l; i++) //перевод шифротeкста в буквенный вид
	{
		switch (cypher[i])
		{
		case 1:
			output[i] = 'a';
			break;
		case 2:
			output[i] = 'b';
			break;
		case 3:
			output[i] = 'c';
			break;
		case 4:
			output[i] = 'd';
			break;
		case 5:
			output[i] = 'e';
			break;
		case 6:
			output[i] = 'f';
			break;
		case 7:
			output[i] = 'g';
			break;
		case 8:
			output[i] = 'h';
			break;
		case 9:
			output[i] = 'i';
			break;
		case 10:
			output[i] = 'j';
			break;
		case 11:
			output[i] = 'k';
			break;
		case 12:
			output[i] = 'l';
			break;
		case 13:
			output[i] = 'm';
			break;
		case 14:
			output[i] = 'n';
			break;
		case 15:
			output[i] = 'o';
			break;
		case 16:
			output[i] = 'p';
			break;
		case 17:
			output[i] = 'q';
			break;
		case 18:
			output[i] = 'r';
			break;
		case 19:
			output[i] = 's';
			break;
		case 20:
			output[i] = 't';
			break;
		case 21:
			output[i] = 'u';
			break;
		case 22:
			output[i] = 'v';
			break;
		case 23:
			output[i] = 'w';
			break;
		case 24:
			output[i] = 'x';
			break;
		case 25:
			output[i] = 'y';
			break;
		case 26:
			output[i] = 'z';
			break;
		}
	}
	cout << endl;
	for (i = 0; i < l; i++)
	{
		cout << output[i]; //вывод шифротекста
	}
	cout << endl;
	system("pause");
}