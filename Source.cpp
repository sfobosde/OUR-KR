#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "ReadRoutes.h"
#include "GetTransport.h"
#include "Counter.h"
#include "GetMinRoute.h"

using namespace std;//��������� ������������ ����

struct TRANSPORT
{
	int num;//���� ���������� � ������ ��������
	char type;//���� ���������� � ���� ��������
	char start;//���� ���������� � ��������� ����� ��������
	char finish;//���� ���������� � �������� ����� ��������
	int time;//���� ���������� � ������� ��������
	struct TRANSPORT* next;//��������� �� ��������� ������� ������
};

void ShowAllRoutes(struct TRANSPORT* X);

int main()
{
	setlocale(LC_ALL, "ru");//��� ������������� �������� ���������

	struct TRANSPORT* X;//��������� �� ������ ������� ������ - ��������� ����� ������
	char FileName[30] = "Routes_List.txt";//������ � ������������� � ������ �����
	char t;//���������� ��� ������ ��������� ���������� ���� ����������
	char  a, b;//���������� ��� ������ ��������� �� ��������� ��������� � �������� ������ ��������

	GetInfo(&X, FileName);//���������� ���������� �� ����� FileName � �������� ������������ ������
	ShowAllRoutes(X);//����� ���� ��������� �� ������ �� ����� ������������

	printf("\n ������� ��� ����������:");
	scanf_s("%c", &t);
	List(X, t);//����� ������� ��� ������ ���� ��������� ���������� ���� ���������� t

	printf("\n");
	printf("\n ������� ��������� �����:");
	cin >> a;
	printf(" ������� �������� �����:");
	cin >> b;
	Cout(X, a, b);//����� ������� ��� ������ ����������� ��������� �� ��������� ��������� � �������� ������ �������� a � b

	printf("\n");
	printf("\n ������� ��������� �����:");
	cin >> a;
	printf(" ������� �������� �����:");
	cin >> b;
	Min(X, a, b);//����� ������� ��� ������ ������������ �������� �� ��������� ��������� � �������� ������ �������� a � b
	return 0;
}


void ShowAllRoutes(struct TRANSPORT* X)
{
	//������� ������� ��� ��������. ������ ��� �������� ����������� ������ ���������
	struct TRANSPORT* prnt;//��������� �� ������ ��� �������� ���������
	printf("\nAll Routes List:");
	for (prnt = X; prnt->next != NULL; prnt = prnt->next)//������� ���� ��������� ������
		printf("\nRoute:%d Type:%c Start:%c Finish:%c Time:%d", prnt->num, prnt->type, prnt->start, prnt->finish, prnt->time);//����� ��������
}
