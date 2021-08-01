#include "MaTran.h"

int main()
{
	cout << "Chuong trinh nay nhap du lieu tu 2 file inputA.txt cho ma tran A va inputB.txt cho ma tran B" << endl;
	do
	{
		cout << "Chinh sua 2 file inputA.txt va inputB.txt, roi tiep tuc..." << endl;
		system("pause");
		MaTran A;
		init(A);
		Nhap("inputA.txt", A);
		cout << "Ma tran A la:" << endl;
		XuatDangMaTran(A);

		MaTran B;
		init(B);
		Nhap("inputB.txt", B);
		cout << "Ma tran B la:" << endl;
		XuatDangMaTran(B);

		MaTran kq_tong;
		init(kq_tong);
		kq_tong = Tong(A, B);
		cout << "Tong 2 ma tran A va B la:" << endl;
		XuatDangMaTran(kq_tong);

		MaTran kq_hieu;
		init(kq_hieu);
		kq_hieu = Hieu(A, B);
		cout << "Hieu 2 ma tran A va B la:" << endl;
		XuatDangMaTran(kq_hieu);
		
	} while (KiemTraTiepTuc());
	
	return 1;
}

