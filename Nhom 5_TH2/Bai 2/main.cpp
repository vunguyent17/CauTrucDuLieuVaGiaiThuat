/*Bai 2 (Slides 77 - 78) : Dung danh sach lien ket don de luu tru mot lop hoc co N sinh vien.
Biet rang moi sinh vien bao gom cac thong tin sau :
Ten(chuoi ky tu), Ma so sinh vien(chuoi ky tu), Diem trung binh.Hay viet ham thuc hien cac yeu cau sau :
1. Hay khai bao cau truc du lieu dang danh sach lien ket de luu danh sach sinh vien noi tren.
2. Nhap danh sach cac sinh vien, va them tung sinh vien vao dau danh sach(viec nhap ket thuc khi ten cua mot sinh vien bang rong)
3. Tim mot sinh vien co trong lop hoc hay khong*/

#include "SinhVien.h"

int main()
{
	List ds_lop;
	CreateNewList(ds_lop);
	Nhap(ds_lop);
	Xuat(ds_lop);
	CoSinhVienTrongLopHoc(ds_lop);
	return 1;
}