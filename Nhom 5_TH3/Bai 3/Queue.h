#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
	int info;
	Node* pNext;
public:
	Node()
	{
		info = 0;
		pNext = NULL;
	}
	Node(int x)
	{
		info = x;
		pNext = NULL;
	}
	void setinfo(int x)
	{
		info = x;
	}
	void set_pNext(Node* new_pNext)
	{
		pNext = new_pNext;
	}


	int getinfo()
	{
		return info;
	}
	Node* get_pNext()
	{
		return pNext;
	}
};

class Queue
{
private:
	Node* pHead;
	Node* pTail;
public:
	Queue()
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

	void EnQueue(int x)
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
		int x = 0;
		do
		{
			cout << "Nhap mot phan tu moi, hoac nhap so am de ket thuc: ";
			cin >> x;
			if (x >= 0)
			{
				EnQueue(x);
			}
		} while (x >= 0);
	}

	void Xuat()
	{
		Node* p;
		p = pHead;
		while (p != NULL)
		{
			cout << p->getinfo() << "\t";
			p = p->get_pNext();
		}
		cout << endl;
	}
};

