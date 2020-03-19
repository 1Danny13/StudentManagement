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
	SInfo();      //���캯��
	~SInfo();     //��������
	void CreatSinfo();  //����ѧ����Ϣ
	void StuInsert(int snum, int smath, int seng, int syuwen);  //����ѧ����Ϣ
	void StuDelete(int snum);    //ɾ��ѧ����Ϣ
	StuNode *StuFind(int snum);   //����ѧ����Ϣ���������ѧ��
	void StuModify(int snum, int smath, int seng, int syuwen);   //�޸�ѧ����Ϣ
	void StuCopy(StuNode *ptemp, StuNode *p);  //ѧ����Ϣ����
	void StuSort(char ch);
	void StuClassfy();     //����ϼ�
	void StuRead();        //���ļ�����ѧ����Ϣ
	void StuSave();        //����ѧ����Ϣ���ļ�
	int IsRead();
	void StuQuit();
	void ShowInfo();           //�������ѧ����Ϣ


};

int Systemdoor()
{
	string username = "name", password = "password";
	string name, temp;
	int number = 3;
	while (1)
	{
		cout << "                �� �� ����";
		cin >> name;
		cout << "                ��    �룺";
		cin >> temp;
		if (name != username || temp != password)
		{
			number--;
			if (number > 0)
			{
				cout << "          �û���/�������!�㻹��" << number << "�λ���" << endl;
			}
			else
				cout << "�û���/�������!" << endl, exit(0);

		}
		else
		{
			cout << "������ȷ" << endl << endl;
			return 1;
		}
	}

}

void ShowMenu()
{
	cout << "------------------------------------------" << endl;
	cout << "       0.��ȫ�˳�ϵͳ          " << endl;
	cout << "       1.�ļ�����ѧ����Ϣ      " << endl;
	cout << "       2.¼���µ�ѧ����Ϣ      " << endl;
	cout << "       3.����µ�ѧ����Ϣ      " << endl;
	cout << "       4.ɾ������ѧ����Ϣ      " << endl;
	cout << "       5.��������ѧ����Ϣ      " << endl;
	cout << "       6.�޸�����ѧ����Ϣ      " << endl;
	cout << "       7.����ѧ����Ϣ����      " << endl;
	cout << "       8.����ϼ�ѧ����Ϣ      " << endl;
	cout << "       9.�������ѧ����Ϣ      " << endl;
	cout << "      10.��������ѧ����Ϣ      " << endl;
	cout << "\n\t\n\t\t��ѡ��";
}

SInfo::SInfo()   //���캯��
{
	StuListHead = new StuNode;
	StuListHead->nextstu = NULL;
}

SInfo::~SInfo()       //��������
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

void SInfo::CreatSinfo()     //����ѧ����Ϣ��
{
	int n;
	StuNode *p, *s;
	p = StuListHead;
	cout << "������ѧ��������";
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
	if (p == NULL)   //�ж�ѧ����Ϣ
	{
		cout << "����ʧ�������´�����" << endl;
		CreatSinfo();
	}
}

void SInfo::ShowInfo()      //����
{
	StuNode *p;
	cout << "ѧ��" << '\t' << "��ѧ" << '\t' << "Ӣ��" << '\t' << "����" << '\t' << "�ܷ�" << endl;
	for (p = StuListHead->nextstu; p != NULL; p = p->nextstu)
	{
		cout << p->num << '\t' << p->math << '\t' << p->eng << '\t' << p->yuwen << '\t' << p->sum << endl;
	}
}

void SInfo::StuInsert(int snum, int smath, int seng, int syuwen)     //����ѧ����Ϣ��ͷ�巨��
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
		cout << "δ�ҵ���ѧ����Ϣ��" << endl;
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
		cout << "δ�ҵ���ѧ����Ϣ��" << endl;
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

void SInfo::StuCopy(StuNode *ptemp, StuNode *p)  //����ѧ����Ϣ
{
	if (p == NULL)
	{
		cout << "����Ŀ��Ϊ�գ�" << endl;
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

void SInfo::StuSort(char ch)  //�ܷ�����
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
		cout << "������������" << endl;
	}
}

void SInfo::StuClassfy()  //�ַܷ���
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

void SInfo::StuRead()    //���ļ���������
{
	StuNode *p;
	p = StuListHead;
	ifstream in("StudentList.txt");
	if (!in) { cout << "û��ѧ����Ϣ������¼��ѧ����Ϣ!" << endl; return; }
	while (!in.eof())
	{
		int num, math, eng, yuwen, sum;
		in >> num >> math >> eng >> yuwen >> sum;
		StuInsert(num, math, eng, yuwen);
	}
}

void SInfo::StuSave()   //����ѧ����Ϣ
{
	StuNode *p;
	p = StuListHead->nextstu;
	ofstream out("StudentList.txt");
	if (!out) { cout << "���ܴ��ļ���" << endl; return; }
	while (p != NULL)
	{
		out << p->num << '\t' << p->math << '\t' << p->eng << '\t' << p->yuwen << '\t' << p->sum << '\n';
		p = p->nextstu;
	}
}

void SInfo::StuQuit()   //ѧ����Ϣд���ļ�
{
	char choice;
	cout << "�Ƿ񱣴�ѧ����Ϣ������Y/N��";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		StuSave();
		cout << "ѧ����Ϣ�ѱ���..." << endl;
	}
}