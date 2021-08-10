#pragma once
#include "QueueOTo.h"
#include "vector"
#include <ctime>

class TramThuPhi
{
private:
	QueueOTo waiting_queue;		//Hang xe cho (trong truong hop hang doi cua cac cong deu day 10 xe)
	QueueOTo_Gate gate_no_[4];	//Hang xe chinh cua 4 cong
	int thoi_gian = 0;			//Thoi gian mo phong
public:
	const int SO_CONG = 4;
	int so_xe_da_qua_tram = 0;

	//Tinh so xe it nhat mot hang trong hang xe cua 4 cong
	int SoXeItNhat()
	{
		int min_xe = gate_no_[0].getSoLuongXeDoi();
		for (int i = 0; i < SO_CONG; i++)
		{
			int temp_xe = gate_no_[i].getSoLuongXeDoi();
			if (min_xe > temp_xe)
			{
				min_xe = temp_xe;
			}
		}
		return min_xe;
	}
	
	//Chon 1 cong trong so 4 cong chinh cua tram de them xe tu hang phu
	int ChonGateThemXe()
	{
		int min_xe = SoXeItNhat();

		//Tim cong co so luong xe dang doi it nhat
		vector<int> gate_chosen;
		for (int i = 0; i < SO_CONG; i++)
		{
			int temp_xe = gate_no_[i].getSoLuongXeDoi();
			if (temp_xe == min_xe)
			{
				gate_chosen.push_back(i);
			}
		}

		//Truong hop chi co 1 cong co so xe it nhat
		if (gate_chosen.size() == 1)
		{
			return gate_chosen[0];
		}
		else	//Truong hop nhieu cong co cung so xe it nhat: chon hang co tong thoi gian can xu ly it nhat
		{
			int kq = gate_chosen[0];
			int temp_time = gate_no_[kq].TongThoiGianCanXuLy(thoi_gian);
			for (int i = 0; i < gate_chosen.size(); i++)
			{
				int x = gate_chosen[i];
				if (temp_time > gate_no_[x].TongThoiGianCanXuLy(thoi_gian))
				{
					kq = x;
					temp_time = gate_no_[x].TongThoiGianCanXuLy(thoi_gian);
				}
			}
			return kq;
		}
	}

	bool isFull()
	{
		for (int i = 0; i < SO_CONG; i++)
		{
			if (!gate_no_[i].isFull())
			{
				return 0;
			}
		}
		return 1;
	}

	//Xep loai o to den dua tren so cho ngoi va tai trong
	int XepLoaiOToDen(int so_cho_ngoi, float tai_trong)
	{
		if (so_cho_ngoi > 35 || tai_trong > 7)
			return 4;
		if (so_cho_ngoi >= 15 || tai_trong >= 3.5)
			return 3;
		if (so_cho_ngoi >= 8 || tai_trong >= 1.5)
			return 2;
		return 1;
	}

	//Dua vao ham XepLoaiOToDen, tao doi tuong OTo
	OTo* OToDen()
	{
		int so_cho_ngoi = rand() % 43 + 2;					//tao so cho ngoi tren xe ngau nhien tu 2 den 45 cho ngoi
		float tai_trong = (float)rand() / (RAND_MAX / 10) + 0.1;	//tao tai trong xe ngau nhien tu 0.1 tan den 10 tan
		OTo* xe = new OTo;

		int loai_o_to = XepLoaiOToDen(so_cho_ngoi, tai_trong);
		switch (loai_o_to)
		{
		case 1:
			xe = new OToNho;
			break;
		case 2:
			xe = new OToTrungBinh;
			break;
		case 3:
			xe = new OToLon;
			break;
		case 4:
			xe = new OToHangNang;
			break;
		default:
			break;
		}
		xe->setSoChoNgoi(so_cho_ngoi);
		xe->setTaiTrong(tai_trong);
		return xe;
	}

