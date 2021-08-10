#include "StackSo.h"

int main()
{
	char s = 'y';
	do
	{
		StackSo S;
		S.Nhap();
		cout << "Ket qua la: " << endl;
		cout << S.TinhToan() << endl;
		cout << "Tiep tuc? (y/n): ";
		cin >> s;
		cin.ignore();
	} while (s == 'y');

	cout << "Chuong trinh ket thuc." << endl;
	
	return 1;
}