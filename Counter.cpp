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
//������� ��� ������ ����������� ��������� �� ��������� ��������� � �������� ������ �������� s � f
void Cout(TRANSPORT* X, char s, char f)
{
	struct TRANSPORT* prnt;//��������� �� ������ ��� ������ ���������� ��������� ����� ��������
	int k = 0;//������� ����������� ���������
	for (prnt = X; prnt->next != NULL; prnt = prnt->next)//������� ���� ��������� ������
		if (prnt->start == s && prnt->finish == f)//���������� ������� ���������� ��������� � �������� �����
			k++;//������� ����������� ��������� +1

	printf("���������� ���������:%d", k);
}
