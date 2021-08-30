#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef struct TNODE* TREE;

// tao cay rong
void CreateTree(TREE& T)
{
    T = NULL;
}
//tao node co key x
TNODE* CreateNode(int x)
{
    TNODE* p = new TNODE;
    if (p == NULL)
    {
        exit(1);
    }
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

//a.Nhap gia tri x
void Insert(TREE& T, int x)
{
    if (T == NULL)
    {
        TNODE* p = new TNODE;
        p->key = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        T = p;
    }
    else
    {
        if (T->key > x)
            return Insert(T->pLeft, x);
        else if (T->key < x)
            return Insert(T->pRight, x);

    }
    T = CreateNode(x);
}

//tang dan
void Acsending(TREE T)
{
    if (T != NULL)
    {
        
        Acsending(T->pLeft);
        cout << T->key << "\t";
        Acsending(T->pRight);
    }
}

//giam dan
void Descending(TREE T)
{
    if (T != NULL)
    {

        Descending(T->pRight);
        cout << T->key << "\t";
        Descending(T->pLeft);
    }
}

void print()
{
    TREE T = NULL;
    printf("\nXuat cac gia tri theo tang k: ");

}

//c.Tim node co khoa bang x tren cay
TNODE* SearchNode(TREE Root, int x)
{
    TNODE* p = Root;
    while (p != NULL)
    {
        if (x == p->key)
            return p;
        else if (x < p->key)
            p = p->pLeft;
        else
            p = p->pRight;
    }
    return NULL;
}

//d. Xoa 1 node co khoa bang X tren cay, neu ko co thi thong bao ko co.
void Thaythe(TREE& p, TREE& T)
{
    if (T->pLeft != NULL)
        Thaythe(p, T->pLeft);
    else
    {
        p->key = T->key;
        p = T;
        T = T->pRight;
    }
}

void DeleteNodeX(TREE& T, int x, int& flag)
{
    if (T)
    {
        if (T->key < x)
            DeleteNodeX(T->pRight, x, flag);
        else
        {
            if (T->key > x)
                DeleteNodeX(T->pLeft, x, flag);
            else
            {
                TNODE* p;
                p = T;
                if (T->pLeft == NULL)
                    T = T->pRight;
                else
                {
                    if (T->pRight == NULL)
                        T = T->pLeft;
                    else Thaythe(p, T->pRight);
                }
                delete p;
                flag = 1;
                return;
            }
        }
    }
}

void DeleteNodeX(TREE& T, int x)
{
    int flag = 0;
    DeleteNodeX(T, x, flag);
    if (flag)
    {
        cout << "Da xoa key bang x" << endl;
    
    }
    else
    {
        cout << "Khong co key bang x" << endl;
    }
}

//e.Dem so node trong cay
int DemNode(TREE T)
{
    int sum = 0;
    if (T == NULL)
        return 0;
    int a = DemNode(T->pLeft);
    int b = DemNode(T->pRight);
    sum=(a + b + 1);
    return sum;
}

//f.Tinh chieu cao cua cay
int Height(TNODE* T)
{
    if (!T)
        return -1;
    int a = Height(T->pLeft);
    int b = Height(T->pRight);
    return (a > b ? a : b) + 1;
}

//g.Xuat cay nhi phan theo tang
void XuatTangK(TREE& T, int k)
{
    if (T == NULL)
        return;
    if (k == 0)
        cout << T->key << "\t";
    else
    {
        XuatTangK(T->pLeft, k - 1);
        XuatTangK(T->pRight, k - 1);
    }
}
void XuatTheoTang(TREE T)
{
    int h = Height(T);
    if (h < 0)
        cout << "\nCay khong ton tai." << endl;
    else
    {
        for (int i = 0; i <= h; i++)
        {
            cout << "\nTang " << i << " : ";
            XuatTangK(T, i);
            cout << "\n";
        }
    }
}

void Menu(TREE T)
{
    TNODE* p;
    int luachon = 0;
    do
    {
        cout << "\n\n\t\t======= Menu ==========";
        cout << "\n1. Nguoi dung nhap vao cac gia tri den khi nhap -1 thi dung (gia tri -1 khong thuoc cay).";
        cout << "\n2. In cay nhi phan theo tang dan.";
        cout << "\n3. In cay nhi phan theo giam dan.";
        cout << "\n4. Tim mot nut co khoa bang X tren cay ";
        cout << "\n5. Xoa 1 nut co khoa bang X tren cay, neu khong co thi thong bao khong co.";
        cout << "\n6. Tim so node trong cay.";
        cout << "\n7. Tim chieu cao cua cay.";
        cout << "\n8. Xuat cay nhi phan theo tang.";
        cout << "\n0. Ket thuc chuong trinh.";
        cout << "\n\n\t\t ======================";

       
        cout << "Nhap lua chon: ";
        cin >> luachon;
        switch (luachon)
        {
        case 1:

            int x;
            do
            {
                cout << "\nMoi nhap so nguyen x: ";
                cin >> x;
                if (x !=-1)
                {
                    Insert(T, x);
                }
            } while (x != -1);
            cout << "Ket thuc qua trinh nhap." << endl;
            break;

        case 2:

            cout << "Xuat tang dan: ";
            Acsending(T);
            cout << endl;
            break;

        case 3:

            cout << "Xuat giam dan: ";
            Descending(T);
            cout << endl;
            break;

        case 4:
            
            cout << "Moi nhap khoa can tim :";
            cin >> x;
            p = SearchNode(T, x);
            if (p)
            {
                cout << "Tim thay node co khoa bang X tren cay.";
            }
            else
            {
                cout << "Khong tim thay." << endl;
            }
            break;

        case 5:
            
            int y;
            cout << "Nhap so can xoa: ";
            cin >> y;
            DeleteNodeX(T, y);
            break;

        case 6:
            
            cout << "So node trong cay la: " << DemNode(T) << endl;
            break;

        case 7:

            cout << "Chieu cao cua cay la: " << Height(T) << endl;
            break;

        case 8:

            cout<<"Xuat cay nhi phan theo tang: " << endl;
            XuatTheoTang(T);
            break;
        default:
            break;
        }
    } while (luachon!=0);
    cout << "Chuong trinh ket thuc." << endl;
}


int main()
{
    TREE T;
    CreateTree(T);
    Menu(T);
    system("pause");
    return 0;
}