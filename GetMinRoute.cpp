#include "GetMinRoute.h"
#include <stdio.h>

struct TRANSPORT
{
	int num;
	char type;
	char start;
	char finish;
	int time;
	struct TRANSPORT* next;
};
//функция выводы информации о наилучшем маршруте по указанным начальным и конечным точкам
void Min(struct TRANSPORT* X, char s, char f)
{
	struct TRANSPORT *search, *BestRoute;//указатель на список для поиска подходящих элементов путем перебора и указатель на элемент списка
	search = X;//устанавливаем указатель на первый элемент
	BestRoute = NULL;//инициализируем буферную переменную-указатель пустой ссылкой
	for (; search != NULL; search = search->next)//перебор всех элементов списка
		if (search->start == s && search->finish == f)//выполнения условия совпадения начальной и конечной точки
			if (BestRoute == NULL)//первая проверка совпадения 
				BestRoute = search;//установка указателя на текущий элемент
			else if ((search->time) < (BestRoute->time))//сравнение времен известного элемента с текущим
				BestRoute = search;//установка указателя на текущий элемент
	if (BestRoute)//элемент найден
		printf("\nBest Route from %c to %c:\nRoute:%d Time:%d.", s, f, BestRoute->num, BestRoute->time);
	else
		printf("\nNo such routes.");//таких маршрутов не существует в списке
}