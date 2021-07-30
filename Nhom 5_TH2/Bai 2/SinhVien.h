#pragma once
#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
	string ten = "";
	string mssv;
	float diem_trung_binh = 0;
};

struct Node
{
	SinhVien info;
	Node* pNext = NULL;
};

struct List
{
	Node* pHead;
	Node* pTail;
};

void CreateNewList(List& L)
{
	L.pHead = NULL;
	L.pTail = NULL;
}

Node* CreateNewNode(SinhVien sv)
{
	Node* p = new Node;
	p->info = sv;
	p->pNext = NULL;
	return p;
}

void AddHead(List& L, SinhVien sv)
{
	Node* p = CreateNewNode(sv);
	if (L.pHead == NULL)
	{
		L.pHead = p;
		L.pTail = p;
	}
	else
	{
		p->pNext = L.pHead;
		L.pHead = p;
	}
}

//Nhap xuat danh sach
void Nhap(List& L)
{
	SinhVien sv;
	int dem = 0;
	cout << "[Tien hanh nhap danh sach cac sinh vien."
		"\nViec nhap ket thuc khi ten cua mot sinh vien bang rong (tuc khong nhap gi ca)]" << endl;

	while (true)
	{
		cout << "Nhap thong tin sinh vien thu " << ++dem << ":" << endl;
		cout << "\tNhap ten sinh vien: ";
		getline(cin, sv.ten);
		if (sv.ten == "")
		{
			break;
		}
		cout << "\tNhap MSSV: ";
		getline(cin, sv.mssv);
		cout << "\tNhap diem trung binh: ";
		cin >> sv.diem_trung_binh;
		cin.ignore();
		AddHead(L, sv);
	}

	cout << "Da ket thuc qua trinh nhap danh sach sinh vien." << endl;
}

void Xuat(List L)
{
	Node* p = L.pHead;
	cout << "Danh sach sinh vien: " << endl;
	while (p != NULL)
	{
		cout << "Ten: " << p->info.ten << endl;
		cout << "\tMSSV: " << p->info.mssv << endl;
		cout << "\tDiem trung binh: " << p->info.diem_trung_binh << endl;
		p = p->pNext;
	}
}

//Kiem tra co sinh vien trong lop
bool CoSinhVienTrongLopHocTen(List L, string ten_tim_kiem)
{
	Node* p = L.pHead;
	while (p != NULL)
	{
		if (p->info.ten == ten_tim_kiem)
		{
			return true;
		}
		p = p->pNext;
	}
	return false;
}

bool CoSinhVienTrongLopHocMSSV(List L, string mssv_tim_kiem)
{
	Node* p = L.pHead;
	while (p != NULL)
	{
		if (p->info.mssv == mssv_tim_kiem)
		{
			return true;
		}
		p = p->pNext;
	}
	return false;
}

void CoSinhVienTrongLopHoc(List ds_lop)
{
	int temp_i;
	string temp_s = "";
	bool kq_tim_kiem;

	do
	{
		cout << "Tim danh sach theo ten (1) hay theo ma so sinh vien (2)? Hay nhap mot con so: ";
		cin >> temp_i;
		if (temp_i < 1 || temp_i>2)
		{
			cout << "Chi co the chon so 1 hoac so 2. Xin hay nhap lai." << endl;
		}
		else
		{
			cin.ignore();
			break;
		}
	} while (true);



	if (temp_i == 1)
	{
		cout << "Hay nhap ten sinh vien: ";
		getline(cin, temp_s);
		kq_tim_kiem = CoSinhVienTrongLopHocTen(ds_lop, temp_s);
	}
	else
	{
		cout << "Hay nhap MSSV cua sinh vien: ";
		getline(cin, temp_s);
		kq_tim_kiem = CoSinhVienTrongLopHocMSSV(ds_lop, temp_s);
	}

	if (kq_tim_kiem == true)
	{
		cout << "Co sinh vien trong lop hoc." << endl;
	}
	else
	{
		cout << "Khong co sinh vien nay trong lop hoc." << endl;
	}
}
