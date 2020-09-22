// progr1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <Conio.h>
#include<Windows.h>
#include<String.h>
void init();// ������� �������������
void OutputCars();// ������� ������ ������
void PutCars();// ������� ����� ������
void AddCars();// ������� ���������� ������
int zashita(char putt[]);// ������� ��� ������ �� ����
void SellCars();// ������� �������� ������
void NewPrice();// ������� ��������� ����
void SumCars();// ������� �������� ���� ����
typedef struct
{
	char name[20];// ����� ����
	char color[20];// ���� ����
	int year;// ��� �������
	double price;// ����
}cars;// ��������� ������
cars car[20];// ������ �����
int n;// ���-�� �����
void init()// ������� �������������
{
	car[0] = { "Toyota", "������", 2020, 2000000 };
	car[1] = { "BMW", "�����", 2020, 1000000 };
	car[2] = { "LADA", "�������", 2020, 500000 };
	n = 3;
	printf("������ �����������������\n\n");
	printf("��� ����������� ������� ����� �������.");
	getch();

}
void OutputCars()// ������� ������ ������
{
	system("cls");
	if (n != 0)
	{
		printf("*******************************************************\n");
		printf("*�����*    �����   *   ����   *    ���   *    ����    *\n");
		printf("*******************************************************\n");
		for (int i = 0; i < n; i++)
		{
			printf("*%5d*%12s*%10s*%10d*%12.2lf*\n", i + 1, car[i].name, car[i].color, car[i].year, car[i].price);
			printf("*     *            *          *          *            *\n");
			if (i != n - 1)printf("*******************************************************\n");
		}
		printf("*******************************************************\n\n");
	}
	else
	{
		printf("\n������ ����� ����, ������� ������");
		getch();
	}
}
void PutCars()// ������� ����� ������
{
	char putt[20];// ��� ������
	int f;// ������ ��� �������� �� �����
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		fflush(stdin);
		printf("  ������ ����� %d\n\n", i + 1);
		printf(" ����� ������: ");
		gets(car[i].name);
		fflush(stdin);
		printf(" ���� ������: ");
		gets(car[i].color);
		do{
			printf(" ��� ������� ������: ");
			fflush(stdin);
			gets_s(putt);
			fflush(stdin);
			f = zashita(putt);// �������� �� �����
			if (f) { printf("\n��� ������� ������ ��������� ������ �����, ���������� ��� ���\n"); }
		} while (f);
		car[i].year = atoi(putt);// ������� ������ � int
		for (int k = 0; k < 20; k++)
			putt[k] = '\0';// ������� �������
		do{
			printf(" ����: ");
			fflush(stdin);
			gets_s(putt);
			fflush(stdin);
			f = zashita(putt);
			if (f) { printf("\n���� ������ ��������� ������ �����, ���������� ��� ���\n"); }
		} while (f);
		car[i].price = atof(putt);// ������� ������ � double
		for (int k = 0; k < 20; k++)
			putt[k] = '\0';
		system("cls");
	}

}
void AddCars()// ������� ���������� ������
{
	system("cls");
	char putt[20];// ��� ������
	int f;// ������ ��� �������� ������ �� �����
	do
	{
		if (n > 20)
		{
			printf("���������� ������������ ���-�� �����\n");
			printf("���� �������, ��� ����������� ������� ����� �������\n");
			_getch();
			break;
		}
		system("cls");
		fflush(stdin);
		printf("  ������ ����� %d\n\n", n + 1);
		printf(" ����� ������: ");
		gets(car[n].name);
		fflush(stdin);
		printf(" ���� ������: ");
		gets(car[n].color);
		do{
			printf(" ��� ������� ������: ");
			fflush(stdin);
			gets_s(putt);
			fflush(stdin);
			f = zashita(putt);// �������� �� �����
			if (f) { printf("\n��� ������� ������ ��������� ������ �����, ���������� ��� ���\n"); }
		} while (f);
		car[n].year = atoi(putt);// ������� ������ � int
		for (int i = 0; i < 20; i++)
			putt[i] = '\0';// ������� �������
		do{
			printf(" ����: ");
			fflush(stdin);
			gets_s(putt);
			fflush(stdin);
			f = zashita(putt);
			if (f) { printf("\n���� ������ ��������� ������ �����, ���������� ��� ���\n"); }
		} while (f);
		car[n].price = atof(putt);
		for (int i = 0; i < 20; i++)
			putt[i] = '\0';
		n++;
		printf("���������� ����? ��� - Esc; �� - ����� �������\n");
	} while (_getch() != 27);
	system("cls");
}
int zashita(char putt[])
{
	int f1;// ������ ��� �������� ���� � ������
	f1 = 0;
	for (int i = 0; putt[i] != '\0'; i++)
	{
		if ((putt[i]<48 || putt[i]>57) && putt[i] != 46 && putt[i] != 43 && putt[i] != 32) { f1 = 1; break; }// ������� ���������� "�������" �������
	}
	return f1;
}

