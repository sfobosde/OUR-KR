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
	struct TRANSPORT* next;
};
//функция для вывода всех маршрутов указанного типа транспорта t
void List(struct TRANSPORT* X, char y)
{
	struct TRANSPORT* b;//указатель на список для поиска подходящих элементов путем перебора
	printf(" Маршруты заданного транспорта:");
	for (b = X; b->next != NULL; b = b->next)//перебор всех элементов списка
		if (b->type == y)//выполнение условия совпадния значения типа транспорта с указанным типом
			printf("\nRoute:%d Type:%c Start:%c Finish:%c Time:%d", b->num, b->type, b->start, b->finish, b->time);
}
