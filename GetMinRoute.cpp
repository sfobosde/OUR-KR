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
//������� ������ ���������� � ��������� �������� �� ��������� ��������� � �������� ������
void Min(struct TRANSPORT* X, char s, char f)
{
	struct TRANSPORT *search, *BestRoute;//��������� �� ������ ��� ������ ���������� ��������� ����� �������� � ��������� �� ������� ������
	search = X;//������������� ��������� �� ������ �������
	BestRoute = NULL;//�������������� �������� ����������-��������� ������ �������
	for (; search != NULL; search = search->next)//������� ���� ��������� ������
		if (search->start == s && search->finish == f)//���������� ������� ���������� ��������� � �������� �����
			if (BestRoute == NULL)//������ �������� ���������� 
				BestRoute = search;//��������� ��������� �� ������� �������
			else if ((search->time) < (BestRoute->time))//��������� ������ ���������� �������� � �������
				BestRoute = search;//��������� ��������� �� ������� �������
	if (BestRoute)//������� ������
		printf("\nBest Route from %c to %c:\nRoute:%d Time:%d.", s, f, BestRoute->num, BestRoute->time);
	else
		printf("\nNo such routes.");//����� ��������� �� ���������� � ������
}