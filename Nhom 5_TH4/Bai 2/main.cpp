#include "Tree.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    Tree T;
    CreateTree(T);
    cout << "Moi nhap chuoi:";
    getline(cin, input);
    for (int i=0; i<input.size(); i++)
    {
        KiTu c;
        c.info = input[i];
        c.count = 1;
        InsertRecursion(T, c);
    }
    cout << "Thong ke so lan xuat hien cua tung ky tu:" << endl;
    inOrder(T);
    /*cout << "\nCay tim kiem:" << endl;
    Xuat(T);*/
    return 1;
}
