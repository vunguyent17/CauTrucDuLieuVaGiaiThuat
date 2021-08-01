#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//Thiet lap kieu du lieu va danh sach lien ket don
struct PhanTuMaTran
{
	int gia_tri;
	int vi_tri;
};

struct Node
{
	PhanTuMaTran info;
	Node* pNext;
};

struct MaTran
{
	int SoHang;
	int SoCot;
	Node* pHead;
	Node* pTail;
};

Node* CreateNewNode(PhanTuMaTran ptmt)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "Bo nho day." << endl;
	}
	p->info = ptmt;
	p->pNext = NULL;
	return p;
}

PhanTuMaTran CreatePhanTuMaTran(int new_gia_tri, int new_vi_tri)
{
	PhanTuMaTran kq;
	kq.gia_tri = new_gia_tri;
	kq.vi_tri = new_vi_tri;
	return kq;
}

void init(MaTran& mt)
{
	mt.SoHang = 0;			//So hang trong ma tran
	mt.SoCot = 0;			//So cot trong ma tran
	mt.pHead = NULL;
	mt.pTail = NULL;
}

void AddTail(MaTran& mt, PhanTuMaTran phan_tu_moi)
{
	Node* p = CreateNewNode(phan_tu_moi);
	if (mt.pHead == NULL)
	{
		mt.pHead = p;
		mt.pTail = p;
	}
	else
	{
		mt.pTail->pNext = p;
		mt.pTail = p;
	}
}

void AddTail(MaTran& mt, Node* Node_moi)
{
	if (mt.pHead == NULL)
	{
		mt.pHead = Node_moi;
		mt.pTail = Node_moi;
	}
	else
	{
		mt.pTail->pNext = Node_moi;
		mt.pTail = Node_moi;
	}
}

//Cac ham thuc hien cac thao tac theo yeu cau
void Nhap(string filename, MaTran& mt)		//Nhap ma tran tu file .txt, cac phan tu trong ma tran phan biet nhau boi ki tu tab
{
	string line;
	ifstream myfile;
	int dem_vi_tri = -1;	//So thu tu cua phan tu trong ma tran, dem tu 0 den "so phan tu cua ma tran - 1"
	int dau = 1;			//Xac dinh gia tri nhap vao am hay duong

	myfile.open(filename);
	if (myfile.is_open())
	{
		while (getline(myfile, line))	//tien hanh duyet tung dong du lieu trong file .txt
		{
			string line_s = line;		//chuyen dong du lieu sang kieu string

			mt.SoHang++;

			string so_s = "";
			for (int i = 0; i < (line_s.length()); i++)
			{
				if ((int)line_s[i] != 9)		//kiem tra co phai ki tu "tab"
				{
					if (line_s[i] == '-')		//kiem tra co phai ki tu "-" cua so am
					{
						dau = -1;
					}
					else
					{
						so_s += line_s[i];
					}
				}
				if ((int)line_s[i] == 9 || i == line_s.length() - 1)
				{
					int co_so_10 = 1;
					int so_i = 0;
					for (int i = (int)so_s.length()-1; i >= 0; i--)
					{
						so_i += dau * (int)(so_s[i] - '0') * co_so_10;
						co_so_10 *= 10;
					}
					dem_vi_tri++;

					if (so_i != 0)
					{
						AddTail(mt, CreatePhanTuMaTran(so_i, dem_vi_tri));
					}
					dau = 1;
					so_s = "";
				}
			}
			//Tinh so cot (= so phan tu 1 hang) sau khi chuyen tat ca du lieu vao ma tran mt
			mt.SoCot = (dem_vi_tri + 1) / mt.SoHang;
		}
	}
}

//Liet ke tat ca ca phan tu khac 0 va vi tri cua no trong ma tran
void XuatLietKe(MaTran mt)
{
	Node* p = mt.pHead;
	cout << "Danh sach gia tri khac 0 trong ma tran:" << endl;
	while (p != NULL)
	{
		cout << "Vi tri: " << p->info.vi_tri << endl;
		cout << "\tGia tri: " << p->info.gia_tri << endl;
		p = p->pNext;
	}
}

//Xuat ma tran day du ra man hinh
void XuatDangMaTran(MaTran mt)
{
	Node* p = mt.pHead;
	cout << "Ma tran:" << endl;
	for (int i = 0; i < mt.SoHang; i++)
	{
		for (int j = 0; j < mt.SoCot; j++)
		{
			if (p == NULL || p->info.vi_tri != i * mt.SoCot + j)
			{
				cout << setw(4) << 0;
			}
			else
			{
				cout << setw(4) << p->info.gia_tri;
				p = p->pNext;
			}
		}
		cout << endl;
	}
}

