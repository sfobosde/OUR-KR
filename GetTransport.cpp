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
//������� ��� ������ ���� ��������� ���������� ���� ���������� t
void List(struct TRANSPORT* X, char y)
{
	struct TRANSPORT* b;//��������� �� ������ ��� ������ ���������� ��������� ����� ��������
	printf(" �������� ��������� ����������:");
	for (b = X; b->next != NULL; b = b->next)//������� ���� ��������� ������
		if (b->type == y)//���������� ������� ��������� �������� ���� ���������� � ��������� �����
			printf("\nRoute:%d Type:%c Start:%c Finish:%c Time:%d", b->num, b->type, b->start, b->finish, b->time);
}
