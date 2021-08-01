#include"NaturalNumber.h"

int main()
{
	NaturalNumber a, b;
	char k = '3';
	do
	{
		if (k == '1')
		{
			NaturalNumber tong;
			tong = a + b;
			cout << "Tong la: ";
			tong.Output();
		}
		else if (k == '2')
		{
			NaturalNumber tich;
			tich = a * b;
			cout << "Tich la: ";
			tich.Output();
		}
		else if (k == '3')
		{
			cout << "Nhap vao so a: ";
			a.InputNumber();
			cout << "Nhap vao so b: ";
			b.InputNumber();
		}
		cout << "\n-Chon '1'-->Tinh Tong; Chon '2'-->Tinh Tich;  Chon'3'-->Nhap lai a, b;  Chon '0'-->Ket Thuc-" << endl;
		cin >> k;
		cin.ignore();
	} while (k != '0');
	return 0;
}