// Tinh tong 2 ma tran: A + B
MaTran Tong(MaTran A, MaTran B)
{
	MaTran kq;
	init(kq);

	kq.SoCot = A.SoCot;
	kq.SoHang = A.SoHang;

	Node* pA = A.pHead;
	Node* pB = B.pHead;

	int vi_tri_A = -1, vi_tri_B = -1;  
	int gia_tri_A = 0, gia_tri_B = 0;

	while (pA != NULL || pB != NULL)
	{
		//Truong hop ma tran A con phan tu
		if (pA != NULL)			
		{
			vi_tri_A = pA->info.vi_tri;
			gia_tri_A = pA->info.gia_tri;
		}
		//Truong hop ma tran B con phan tu
		if (pB != NULL)			
		{
			vi_tri_B = pB->info.vi_tri;
			gia_tri_B = pB->info.gia_tri;
		}

		//Tinh ket qua tong 2 ma tran
		if (pA != NULL && pB != NULL && gia_tri_A == -gia_tri_B)	
		{
			pA = pA->pNext;
			pB = pB->pNext;
		}
		else
		{
			if (pA != NULL && (pB == NULL || vi_tri_A < vi_tri_B))
			{
				AddTail(kq, CreatePhanTuMaTran(gia_tri_A, vi_tri_A));
				pA = pA->pNext;
			}
			if (pB != NULL && (pA == NULL || vi_tri_A > vi_tri_B))
			{
				AddTail(kq, CreatePhanTuMaTran(gia_tri_B, vi_tri_B));
				pB = pB->pNext;
			}
			if (pA != NULL && pB != NULL && vi_tri_A == vi_tri_B)
			{
				AddTail(kq, CreatePhanTuMaTran(gia_tri_A + gia_tri_B, vi_tri_A));
				pA = pA->pNext;
				pB = pB->pNext;
			}
		}
	}
	return kq;
}

//Tinh hieu 2 ma tran: A - B
MaTran Hieu(MaTran A, MaTran B)
{
	MaTran kq;
	init(kq);

	kq.SoCot = A.SoCot;
	kq.SoHang = A.SoHang;

	Node* pA = A.pHead;
	Node* pB = B.pHead;

	int vi_tri_A = -1, vi_tri_B = -1;
	int gia_tri_A = 0, gia_tri_B = 0;

	while (pA != NULL || pB != NULL)
	{
		//Truong hop ma tran A con phan tu
		if (pA != NULL)
		{
			vi_tri_A = pA->info.vi_tri;
			gia_tri_A = pA->info.gia_tri;
		}
		//Truong hop ma tran B con phan tu
		if (pB != NULL)
		{
			vi_tri_B = pB->info.vi_tri;
			gia_tri_B = pB->info.gia_tri;
		}

		//Tinh ket qua hieu 2 ma tran
		if (pA != NULL && pB != NULL && gia_tri_A == -gia_tri_B)
		{
			pA = pA->pNext;
			pB = pB->pNext;
		}
		else
		{
			if (pA != NULL && (pB == NULL || vi_tri_A < vi_tri_B))
			{
				AddTail(kq, CreatePhanTuMaTran(gia_tri_A, vi_tri_A));
				pA = pA->pNext;
			}
			if (pB != NULL && (pA == NULL || vi_tri_A > vi_tri_B))
			{
				AddTail(kq, CreatePhanTuMaTran(-gia_tri_B, vi_tri_B));
				pB = pB->pNext;
			}
			if (pA != NULL && pB != NULL && vi_tri_A == vi_tri_B)
			{
				AddTail(kq, CreatePhanTuMaTran(gia_tri_A - gia_tri_B, vi_tri_A));
				pA = pA->pNext;
				pB = pB->pNext;
			}
		}
	}
	return kq;
}

bool KiemTraTiepTuc()
{
	string s;
	do
	{
		cout << "Tiep tuc? (y/n): ";
		getline(cin, s);
		if (s == "y")
		{
			return true;
		}
		else if (s == "n")
		{
			cout << "Ket thuc chuong trinh." << endl;
			return false;
		}
		else
		{
			cout << "Chi nhap y hoac n. Xin hay nhap lai." << endl;
		}
		
	} while (s != "n" || s != "y");
	return false;
}