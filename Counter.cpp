#include "Counter.h"
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
//функция для вывода колличества маршрутов по указанным начальным и конечным точкам маршрута s и f
void Cout(TRANSPORT* X, char s, char f)
{
	struct TRANSPORT* prnt;//указатель на список для поиска подходящих элементов путем перебора
	int k = 0;//счетчик колличества маршрутов
	for (prnt = X; prnt->next != NULL; prnt = prnt->next)//перебор всех элементов списка
		if (prnt->start == s && prnt->finish == f)//выполнения условия совпадения начальной и конечной точки
			k++;//считаем колличество маршрутов +1

	printf("Количество маршрутов:%d", k);
}
