#pragma once
#include <iostream>
#include <string>
using namespace std;
class OTo
{
protected:
	string ten_loai = "";
	int so_cho_ngoi = 0;
	float tai_trong = 0;
	int thoi_gian_vao_cong = 0;
	int thoi_gian_qua_tram = 0;
	int phi_qua_tram = 0;
public:
	int Loai = 0;
	OTo()
	{
		ten_loai = "";
		so_cho_ngoi = 0;
		tai_trong = 0;
		thoi_gian_qua_tram = 0;
		phi_qua_tram = 0;
	}
	
	void Xuat()
	{
		cout << "Loai xe: " << ten_loai << ". Tai trong: " << tai_trong << ". So cho ngoi: " << so_cho_ngoi << endl <<
			"\tThoi gian qua tram: " << thoi_gian_qua_tram << ". Phi qua tram: " << phi_qua_tram << endl;
	}

	string getTenLoai()
	{
		return ten_loai;
	}

	int getThoiGianQuaTram()
	{
		return thoi_gian_qua_tram;
	}

	int getPhiQuaTram()
	{
		return phi_qua_tram;
	}

	int getThoiGianVaoCong()
	{
		return thoi_gian_vao_cong;
	}

	void setThoiGianVaoCong(int x)
	{
		thoi_gian_vao_cong = x;
	}
	void setSoChoNgoi(int new_so_cho_ngoi)
	{
		so_cho_ngoi = new_so_cho_ngoi;
	}
	void setTaiTrong(float new_tai_trong)
	{
		tai_trong = new_tai_trong;
	}
};

