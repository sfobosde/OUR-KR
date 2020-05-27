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
//������� ���������� ���������� �� ����� FileName � �������� ������������ ������
void GetInfo(struct TRANSPORT** X, char FileName[30])
{
	FILE* Route_List;//��������� �� ����
	*X = NULL;//��������� ��������� ������ �������� ������ ������
	char RouteInfo[42];//���� ��� �������� ���������� � ��������� ������ �� �����
	if (fopen_s(&Route_List, FileName, "r") != 0)//�������� ������� �����
		printf("\nRote file didn`t exists");//���� �� ������
	else//���� ������
	{
		while (fgets(RouteInfo, 42, Route_List) != NULL)//��������� ���������� �� ����� ��������� �� ����� �����
		{
			struct TRANSPORT *pt;//�������� �������� ��������� 
			pt = (struct TRANSPORT*) malloc(sizeof(struct TRANSPORT));//��������� ������ ��� ����� �������
			pt->num = (RouteInfo[6] - 48) * 10 + (RouteInfo[7] - 48);//��������� ������� int ��� ���� ���������� � ������ � ������ ����������� ��������
			pt->type = RouteInfo[14];//������ ���������� � ���� ��������
			pt->start = RouteInfo[22];//������ ���������� � ��������� ����� ��������
			pt->finish = RouteInfo[31];//������ ���������� � �������� ����� ��������
			pt->time = (RouteInfo[38] - 48) * 10 + (RouteInfo[39] - 48);//��������� ������� int ��� ���� ���������� � ������� �������� � ������ ����������� ��������
			//"�������������" �������� � ������
			pt->next = *X;
			*X = pt;			
		}
	}
	fclose(Route_List);//��������� ���� �� ���������� �����
}