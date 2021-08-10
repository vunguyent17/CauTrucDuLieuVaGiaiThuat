#pragma once

#include <iostream>
#include <string>
using namespace std;

//Thiet lap lop cho Node chua so thuc
class Node
{
private:
	float info;
	Node* pNext;
public:

	//Khoi tao gia tri cho Node
	Node()
	{
		info = 0;
		pNext = NULL;
	}

	Node(float x)
	{
		info = x;
		pNext = NULL;
	}

	//Ham cap nhat cac gia tri cho Node
	void setinfo(float& x)
	{
		info = x;
	}

	void set_pNext(Node*& new_pNext)
	{
		pNext = new_pNext;
	}

	//Ham truy xuat cac gia tri cua Node
	float getinfo()
	{
		return info;
	}

	Node* get_pNext()
	{
		return pNext;
	}
};


//Thiet lap Stack dung de chua cac Node khi tinh ky phap nghich dao Ba Lan
class StackSo
{
private:
	Node* pHead;
	Node* pTail;
	string s = "";		//chua chuoi ky phap ban dau
public:
	StackSo()
	{
		pHead = NULL;
		pTail = NULL;
		s = "";
	}

	void Push(Node* p)
	{
		if (this->pHead == NULL)
		{
			pHead = p;
			pTail = p;
		}
		else
		{
			p->set_pNext(pHead);
			pHead = p;
		}
	}

	void Push(float x)
	{
		Node* p = new Node(x);
		Push(p);
	}

	bool Pop(float& x)
	{
		Node* p;
		if (!isEmpty())
		{
			if (pHead != NULL)
			{
				p = pHead;
				x = p->getinfo();
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
		cout << "Nhap bieu thuc can tinh duoi dang ky phap nghich dao Ba Lan: ";
		getline(cin, s);
	}

	float TinhToan()
	{
		int size_s = s.length();	//Do dai chuoi ky phap
		
		//Duyet cac phan tu trong chuoi ky phap va tinh toan
		for (int i = 0; i < size_s; i++)
		{
			//Truong hop phan tu la so
			if (s[i] >= '0' && s[i] <= '9')
			{
				float temp_i = (float)(s[i] - '0');		//chuyen so tu kieu string sang kieu int
				Push(temp_i);
			}
			else	//Truong hop phan tu la cac toan tu +, -, *, /, ^
			{
				//Lay cac Node o trong Stack
				float x1, x2;
				Pop(x2);
				Pop(x1);
				cout << x1 << s[i] << x2 << endl;

				//Xet cac truong hop toan tu
				switch (s[i])
				{
				case '+':
					Push(x1 + x2);
					break;
				case '-':
					Push(x1 - x2);
					break;
				case '*':
					Push(x1 * x2);
					break;
				case '/':
					Push(x1 / x2);
					break;
				case '^':
					Push(pow(x1, x2));
				default:
					cout << "Error." << endl;
					break;
				}
			}
		}

		//Sau khi tinh toan xong ket qua duoc day vao Stack va la Node duy nhat trong Stack. Tra ket qua cua biet thuc
		if (pHead == pTail)
		{
			return pHead->getinfo();
		}
		return -1;
	}
};