void SellCars()// ������� �������� ������
{
	int number;// ����� ��������� ������
	OutputCars();// ����� ������� ������ ������
	do{
		printf("\n ������� ����� ��������� ������: ");
		scanf("%d", &number);
		if (number<1 || number>n)printf("\n������ ������������ �����, ���������� ��� ���\n");
	} while (number<1 || number>n);
	for (int i = number; i < n; i++)// ����� �������
	{
		car[i - 1] = car[i];
	}
	n--;// ���������� ���-�� �����
	printf("\n ������ ������� �������, ��� ����������� ������� ����� �������");
	getch();
}
void NewPrice()// ������� ��������� ����
{
	char putt[20];// ��� ������
	int number;// ����� ������, � ������� �������� ����
	int f;// ������ ��� �������� �� �����
	OutputCars();// ������� ������
	do{
		printf("\n ������� ����� ������: ");
		scanf("%d", &number);
		if (number<0 || number>n) printf("������ ������������ �����, ���������� ��� ���\n");
	} while (number<0 || number>n);
	do{
		printf(" ����� ����: ");
		fflush(stdin);
		gets_s(putt);
		fflush(stdin);
		f = zashita(putt);// ������ �� "������"
		if (f) { printf("\n���� ������ ��������� ������ �����, ���������� ��� ���\n"); }
	} while (f);
	car[number - 1].price = atof(putt);// ������� ������ � double
	for (int i = 0; i < 20; i++)
		putt[i] = '\0';// ������� �������
	printf("\n���� ������� ��������, ��� ����������� ������� ����� ��������");
	getch();
}
void  SumCars()// ������� �������� ���� ����
{
	int f;// ������ ��� ������ �� ����
	int count;// ���-�� ������������ �����
	int Number[20];// ������ ������� �����
	char *ptr;// ��������� �� ������
	char str[50];// ������� ������
	double sum;// ������� �����
	bool f1 = false;// ������ ��� ������ �� ������������� �����
	OutputCars();// ����� ������
	do{
		f1 = false;
		do{
			printf("\n������� ����� ������ ������ �����, ���� ������� ���������� �������:\n");
			fflush(stdin);
			gets(str);
			fflush(stdin);
			f = zashita(str);
			if (f) {
				printf("\n������� ������������ �������� ��� ������ ������, ���������� ��� ���\n");
				for (int k = 0; k < 50; k++)
					str[k] = '\0';
			}
		} while (f);
		ptr = strtok(str, " ");// �������� ������ ������� �� �����
		count = 0;// ��������� ���-�� �������
		while (ptr != NULL)
		{
			Number[count] = atoi(ptr);// ������� ������ � int
			ptr = strtok(NULL, " ");
			count++;
		}
		for (int i = 0; i < count; i++)
		{
			if (Number[i]<1 || Number[i]>n) f1 = true;// �������� �� ������������ ����
		}
		if (count<2 || count>n || f1){ printf("\n������� ������������ ��������, ���������� ��� ���\n"); }
	} while (count<2 || count>n || f1);
	sum = 0;// ��������� �����
	for (int i = 0; i < count; i++)
	{
		sum += car[Number[i] - 1].price;
	}
	system("cls");
	OutputCars();
	printf("��������� ����� ��� ������� ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", Number[i]);// ����� �����
	}
	printf("�����: %.3lf ������\n\n", sum);
	printf("��� ����������� ������� ����� �������.");
	getch();
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// ����������� �������������� �����/������
	SetConsoleOutputCP(1251);
	system("Color F0");
	init();
	char cas;// ����� ������������
	do{
		system("cls");
		printf("  �������� ��������:\n\n");
		printf(" 1 - ������ ������\n");
		printf(" 2 - ����� ������\n");
		printf(" 3 - �������� ������\n");
		printf(" 4 - ������� ������\n");
		printf(" 5 - �������� ���� ������\n");
		printf(" 6 - ��������� ��������� ���������� �����\n");
		printf(" 0 - ����� �� ���������\n");
		bool f;// ������ ��� �������� �� ������������ ����
		do{
			f = true;
			cas = _getch();
			switch (cas)
			{
			case '1': PutCars(); break;
			case '2': OutputCars(); printf("��� ����������� ������� ����� �������."); getch(); break;
			case '3': AddCars(); break;
			case '4': SellCars(); break;
			case '5': NewPrice(); break;
			case '6': SumCars(); break;
			case '0': break;
			default: printf("������ �������� ���, ���������� ��� ���\n"); f = false; break;
			}
		} while (!f);
	} while (cas != '0');
	return 0;
}

