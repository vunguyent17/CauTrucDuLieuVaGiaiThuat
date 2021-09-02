#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct TNode
{
    int key;
    TNode* pLeft;
    TNode* pRight;
};

typedef TNode* Tree;

TNode* CreateNewTNode(int x);
void CreateTree(Tree& T);
int ktFile(string filename);
int Insert(Tree& T, int x);
void Nhap(Tree& T, string filename);
void Xuat(Tree T, int x, string s);     //Ho tro cho ham Xuat(Tree T)
void Xuat(Tree T);
void XuatSapXepTangDan(Tree T);
void XuatSapXepGiamDan(Tree T);
TNode* TimNodeKhoa(Tree T, int x);
void XuatThongTinTNode(TNode* p);
void ThayThe(Tree& p, Tree& T);
void XoaPhanTu(Tree& T, int x, int& flag);  //Ho tro cho ham XoaPhanTu(Tree& T, int x)
int XoaPhanTu(Tree& T, int x);
void Menu(Tree T);

int main()
{
    Tree T;
    CreateTree(T);
    cout << "Mo file input.txt de nhap cac phan tu so nguyen cua cay\n"
        "Dong dau tien la so phan tu cua cay, cac dong tiep theo la gia tri tung phan tu.\n";
    system("pause");
    Nhap(T, "input.txt");
    cout << "Da nhap xong du lieu vao cay. So do cay hien tai:" << endl;
    Xuat(T);
    Menu(T);
    cout << "Chuong trinh ket thuc :)" << endl;
    return 1;
}

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

int ktFile(string filename)
{
    string line;
    ifstream myfile;
    int n;
    myfile.open(filename);
    if (getline(myfile, line))
    {
        n = stoi(line);
    }
    else
    {
        return 0;
    }
    int dem = 0;
    while (getline(myfile,line))
    {
        dem++;
    }
    return (dem == n);
}

void Nhap(Tree& T, string filename)
{
    int n;
    int flag = 0;
    do
    {
        if (!ktFile(filename))
        {
            cout << "File input.txt khong co du lieu hoac du lieu khong hop le."
                "\nVui long mo file va kiem tra lai. Nhan bat ki phim nao de tien hanh nhap du lieu." << endl;
            system("pause");
        }
        else
        {
            ifstream fi(filename);
            fi >> n;
            for (int i = 0; i < n; i++)
            {
                int temp;
                fi >> temp;
                Insert(T, temp);
                flag = (i == n - 1 ? 1 : 0);
            }
        }
    } while (flag == 0);
}

void Xuat(Tree T, int x, string s)      //x de luu so tab can cach ra de tao so do, s de the hien moi quan he node trai va node phai
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
void XoaPhanTu(Tree& T, int x, int& flag)   // flag de danh dau chuong trinh da xoa phan tu chua
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

int XoaPhanTu(Tree& T, int x)
{
    int flag = 0;
    XoaPhanTu(T, x, flag);
    return flag;
}

void Menu(Tree T)
{
    TNode* p;
    int lua_chon = 0;
    do
    {
        cout << "\t=== Cac lua chon === " << endl;
        cout << "\t1. Nhap cay nhi phan.\n"
            "\t2. Xuat cay dang so do\n"
            "\t3. Xuat sap xep tang dan.\n"
            "\t4. Xuat sap xep giam dan.\n"
            "\t5. Tim mot nut co khoa bang X tren cay.\n"
            "\t6. Xoa 1 nut co khoa bang X tren cay, neu khong co thi thong bao khong co.\n"
            "\t0. Ket thuc\n"
            "\tChon mot so tu 0 den 4: ";
        cin >> lua_chon;
        switch (lua_chon)
        {
        case 1:
            while (T)
            {
                XoaPhanTu(T, T->key);
            }
            T = NULL;
            cout << "Mo file input.txt de nhap cac phan tu so nguyen cua cay\n"
                "Dong dau tien la so phan tu cua cay, cac dong tiep theo la gia tri tung phan tu.\n";
            system("pause");
            Nhap(T, "input.txt");
            cout << "Da nhap xong du lieu vao cay. So do cay hien tai:" << endl;
            Xuat(T);
            break;
        case 2:
            if (T)
            {
                Xuat(T);
            }
            else
            {
                cout << "Cay khong co du lieu. Xin lua chon 1 de nhap du lieu vao cay" << endl;
            }
            break;
        case 3:
            cout << "Xuat cac node theo thu tu tang dan: ";
            XuatSapXepTangDan(T);
            cout << endl;
            break;
        case 4:
            cout << "Xuat cac node theo thu tu giam dan: ";
            XuatSapXepGiamDan(T);
            cout << endl;
            break;
        case 5:             //Tim mot nut co khoa bang X tren cay.
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
        case 6:                     //Xoa 1 nut co khoa bang X tren cay, neu khong co thi thong bao khong co.
            int y;
            cout << "Nhap khoa can xoa: ";
            cin >> y;
            if (XoaPhanTu(T, y) == 1)
            {
                cout << "Da xoa phan tu thanh cong!" << endl;
                cout << "Cay hien tai:" << endl;
                Xuat(T);
            }
            else
            {
                cout << "Khong tim thay phan tu can xoa." << endl;
            }
            break;
        default:
            break;
        }
    } while (lua_chon != 0);
}