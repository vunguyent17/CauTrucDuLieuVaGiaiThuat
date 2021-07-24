#include"SinhVien.h"
#include"Lop.h"
#include <sstream>


//nhap thong tin sinh vien tu file
void InputInfoSVFromFile(Lop& l, string filename)
{
	ifstream fi(filename);      //khai bao file can doc
	string temp, tempname, tempid, diem;
	float tempdiem;
	do
	{
		getline(fi, temp);          //doc 1 dong cia file va gan vao bie tam thoi temp
		if (temp.empty())
		{
			break;
		}
		int trr = temp.length() - 1;
		int first = 0, second = 0;
		for (int i = 0; i < temp.length(); ++i)
		{
			if (temp.at(i) == ',' && first == 0)
			{
				first = i + 1;        //lay thu tu cot dau tien
			}
			else if (temp.at(i) == ',' && first != 0)
			{
				second = i;        //lay thu tu cot thu 2
			}
		}
		tempname.assign(temp, 0, first - 1);     //lay ky tu trong chuoi
		tempid.assign(temp, (first), second - first); //lay ky tu trong chuoi
		diem.assign(temp, trr, 1);             //lay ky tu trong chuoi
		stringstream str2um(diem);          //chuyen chuoi thanh int
		str2um >> tempdiem;                 //gan gia tri vua chuyen vao 
		l.AddTail(tempname, tempid, tempdiem);
		l.tangSL();
	} while (!fi.eof());
}



int main()
{
	Lop l;
	string filename("Danhsach.csv");
	InputInfoSVFromFile(l, filename);
	char k;
	do
	{
		cout <<"==== Lua chon: ==="
			"\na.In danh sach sinh vien ra man hinh"
			"\nb.Liet ke nhung sinh vien co diem trung binh cao nhat trong lop hoc."
			"\nc.Cho biet so sinh vien co diem trung binh >= 5."
			"\nd.Tim mot sinh vien co ten X trong lop hoc(X nhap tu ban phim)"
			"\ne.Xoa mot sinh vien co ma so cho truoc trong lop hoc."
			"\n----nhap 'a' hoac 'b', hoac 'c' hoac 'd', hoac 'e' de xem ket qua or '0' to end!----" << endl;
		cin >> k;
		if (k == 'a')
			l.XuatDanhSach();
		else if (k == 'b')
			l.LietKeDiemCaoNhat();
		else if (k == 'c')
			l.LietKeDiemCaoHon4();
		else if (k == 'd')
			l.TimSinhVien();
		else if (k == 'e')
			l.XoaSinhVienCoMa();
	} while (k!='0');
	return 0;
}