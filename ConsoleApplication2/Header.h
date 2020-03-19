#pragma once

#define MAX_NUM 10
#include <String>
#include <fstream>
#include <iostream>
using namespace std;

bool quit = false;

struct StuNode {
	int num;
	int math, eng, yuwen;
	int sum;
	StuNode *nextstu;
};

class SInfo {
	StuNode *StuListHead;
public:
	SInfo();      //构造函数
	~SInfo();     //析构函数
	void CreatSinfo();  //创建学生信息
	void StuInsert(int snum, int smath, int seng, int syuwen);  //插入学生信息
	void StuDelete(int snum);    //删除学生信息
	StuNode *StuFind(int snum);   //查找学生信息，传入参数学号
	void StuModify(int snum, int smath, int seng, int syuwen);   //修改学生信息
	void StuCopy(StuNode *ptemp, StuNode *p);  //学生信息拷贝
	void StuSort(char ch);
	void StuClassfy();     //分类合计
	void StuRead();        //从文件读入学生信息
	void StuSave();        //保存学生信息到文件
	int IsRead();
	void StuQuit();
	void ShowInfo();           //遍历输出学生信息


};

int Systemdoor()
{
	string username = "name", password = "password";
	string name, temp;
	int number = 3;
	while (1)
	{
		cout << "                用 户 名：";
		cin >> name;
		cout << "                密    码：";
		cin >> temp;
		if (name != username || temp != password)
		{
			number--;
			if (number > 0)
			{
				cout << "          用户名/密码错误!你还有" << number << "次机会" << endl;
			}
			else
				cout << "用户名/密码错误!" << endl, exit(0);

		}
		else
		{
			cout << "密码正确" << endl << endl;
			return 1;
		}
	}

}

void ShowMenu()
{
	cout << "------------------------------------------" << endl;
	cout << "       0.安全退出系统          " << endl;
	cout << "       1.文件读入学生信息      " << endl;
	cout << "       2.录入新的学生信息      " << endl;
	cout << "       3.添加新的学生信息      " << endl;
	cout << "       4.删除已有学生信息      " << endl;
	cout << "       5.查找已有学生信息      " << endl;
	cout << "       6.修改已有学生信息      " << endl;
	cout << "       7.已有学生信息排序      " << endl;
	cout << "       8.分类合计学生信息      " << endl;
	cout << "       9.输出所有学生信息      " << endl;
	cout << "      10.保存现有学生信息      " << endl;
	cout << "\n\t\n\t\t请选择：";
}

SInfo::SInfo()   //构造函数
{
	StuListHead = new StuNode;
	StuListHead->nextstu = NULL;
}

SInfo::~SInfo()       //析构函数
{
	StuNode *p;
	while (StuListHead)
	{
		p = StuListHead;
		StuListHead = StuListHead->nextstu;
		delete p;
	}
	StuListHead = NULL;
}

void SInfo::CreatSinfo()     //创建学生信息表
{
	int n;
	StuNode *p, *s;
	p = StuListHead;
	cout << "请输入学生人数：";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		s = new StuNode;
		cin >> s->num >> s->math >> s->eng >> s->yuwen;
		s->sum = s->math + s->eng + s->yuwen;
		s->nextstu = p->nextstu;
		p->nextstu = s;
		p = p->nextstu;
	}
	if (p == NULL)   //判断学生信息
	{
		cout << "创建失败请重新创建！" << endl;
		CreatSinfo();
	}
}

void SInfo::ShowInfo()      //遍历
{
	StuNode *p;
	cout << "学号" << '\t' << "数学" << '\t' << "英语" << '\t' << "语文" << '\t' << "总分" << endl;
	for (p = StuListHead->nextstu; p != NULL; p = p->nextstu)
	{
		cout << p->num << '\t' << p->math << '\t' << p->eng << '\t' << p->yuwen << '\t' << p->sum << endl;
	}
}

void SInfo::StuInsert(int snum, int smath, int seng, int syuwen)     //插入学生信息（头插法）
{
	StuNode *s, *p;
	s = new StuNode;
	s->num = snum;
	s->math = smath;
	s->eng = seng;
	s->yuwen = syuwen;
	s->sum = s->math + s->eng + s->yuwen;
	p = StuListHead;
	s->nextstu = p->nextstu;
	p->nextstu = s;
}

void SInfo::StuDelete(int snum)
{
	StuNode *p, *ptemp;
	p = StuListHead;
	ptemp = p;
	while (p->nextstu && p->num != snum)  
	{
		ptemp = p;
		p = p->nextstu;
	}
	if (p->num == snum)
	{
		ptemp->nextstu = p->nextstu;
		delete p;
	}
	else
	{
		cout << "未找到该学生信息！" << endl;
	}
}

