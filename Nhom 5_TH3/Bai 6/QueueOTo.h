#pragma once

#include "OTo.h"
#include "OToHangNang.h"
#include "OToLon.h"
#include "OToNho.h"
#include "OToTrungBinh.h"
#include <Windows.h>
#include <iomanip>

//Thiet lap lop Node 
class Node
{
private:
	OTo info;
	Node* pNext = NULL;
public:
	//Khoi tao cac gia tri cua Node
	void CreateNode(OTo x)
	{
		info = x;
		pNext = NULL;
	}

	//Ham cap nhat cac gia tri cua Node
	void setinfo(OTo x)
	{
		info = x;
	}
	void set_pNext(Node* new_pNext)
	{
		pNext = new_pNext;
	}

	//Ham truy xuat cac gia tri cua Node
	OTo getinfo()
	{
		return info;
	}
	Node* get_pNext()
	{
		return pNext;
	}
};


//Thiet lap hang doi cua o to: QueueOTo
class QueueOTo
{
protected:
	Node* pHead;
	Node* pTail;
	int so_luong_xe_doi = 0;	//so luong xe dang cho trong hang doi
		
public:
	QueueOTo()
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
		so_luong_xe_doi++;
	}

	void EnQueue(OTo x)
	{
		Node* p = new Node;
		p->CreateNode(x);
		EnQueue(p);
	}

	bool DeQueue()
	{
		OTo x;
		DeQueue(x);
		return 1;
	}

	bool DeQueue(OTo& x)
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
				so_luong_xe_doi--;
				return 1;
			}
		}
		return 0;
	}

	int getSoLuongXeDoi()
	{
		return so_luong_xe_doi;
	}

	bool isEmpty()
	{
		if (pHead == NULL)
		{
			return 1;
		}
		return 0;
	}

	void Xuat()
	{
		Node* p = pHead;
		while (p!=NULL)
		{
			switch (p->getinfo().Loai)
			{
			case 1:
				cout << setw(4) << "N";
				break;
			case 2:
				cout << setw(4) << "TB";
				break;
			case 3:
				cout << setw(4) << "L";
				break;
			case 4:
				cout << setw(4) << "HN";
				break;
			default:
				break;
			}
			p = p->get_pNext();
		}
		cout << endl;
	}
};

//Thiet lap lop cho hang doi xe cua cong trong tram
class QueueOTo_Gate: public QueueOTo
{
private:
	int so_tien=0;				//so tien thu duoc cua cong
	int moc_thoi_gian = 0;		//moc thoi gian vao thoi diem thu tien xong xe truoc do
public:
	bool isFull()
	{
		if (so_luong_xe_doi >= 10)
		{
			return 1;
		}
		return 0;
	}

	void setMocThoiGian(int t)
	{
		moc_thoi_gian = t;
	}

	int getMocThoiGian()
	{
		return moc_thoi_gian;
	}

	int getSoTien()
	{
		return so_tien;
	}
	
	//Tong thoi gian can de thong cac xe trong hang doi
	int TongThoiGianCanXuLy(int thoi_gian)		
	{
		Node* p = pHead;
		
		//Truong hop hang doi khong co xe nao thi tra ve 0
		if (p==NULL)
		{
			return 0;
		}

		//Tinh thoi gian con lai can de xe hien tai thong xe
		int kq = p->getinfo().getThoiGianQuaTram() - (thoi_gian - moc_thoi_gian);

		//Cong them thoi gian cac xe con lai trong hang cho can de thong xe
		p = p->get_pNext();
		while (p != NULL)
		{
			kq += p->getinfo().getThoiGianQuaTram();
			p = p->get_pNext();
		}

		return kq;
	}
	
	//kiem tra thong xe, thu tien va cho qua tram
	OTo XuLy(int thoi_gian)
	{
		//Chon xe o dau hang
		OTo xe = pHead->getinfo();		
		
		//Kiem tra thoi gian thong xe da du de thu tien 
		if (thoi_gian - moc_thoi_gian == xe.getThoiGianQuaTram())
		{
			so_tien += xe.getPhiQuaTram();		//Tien hanh thu tien
			DeQueue();							//Cho xe qua tram
			moc_thoi_gian = thoi_gian;			//Luu lai thoi gian da thong xe nay
			return xe;
		}
		OTo khong_xuat_xe;
		return khong_xuat_xe;
	}

};

