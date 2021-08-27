#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct TNode
{
    int key;
    TNode* pLeft;
    TNode* pRight;
};

typedef TNode* Tree;

TNode* CreateNewTNode(int x)
{
    TNode* p = new TNode;
    if (p == NULL)
    {
        cout << "Bo nho day!" << endl;
        exit(1);
    }
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void CreateTree(Tree& T)
{
    T = NULL;
}

int Insert(Tree& T, int x)
{
    if (T)
    {
        if (T->key == x)
        {
            return 0;
        }
        if (x < T->key)
        {
            return Insert(T->pLeft, x);
        }
        else
        {
            return Insert(T->pRight, x);
        }
    }
    T = CreateNewTNode(x);
    return 1;
}

void Nhap(Tree& T, string filename)
{
    int n;
    ifstream fi(filename);
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
    	fi >> temp;
        Insert(T, temp);
    }
}

void Xuat(Tree T, int x, string s)
{
    if (T)
    {
        ++x;
        Xuat(T->pRight, x, "/\"\"\"");
        for (int i = 0; i < x; i++)
        {
            cout << "\t";
        }
        cout << s << T->key;
        cout << endl;
        Xuat(T->pLeft, x, "\\___");
    }
}

void Xuat(Tree T)
{
    Xuat(T, -1, "");
}

int ktTrongMang(vector<int> arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
            return 1;
    }
    return 0;
}

void XuatSapXepTangDan(Tree T)
{
    if (T)
    {
        XuatSapXepTangDan(T->pLeft);
        cout << T->key << " ";
        XuatSapXepTangDan(T->pRight);
    }
}

void XuatSapXepGiamDan(Tree T)
{
    if (T)
    {
        XuatSapXepGiamDan(T->pRight);
        cout << T->key << " ";
        XuatSapXepGiamDan(T->pLeft);
    }
}

TNode* TimNodeKhoa(Tree T, int x)
{
    if (T)
    {
        if (T->key == x)
        {
            return T;
        }
        if (x < T->key)
        {
            return TimNodeKhoa(T->pLeft, x);
        }
        else
        {
            return TimNodeKhoa(T->pRight, x);
        }
    }
    return NULL;
}

void XuatThongTinTNode(TNode* p)
{
    if (p)
    {
        cout << "Node co key=" << p->key << ", dia chi=" << p << ", node trai key=";
        if (p->pLeft)
        {
            cout << p->pLeft->key;
        }
        else
        {
            cout << "NULL";
        }
        cout << ", node phai key=";
        if (p->pRight)
        {
            cout << p->pRight->key;
        }
        else
        {
            cout << "NULL";
        }
        cout << endl;
    }
    else
    {
        cout << "Khong co thong tin cua node." << endl;
    }
}
void ThayThe(Tree& p, Tree& T)
{
    if (T->pRight)
    {
        ThayThe(p, T->pRight);
    }
    else
    {
        p->key = T->key;
        p = T;
        T = T->pLeft;
    }
}
void XoaPhanTu(Tree& T, int x, int& flag)
{
    if (T)
    {
        if (x == T->key)
        {
            Tree p = T;
            if (T->pLeft == NULL)
            {
                T = T->pRight;
            }
            else if (T->pRight == NULL)
            {
                T = T->pLeft;
            }
            else
            {
                ThayThe(p, T->pLeft);
            }
            delete p;
            flag = 1;
            return;
        }
        else if (x < T->key)
        {
            XoaPhanTu(T->pLeft, x, flag);
        }
        else
        {
            XoaPhanTu(T->pRight, x, flag);
        }
    }
}

void XoaPhanTu(Tree& T, int x)
{
    int flag = 0;
    XoaPhanTu(T, x, flag);
    if (flag)
    {
        cout << "Da xoa phan tu thanh cong!" << endl;
        cout << "Cay hien tai:" << endl;
        Xuat(T);
    }
    else
    {
        cout << "Khong tim thay phan tu can xoa." << endl;
    }
}

void Menu(Tree T)
{
    TNode* p;
    int lua_chon = 0;
    do
    {
        cout << "\t=== Cac lua chon === " << endl;
        cout << "\t1. Sap xep tang dan.\n"
            "\t2. Sap xep giam dan.\n"
            "\t3. Tim mot nut co khoa bang X tren cay.\n"
            "\t4. Xoa 1 nut co khoa bang X tren cay, neu khong co thi thong bao khong co.\n"
            "\t0. Ket thuc\n"
            "\tChon mot so tu 0 den 4: ";
        cin >> lua_chon;
        switch (lua_chon)
        {
        case 1:
            cout << "Xuat cac node theo thu tu tang dan: ";
            XuatSapXepTangDan(T);
            cout << endl;
            break;
        case 2:
            cout << "Xuat cac node theo thu tu giam dan: ";
            XuatSapXepGiamDan(T);
            cout << endl;
            break;
        case 3:             //Tim mot nut co khoa bang X tren cay.
            int x;
            cout << "Nhap khoa x can tim: ";
            cin >> x;
            p = TimNodeKhoa(T, x);
            if (p)
            {
                XuatThongTinTNode(p);
            }
            else
            {
                cout << "Khong tim thay node co gia tri " << x << " trong cay." << endl;
            }
            
            break;
        case 4:                     //Xoa 1 nut co khoa bang X tren cay, neu khong co thi thong bao khong co.
            int y;
            cout << "Nhap khoa y can xoa: ";
            cin >> y;
            XoaPhanTu(T, y);
            break;
        default:
            break;
        }
    } while (lua_chon != 0);
}

int main()
{
    Tree T;
    CreateTree(T);
    cout << "Mo file input.txt de nhap cac phan tu so nguyen cua cay\n"
        "Dong dau tien la so phan tu cua cay, cac dong tiep theo la gia tri tung phan tu.\n";
    system("pause");
    Nhap(T, "input.txt");
    Xuat(T);
    Menu(T);
    cout << "Chuong trinh ket thuc :)" << endl;
    return 1;
}