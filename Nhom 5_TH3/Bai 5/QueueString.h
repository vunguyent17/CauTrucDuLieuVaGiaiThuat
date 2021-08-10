#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include<windows.h>
using namespace std;

//--Thiet lap lop cho Node chua 1 ky tu
class Node
{
private:
	char info;		//Mot Node chua 1 ky tu trong chuoi
	Node* pNext;
public:

	//Thiet lap Node ban dau
	Node()
	{
		info = ' ';
		pNext = NULL;
	}
	Node(char s)
	{
		info = s;
		pNext = NULL;
	}

	//Cac ham cap nhat gia tri cua Node
	void setinfo(char x)
	{
		info = x;
	}
	void set_pNext(Node* new_pNext)
	{
		pNext = new_pNext;
	}

	//Cac ham truy xuat gia tri cua Node
	char getinfo()
	{
		return info;
	}
	Node* get_pNext()
	{
		return pNext;
	}
};

//--Thiet lap lop cho Queue chua cac ky tu trong mot chuoi: QueueString
class QueueString
{
private:
	string s;	//Chua chuoi ky tu ban dau
	Node* pHead;
	Node* pTail;
public:

	QueueString()
	{
		pHead = NULL;
		pTail = NULL;
	}
	
	void EnQueue(Node* p)
	{
		if (pHead == NULL)
		{
			pHead = p;
			pTail = p;
		}
		else
		{
			pTail->set_pNext(p);
			pTail = p;
		}
	}

	void EnQueue(char x)
	{
		Node* p = new Node(x);
		EnQueue(p);
	}

	bool DeQueue()
	{
		Node* p;
		if (!isEmpty())
		{
			if (pHead != NULL)
			{
				p = pHead;
				pHead = p->get_pNext();
				if (pHead == NULL)
				{
					pTail = NULL;
				}
				delete p;
				return 1;
			}
		}
		return 0;
	}

	bool isEmpty()
	{
		if (pHead == NULL)
		{
			return 1;
		}
		return 0;
	}

	void Nhap()
	{
		cout << "Nhap mot dong chu de chay man hinh: ";
		getline(cin, s);

		//Dua cac phan tu trong chuoi vao trong Queue
		int n = s.length();
		for (int i = 0; i < n; i++)
		{
			EnQueue(s[i]);
		}
	}

	void Xuat()
	{
		Node* p;
		p = pHead;
		while (p != NULL)
		{
			cout << p->getinfo();
			p = p->get_pNext();
		}
		cout << endl;
	}

	void ChayChu(int so_lan)	//so_lan: tinh la mot lan khi ca dong chu tro lai vi tri ban dau cua no
	{
		//Xuat ra man hinh chuoi ban dau
		system("CLS");
		Xuat();
		Sleep(400);

		//Tien hanh them bot cac Node trong Queue roi xuat ra man hinh de co hieu ung chay chu
		int dem = 0;
		while (dem <= so_lan)
		{
			dem++;
			for (int i = 0; i < s.size() * 2; i++)
			{
				system("CLS");
				DeQueue();
				if (i < s.size())
				{
					EnQueue(' ');	//Khi Queue con ky tu trong chuoi ban dau thi thay the bang ky tu ' '
				}
				else
				{
					EnQueue(s[i-s.size()]);		//Khi tat ca Queue la ky tu ' ' thi thay the bang ky tu trong chuoi
				}
				Xuat();
				Sleep(400);
			}
		}
	}
};