StuNode *SInfo::StuFind(int snum)
{
	StuNode *p;
	p = StuListHead->nextstu;
	while (p->nextstu && p->num != snum)   
	{
		p = p->nextstu;
	}
	if (p->num == snum)
	{
		return p;
	}
	else
	{
		cout << "未找到该学生信息！" << endl;
		return NULL;
	}
}

void SInfo::StuModify(int snum, int smath, int seng, int syuwen)
{
	StuNode *ItemStu = StuFind(snum);   
	if (ItemStu != NULL)
	{
		ItemStu->math = smath;
		ItemStu->num = snum;
		ItemStu->math = smath;
		ItemStu->eng = seng;
		ItemStu->yuwen = syuwen;
		ItemStu->sum = ItemStu->math + ItemStu->eng + ItemStu->yuwen;
	}
}

void SInfo::StuCopy(StuNode *ptemp, StuNode *p)  //拷贝学生信息
{
	if (p == NULL)
	{
		cout << "拷贝目标为空！" << endl;
	}
	else
	{
		ptemp->num = p->num;
		ptemp->math = p->math;
		ptemp->eng = p->eng;
		ptemp->yuwen = p->yuwen;
		ptemp->sum = p->sum;
	}
}

void SInfo::StuSort(char ch)  //总分排序
{
	if (ch == '>')
	{
		for (StuNode *p = StuListHead->nextstu; p != NULL; p = p->nextstu)
		{
			for (StuNode *q = StuListHead->nextstu; q != NULL; q = q->nextstu)
			{
				if (p->sum > q->sum)
				{
					StuNode *ptemp = new StuNode;
					StuCopy(ptemp, p);
					StuCopy(p, q);
					StuCopy(q, ptemp);
				}
			}
		}
	}
	else if (ch == '<')
	{
		for (StuNode *p = StuListHead->nextstu; p != NULL; p = p->nextstu)
		{
			for (StuNode *q = StuListHead->nextstu; q != NULL; q = q->nextstu)
			{
				if (p->sum < q->sum)
				{
					StuNode *ptemp = new StuNode;
					StuCopy(ptemp, p);
					StuCopy(p, q);
					StuCopy(q, ptemp);
				}
			}
		}
	}
	else if (ch == 'o')
	{
		for (StuNode *p = StuListHead->nextstu; p != NULL; p = p->nextstu)
		{
			for (StuNode *q = StuListHead->nextstu; q != NULL; q = q->nextstu)
			{
				if (p->num < q->num)
				{
					StuNode *ptemp = new StuNode;
					StuCopy(ptemp, p);
					StuCopy(p, q);
					StuCopy(q, ptemp);
				}
			}
		}
	}
	else
	{
		cout << "排序条件出错！" << endl;
	}
}

void SInfo::StuClassfy()  //总分分类
{
	int grade[5] = { 0 };
	StuNode *p = StuListHead->nextstu;
	while (p != NULL)
	{
		if (89 < p->math)
		{
			grade[0]++;
		}
		else if (79 < p->math && p->math < 90)
		{
			grade[1]++;
		}
		else if (69 < p->math && p->math < 80)
		{
			grade[2]++;
		}
		else if (59 < p->math && p->math < 70)
		{
			grade[3]++;
		}
		else
		{
			grade[4]++;
		}
		p = p->nextstu;
	}
	cout << "A" << '\t' << "B" << '\t' << "C" << '\t' << "D" << '\t' << "E" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << grade[i] << '\t';
	}
	cout << endl;
}

void SInfo::StuRead()    //从文件读入数据
{
	StuNode *p;
	p = StuListHead;
	ifstream in("StudentList.txt");
	if (!in) { cout << "没有学生信息，请先录入学生信息!" << endl; return; }
	while (!in.eof())
	{
		int num, math, eng, yuwen, sum;
		in >> num >> math >> eng >> yuwen >> sum;
		StuInsert(num, math, eng, yuwen);
	}
}

void SInfo::StuSave()   //保存学生信息
{
	StuNode *p;
	p = StuListHead->nextstu;
	ofstream out("StudentList.txt");
	if (!out) { cout << "不能打开文件！" << endl; return; }
	while (p != NULL)
	{
		out << p->num << '\t' << p->math << '\t' << p->eng << '\t' << p->yuwen << '\t' << p->sum << '\n';
		p = p->nextstu;
	}
}

void SInfo::StuQuit()   //学生信息写入文件
{
	char choice;
	cout << "是否保存学生信息：？（Y/N）";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		StuSave();
		cout << "学生信息已保存..." << endl;
	}
}