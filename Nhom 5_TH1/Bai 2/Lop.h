#include"SinhVien.h"

class Lop
{
private:

	int sl; //So luong sinh vien
	SinhVien* sHead; //luu dia chi cua sinh vien dau
	SinhVien* sTail; //luu dia chi cua sinh vien cuoi

public:
	//gia tri mac dinh cua lop khi duoc khoi tao
	Lop()
	{
		sl = 0;
		sHead = NULL;
		sTail = NULL;
	}

	//cong so luong sinh vien 1 sinh vien
	void tangSL()
	{
		sl = sl + 1;
	}

	//tao sinh vien o dau do va tra ve dia chi
	SinhVien* CreateSinhVien(string& Newname, string& NewID, float& NewDiem)
	{
		SinhVien* newSV;          //tao sinh vien o dau do
		newSV = new SinhVien;
		newSV->SetName(Newname);  //cai dat ten cho sinh vien duoc tao
		newSV->SetID(NewID);      //cai dat ma cho sinh vien duoc tao
		newSV->SetDiem(NewDiem);  //cai dat diem cho sinh vien duoc tao
		return newSV;           // tra ve dia cchi cua sinh vien duoc tao
	}

	//add sinh vien o dau do vao trong mang khi co dia chi
	void AddTail(string& Newname, string& NewID, float& NewDiem)
	{
		SinhVien* temp;                                   //tao dia chi luu sinh vien moi
		temp = CreateSinhVien(Newname, NewID, NewDiem);   //tao sinh vien moi 
		if (sHead == NULL)                               //neu mang con rong
		{
			sHead = temp;
			sTail = temp;
		}
		else                                   //nguoc lai, mang da co phan tu
		{
			temp->SetsPrevious(sTail);
			sTail->SetsNext(temp);
			sTail = temp;
		}
	}

	//Xuat danh sach lop ra man hinh
	void XuatDanhSach()
	{
		SinhVien* temp;
		temp = sHead;
		cout << "\n***********Danh sach*******\n" << endl;
		cout << "Stt" << "\tTen" << endl;
		for (int i = 0; i < sl; i++)
		{
			cout << i + 1 << ".\t" << temp->GetName() << endl;
			temp = temp->GetsNext();
		}
	}

	//Liet ke danh sach diem trung binh cao nhat
	void LietKeDiemCaoNhat()
	{
		SinhVien* comp;
		float diemcaonhat = 0;
		comp = sHead;
		cout << "\n*******Cac sinh vien co diem cao nhat*****\n" << endl;
		cout << "Stt" << "\tTen" /*<< "\t\tMaSinhVien" << "\t\tDiemTB" */ << endl;
		for (int i = 0; i < sl; i++)
		{
			if (diemcaonhat <= comp->GetDiem())
			{
				diemcaonhat = comp->GetDiem();
			}
			comp = comp->GetsNext();  //cho chay tiep toi sinh vien phia sau
		}
		comp = sHead;
		for (int i = 0; i < sl; i++)
		{
			if (diemcaonhat == comp->GetDiem())
			{
				cout << i + 1 << ".\t" << comp->GetName() << ": " << comp->GetDiem() << "d" << endl;
			}
			comp = comp->GetsNext(); //cho chay tiep toi sinh vien phia sau
		}
		comp = nullptr;
		delete[]comp;
	}

	//Liet ke sinh vien co diem trung binh cao hon = 5. Neu khong co thong bao khong co
	void LietKeDiemCaoHon4()
	{
		SinhVien* temp;
		SinhVien* comp;
		bool flag = 0;
		cout << "\n*******Cac sinh vien co diem cao hon hoac bang 5*****\n" << endl;
		cout << "Stt" << "\tTen" << endl;
		comp = sHead;
		temp = sHead;
		for (int i = 0; i < sl; i++)
		{
			if (5 <= comp->GetDiem())
			{
				cout << i + 1 << ".\t" << temp->GetName() << ": " << temp->GetDiem() << "d" << endl;
				flag = 1;
			}
			comp = temp->GetsNext(); //cho chay tiep toi sinh vien phia sau
			temp = comp; //cho chay tiep toi sinh vien phia sau
		}
		if (!flag)
			cout << "\nkhong co sinh vien nao >= 5d." << endl;

		delete[]temp;
		delete[]comp;
	}

	//Tim sinh vien co ten xxx trong lop hoc.
	void TimSinhVien()
	{
		string newname;
		SinhVien* temp;
		temp = sHead;
		bool flag = 0;
		cout << "Nhap ten (khong bo dau): ";
		cin.ignore();
		getline(cin, newname);
		for (int i = 0; i < sl; i++)
		{
			if (newname.compare(temp->GetName()) == 0)
			{
				cout << "\nsinh vien: " << temp->GetName() << "-" << temp->GetID() << endl;
				flag = 1;
			}
			temp = temp->GetsNext();
		}
		if (!flag)
		{
			cout << "\nkhong co sinh vien nao co ten vua nhap!" << endl;
		}
	}

	//Xoa sinhvien dau mang
	void XoaDau()
	{
		sHead->GetsNext()->SetsPrevious(sHead);
		sHead = sHead->GetsNext();
		sl = sl - 1;
	}

	//Xoa sinhvien cuoi mang
	void XoaCuoi()
	{
		sTail->GetsPrevious()->SetsNext(NULL);
		sTail = sTail->GetsPrevious();
		sl = sl - 1;
	}

	//Xoa sinhvien thu k trong mang
	void XoaSinhVienThuK(int k)
	{
		SinhVien* temp;
		temp = sHead;

		for (int i = 0; i < sl; i++)
		{
			if (i == k)
			{
				temp->GetsPrevious()->SetsNext(temp->GetsNext());
				temp->GetsNext()->SetsPrevious(temp->GetsPrevious());
				 sl = sl - 1;
				break;
			}
			temp = temp->GetsNext();
		}
	}

	//Xoa sinh vien co ma cho truoc
	void XoaSinhVienCoMa()
	{
		SinhVien* temp;
		temp = sHead;
		bool flag = 0;
		cout << "\nNhap ma sinh vien can xoa: ";
		string idxoa;
		cin.ignore();
		getline(cin, idxoa);
		
		for (int i = 0; i < sl; i++)
		{
			if (idxoa.compare(temp->GetID()) == 0)
			{
				cout << "ok";
				if (i==0)
				{
					XoaDau();
					flag = 1;
				}
				else if (i==(sl-1))
				{
					XoaCuoi();
					flag = 1;
				}
				else
				{
					XoaSinhVienThuK(i);
					flag = 1;
				}
			}
			temp = temp->GetsNext();
		}
		if (!flag)
		{
			cout << "\nkhong co sinh vien nao co ma so nay!" << endl;
		}
		else
		{
			cout << "\nda xoa!" << endl;
		}
	}

};

