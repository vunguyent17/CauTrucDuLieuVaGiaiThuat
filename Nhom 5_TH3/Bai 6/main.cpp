#include "TramThuPhi.h"

int main()
{
	srand((unsigned int)time(nullptr));
	TramThuPhi T1;
	cout << "Mo phong Quan ly tram thu phi. Nhap bat ki phim nao de bat dau:" << endl;
	system("pause");
	T1.TienHanh();
	cout << "Mo phong ket thuc.";
	return 1;
}