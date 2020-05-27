#include "ReadRoutes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct TRANSPORT
{
	int num;
	char type;
	char start;
	char finish;
	int time;
	struct TRANSPORT *next;
};
//функция считывания информации из файла FileName и создание односвязного списка
void GetInfo(struct TRANSPORT** X, char FileName[30])
{
	FILE* Route_List;//указатель на файл
	*X = NULL;//установка указателю списка значение пустой ссылки
	char RouteInfo[42];//поле для хранения информации о считанной строке из файла
	if (fopen_s(&Route_List, FileName, "r") != 0)//проверка наличия файла
		printf("\nRote file didn`t exists");//файл не найден
	else//файл найден
	{
		while (fgets(RouteInfo, 42, Route_List) != NULL)//считвание информации из файла построчно до конца файла
		{
			struct TRANSPORT *pt;//создание элемента структуры 
			pt = (struct TRANSPORT*) malloc(sizeof(struct TRANSPORT));//выделение памяти под новый элемент
			pt->num = (RouteInfo[6] - 48) * 10 + (RouteInfo[7] - 48);//установка формата int для поля информации о номере и запись полученного значения
			pt->type = RouteInfo[14];//запись информации о типе маршрута
			pt->start = RouteInfo[22];//запись информации о начальной точке маршрута
			pt->finish = RouteInfo[31];//запись информации о конечной точке маршрута
			pt->time = (RouteInfo[38] - 48) * 10 + (RouteInfo[39] - 48);//установка формата int для поля информации о времени маршрута и запись полученного значения
			//"присоединение" элемента к списку
			pt->next = *X;
			*X = pt;			
		}
	}
	fclose(Route_List);//закрываем файл по достижению конца
}