	//Dieu khien thoi gian xuat hien xe vao tram
	void ThemOToVaoHangCho(int speed, bool is_random)
	{
		if (thoi_gian % speed == 0 && rand() % 2 && is_random || thoi_gian % speed == 0 && !is_random)
		{
			OTo* xe = OToDen();
			xe->setThoiGianVaoCong(thoi_gian);
			waiting_queue.EnQueue(*xe);
		}
	}

	//Dua o to tu hang cho vao hang chinh cua cong va thong bao
	void DuaOToVaoGate()
	{
		if (!isFull() && !waiting_queue.isEmpty())
		{
			OTo xe;
			waiting_queue.DeQueue(xe);
			int c = ChonGateThemXe();
			gate_no_[c].EnQueue(xe);
			cout << " 1 " << xe.getTenLoai() << " da vao Gate no. " << c << endl;
		}
	}

	///Hien thi thong tin cua hang xe chinh cua cac cong va hang xe cho
	void XuatThongTinTram()
	{
		for (int i = 0; i < SO_CONG; i++)
		{
			cout << " -- Gate No." << i << " (SL dang cho: " << setw(2) << gate_no_[i].getSoLuongXeDoi() << ")";
			cout << "(Total time remaining: " << setw(3) << gate_no_[i].TongThoiGianCanXuLy(thoi_gian) << ")";
			cout << setw(8) << gate_no_[i].getSoTien() << "d" << setw(2) << " | ";
			gate_no_[i].Xuat();
		}
		cout << " -- Hang doi: ";
		waiting_queue.Xuat();
		cout << "Tong so luong xe da qua tram: " << so_xe_da_qua_tram << endl;
	}

	//Ham xu ly qua trinh thong xe cho cac cong
	void ThongXe()
	{
		for (int i = 0; i < SO_CONG; i++)
		{
			if (!gate_no_[i].isEmpty())
			{
				OTo xe = gate_no_[i].XuLy(thoi_gian);
				if (xe.getTenLoai() != "")
				{
					cout << " ** GATE NO. " << i << " DA THU PHI MOT XE (VAO TU GIAY " << xe.getThoiGianVaoCong()
						<< ")\n\tThong tin xe ---> ";
					xe.Xuat();
					cout << "\tSo tien hien tai cua Gate no. " << i << ": " << gate_no_[i].getSoTien() << endl;
					so_xe_da_qua_tram++;
				}
			}
		}
	}

	//Ham dieu chinh thoi gian trong mo phong
	void ChayThoiGian()
	{
		Sleep(1000);
		thoi_gian++;
		cout << "GIAY " << thoi_gian << ":" << endl;
		for (int i = 0; i < SO_CONG; i++)
		{
			//Truong hop khong co xe thi moc thoi gian thong xe truoc do gan bang thoi gian mo phong
			if (gate_no_[i].isEmpty())
			{
				gate_no_[i].setMocThoiGian(thoi_gian);
			}
		}
	}

	//Ham chay mo phong
	void TienHanh()
	{
		string s = "";
		int t = 0;
		int speed = 1;
		bool is_random = true;
		do
		{
			cout << "Ban muon chay toi giay bao nhieu (nhap mot so nguyen duong): ";
			cin >> t;
			cout << "Ban muon bao nhieu giay thi 1 xe toi tram (nhap mot so nguyen duong): ";
			cin >> speed;
			cout << "Ban muon xe den tram vao thoi gian ngau nhien? Nhap 0 (khong ngau nhien) hoac 1 (co ngau nhien): ";
			cin >> is_random;
			cin.ignore();
			
			while (thoi_gian < t)
			{
				ChayThoiGian();
				ThemOToVaoHangCho(speed, is_random);
				ThongXe();
				DuaOToVaoGate();
				XuatThongTinTram();
			}
			cout << "Tiep tuc? (y/n): ";
			getline(cin, s);
		
		} while (s == "y");
	}
};

