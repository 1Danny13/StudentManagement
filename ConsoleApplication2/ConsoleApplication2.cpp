// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include "Header.h"
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	Systemdoor();
	int x = 100, pnum, pmath, peng, pyuwen;
	StuNode *pfind;
	SInfo stu;
	cout << "   ------   ��ӭ����ѧ����Ϣ����ϵͳ   ------" << endl;
	while (x != 0)
	{
		system("pause");
	    //system("CLS")    //����
		ShowMenu();
		cin >> x;
		switch (x)
		{
		case 0:
			stu.StuQuit();
			break;
		case 1:
			stu.StuRead();
			cout << "����ѧ����Ϣ��" << endl;
			stu.ShowInfo();
			break;
		case 2:
			stu.CreatSinfo();
			cout << "��˶�ѧ����Ϣ��" << endl;
			stu.ShowInfo();
			break;
		case 3:
			cout << "�����ѧ����Ϣ��";
			cin >> pnum >> pmath >> peng >> pyuwen;
			stu.StuInsert(pnum, pmath, peng, pyuwen);
			cout << "����ѧ����Ϣ��" << endl;
			stu.ShowInfo();
			break;
		case 4:
			cout << "������Ҫɾ��ѧ��ѧ�ţ�";
			cin >> pnum;
			stu.StuDelete(pnum);
			cout << "����ѧ����Ϣ��" << endl;
			stu.ShowInfo();
			break;
		case 5:
			cout << "������Ҫ����ѧ��ѧ�ţ�";
			cin >> pnum;
			pfind = stu.StuFind(pnum);
			cout << "����ѧ��ѧ�ţ�" << pfind->num << " ��ѧ " << pfind->math << " Ӣ�� " << pfind->eng << " ���� " << pfind->yuwen << " �ܷ� " << pfind->sum << endl;
			break;
		case 6:
			cout << "������Ҫ�޸�ѧ��ѧ�ţ�";
			cin >> pnum;
			cout << "����������ѧ��������";
			cin >> pmath >> peng >> pyuwen;
			stu.StuModify(pnum, pmath, peng, pyuwen);
			cout << "�޸ĳɹ���" << endl;
			cout << "����ѧ����Ϣ��..." << endl;
			stu.ShowInfo();
			break;
		case 7:
			cout << "����1������0��ѧ������10����";
			cin >> pnum;
			if (pnum == 1)
			{
				stu.StuSort('<');
				stu.ShowInfo();
			}
			else if (pnum == 0)
			{
				stu.StuSort('>');
				stu.ShowInfo();
			}
			else if (pnum == 10)
			{
				stu.StuSort('o');
				stu.ShowInfo();
			}
			else
			{
				cout << "�������" << endl;
			}
			break;
		case 8:
			stu.StuClassfy();
			break;
		case 9:
			stu.ShowInfo();
			break;
		case 10:
			stu.StuSave();
			break;
		}
	}

	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
