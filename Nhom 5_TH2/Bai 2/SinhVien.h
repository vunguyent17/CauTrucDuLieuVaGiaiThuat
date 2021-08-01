#pragma once
#include <iostream>
#include <string>

using namespace std;

// Sinhvien
struct Sinhvien {
    string ten = "";
    string mssv = "";
    float dtb = 0;
};

// NODE
struct NODE {
    Sinhvien info;
    NODE* pNext;
};

// LIST
struct LIST {
    NODE* pHead;
    NODE* pTail;
};

// Khoi tao LIST
void Init(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

// Tao NODE
NODE* CreateNode(Sinhvien data) {
    NODE* p;
    p = new NODE;
    // if (p == NULL)
    //     cout << "Het bo nho.";
    //     return NULL;
    p->info = data;
    p->pNext = NULL;
    return p;
}

// Add NODE vao dau LIST
void AddHead(LIST &L, NODE* p){
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = p;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

// 2.2 Nhap danh sach sinh vien
void NhapDS(LIST &L)
{
    Init(L);
    while (true)
    {
        Sinhvien data;
        cout << "Ho ten: ";
        getline(cin, data.ten);
        if (data.ten.length() == 0)
            break;
        cout << "MSSV: ";
        getline(cin, data.mssv);
        cout << "Diem TB: ";
        cin >> data.dtb;
        cin.ignore();
        NODE* p; 
        p = CreateNode(data);
        AddHead(L,p);
    }
}

// 2.2. In danh sach sinh vien
void XuatDS(LIST &L){
    NODE* p;
    p = L.pHead;
    cout << "-----DANH SACH SINH VIEN-----" << endl;
    cout << "(Ho ten, MSSV, DTB)" << endl;
    if (p == NULL)
    {
        cout << "-----------------" << endl;
    }
    else
    {
        while (p != NULL){
            cout << "(" << p->info.ten << ", "; 
            cout << p->info.mssv << ", ";
            cout << p->info.dtb << ")" << endl;
            p = p->pNext;
        }
        cout << "-----------------" << endl;
    }
    
}

// 2.3. Tim sinh vien
NODE* TimSinhVienByMSSV(LIST &L, string mssv){
    NODE* p;
    p = L.pHead;
    while (p != NULL){
        if (p->info.mssv == mssv)
            return p;
        p = p->pNext;
    }
    return NULL;
}

// 2.4. Xoa sinh vien
bool RemoveHead(LIST &L){
    NODE* p;
    if (L.pHead != NULL)
    {
        p = L.pHead;
        L.pHead = p->pNext;
        delete p;
        return 1; // Remove head successfully
    }
    return 0; // Empty list
}

bool RemoveAfterQ(LIST &L, NODE *Q)
{
    NODE *p;
    if (Q != NULL)
    {
        p = Q->pNext; // p is targeted node
        if (p != NULL) // q is NOT last node
        {
            if (p == L.pTail) // targeted node is last node
            {
                L.pTail = Q; // pTail points to Q since Q now is last node
            }
            Q->pNext = Q->pNext->pNext;
            delete p;
        }
        return 1;
    }
    return 0;
}

bool XoaMSSV(LIST &L, string mssv){
    NODE* p;
    p = L.pHead;
    if (p == NULL){
        return false;
    }
    if (p->info.mssv == mssv)
    {
        RemoveHead(L);
        return true;
    }
    while (p != L.pTail){
        if (p->pNext->info.mssv == mssv)
        {
            RemoveAfterQ(L, p);
            return true;
        }
        p = p->pNext;
    }
    return false;
}

// 2.5. Liet ke thong tin sinh vien co dtb >= 5
void ListSVgreaterThan5(LIST &L){
    NODE *p;
    bool temp = false;
    p = L.pHead;
    while (p != NULL){
        if (p->info.dtb >= 5)
        {
            temp = true;
            cout << "(" << p->info.ten << ", "; 
            cout << p->info.mssv << ", ";
            cout << p->info.dtb << ")" << endl;
        }
        p = p->pNext;
    }
    if (temp == false)
    {
        cout << "Danh sach khong ai ai diem trung binh tren 5." << endl;
    }
}

// 2.6. Xep loai va in ra thong tin sinh vien
void XepLoaiVaList(LIST &L){
    NODE *p;
    p = L.pHead;
    cout << "-----DANH SACH SINH VIEN-----" << endl;
    cout << "(Ho ten, MSSV, DTB, Xep loai)" << endl;
    while (p != NULL){
        cout << "(" << p->info.ten << ", ";
        cout << p->info.mssv << ", ";
        cout << p->info.dtb << ", ";
        if (p->info.dtb < 5)
        {
            cout << "Yeu" << ")" << endl;
        }
        else if (p->info.dtb >= 5 && p->info.dtb < 6.5)
        {
            cout << "Trung binh" << ")" << endl;
        }
        else if (p->info.dtb >= 6.5 && p->info.dtb < 7.0)
        {
            cout << "Trung binh Kha" << ")" << endl;
        }
        else if (p->info.dtb >= 7.0 && p->info.dtb < 8.0)
        {
            cout << "Kha" << ")" << endl;
        }
        else if (p->info.dtb >= 8.0 && p->info.dtb < 9.0)
        {
            cout << "Gioi" << ")" << endl;
        }
        else if (p->info.dtb >= 9.0 && p->info.dtb <= 10.0)
        {
            cout << "Xuat sac" << ")" << endl;
        }

        p = p->pNext;
    }
}

// 2.7. Sap xep theo diem trung binh
void SapXepTheoDTB(LIST &L){
    NODE* p;
    NODE* q;
    Sinhvien temp;
    p = L.pHead;
    while (p != L.pTail){
        q = p->pNext;
        while (q != NULL)
        {
            if (q->info.dtb < p->info.dtb)
            {
                temp = p->info;
                p->info = q->info;
                q->info = temp;
            }
            q = q->pNext;    
        }
        p = p->pNext;
    }
}

// 2.8. Chen nhung giu nguyen thu tu
void AddAfterQ(LIST &L, NODE* Q, NODE* p){  
    if (Q != NULL)
    {
        p->pNext = Q->pNext;
        Q->pNext = p;
        if (L.pTail == Q)
        {
            L.pTail = p;
        }
    }
    else
    {
        AddHead(L, p); // Add p into the beginning of list since Q is NULL 
    }
}

void AddTail(LIST &L, NODE* p){
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void ChenGiuNguyenThuTu(LIST &L, NODE* p){
    SapXepTheoDTB(L);
    
    NODE* temp;
    temp = L.pHead;
    if (temp == NULL || p->info.dtb <= temp->info.dtb)
    {
        AddHead(L, p);
        return;
    }
    while (temp != NULL){
        
        if ((temp->pNext == NULL && p->info.dtb >= temp->info.dtb)
            || (temp->info.dtb <= p->info.dtb && p->info.dtb <= temp->pNext->info.dtb))
        {
            AddAfterQ(L, temp, p);
            return;
        }
        temp = temp->pNext;
    }
    return;
}
