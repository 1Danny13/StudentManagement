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
	cout << "   ------   欢迎进入学生信息管理系统   ------" << endl;
	while (x != 0)
	{
		system("pause");
	    //system("CLS")    //清屏
		ShowMenu();
		cin >> x;
		switch (x)
		{
		case 0:
			stu.StuQuit();
			break;
		case 1:
			stu.StuRead();
			cout << "读入学生信息：" << endl;
			stu.ShowInfo();
			break;
		case 2:
			stu.CreatSinfo();
			cout << "请核对学生信息！" << endl;
			stu.ShowInfo();
			break;
		case 3:
			cout << "请添加学生信息：";
			cin >> pnum >> pmath >> peng >> pyuwen;
			stu.StuInsert(pnum, pmath, peng, pyuwen);
			cout << "更新学生信息表" << endl;
			stu.ShowInfo();
			break;
		case 4:
			cout << "请输入要删除学生学号：";
			cin >> pnum;
			stu.StuDelete(pnum);
			cout << "更新学生信息表" << endl;
			stu.ShowInfo();
			break;
		case 5:
			cout << "请输入要查找学生学号：";
			cin >> pnum;
			pfind = stu.StuFind(pnum);
			cout << "查找学生学号：" << pfind->num << " 数学 " << pfind->math << " 英语 " << pfind->eng << " 语文 " << pfind->yuwen << " 总分 " << pfind->sum << endl;
			break;
		case 6:
			cout << "请输入要修改学生学号：";
			cin >> pnum;
			cout << "请重新输入学生分数：";
			cin >> pmath >> peng >> pyuwen;
			stu.StuModify(pnum, pmath, peng, pyuwen);
			cout << "修改成功！" << endl;
			cout << "更新学生信息表..." << endl;
			stu.ShowInfo();
			break;
		case 7:
			cout << "升序（1）降序（0）学号排序（10）：";
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
				cout << "输入错误！" << endl;
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
