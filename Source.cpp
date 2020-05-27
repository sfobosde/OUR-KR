#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "ReadRoutes.h"
#include "GetTransport.h"
#include "Counter.h"
#include "GetMinRoute.h"

using namespace std;//установка простарнства имен

struct TRANSPORT
{
	int num;//поле информации о номере маршрута
	char type;//поле информации о типе маршрута
	char start;//поле информации о начальной точке маршрута
	char finish;//поле информации о конечной точке маршрута
	int time;//поле информации о времени маршрута
	struct TRANSPORT* next;//указатель на следующий элемент списка
};

void ShowAllRoutes(struct TRANSPORT* X);

int main()
{
	setlocale(LC_ALL, "ru");//дл€ использовани€ символов кириллицы

	struct TRANSPORT* X;//указатель на первый элемент списка - указатель всего списка
	char FileName[30] = "Routes_List.txt";//строка с расположением и именем файла
	char t;//переменна€ дл€ вывода маршрутов указанного типа транспорта
	char  a, b;//переменна€ дл€ вывода маршрутов по указанным начальным и конечным точкам маршрута

	GetInfo(&X, FileName);//считывание информации из файла FileName и создание односв€зного списка
	ShowAllRoutes(X);//вывод всех маршрутов из списка на экран пользовател€

	printf("\n ¬ведите тип транспорта:");
	scanf_s("%c", &t);
	List(X, t);//вызов функции дл€ вывода всех маршрутов указанного типа транспорта t

	printf("\n");
	printf("\n ¬ведите начальную точку:");
	cin >> a;
	printf(" ¬ведите конечную точку:");
	cin >> b;
	Cout(X, a, b);//вызов функции дл€ вывода колличества маршрутов по указанным начальным и конечным точкам маршрута a и b

	printf("\n");
	printf("\n ¬ведите начальную точку:");
	cin >> a;
	printf(" ¬ведите конечную точку:");
	cin >> b;
	Min(X, a, b);//вызов функции дл€ вывода минимального маршрута по указанным начальным и конечным точкам маршрута a и b
	return 0;
}


void ShowAllRoutes(struct TRANSPORT* X)
{
	//функци€ выводит все маршруты. служит дл€ проверки организации списка маршрутов
	struct TRANSPORT* prnt;//указатель на список дл€ перебора элементов
	printf("\nAll Routes List:");
	for (prnt = X; prnt->next != NULL; prnt = prnt->next)//перебор всех элементов списка
		printf("\nRoute:%d Type:%c Start:%c Finish:%c Time:%d", prnt->num, prnt->type, prnt->start, prnt->finish, prnt->time);//вывод маршрута
}
