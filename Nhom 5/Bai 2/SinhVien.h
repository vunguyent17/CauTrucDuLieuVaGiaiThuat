#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class SinhVien  //lop sinh vien
{

private:                    // thanh phan bao mat
	SinhVien* sPrevious;        //contro luu dia chi sinh vien truoc
	string Name;            //ten sinh vien
	string IDStudent;       //ma sinh vien
	float DiemTB;           //diem sinh vien
	SinhVien* sNext;        //contro luu dia chi sinh vien ke tiep

public:

	SinhVien()       //gia tri sinh vien mac dinh khi duoc khoi tao
	{
		sNext = NULL;
		DiemTB = 0;
		sPrevious = NULL;
	}

	void SetName(string a)       //cai dat ten sinh vien
	{
		Name = a;
	}

	string GetName()             //tra ve ten sinh vien
	{
		return Name;
	}

	void SetID(string a)       //caidat ma sinh vien
	{
		IDStudent = a;
	}

	string GetID()             //tra ve ma sinh vien
	{
		return IDStudent;
	}

	void SetDiem(float d)       //caidat diem sinh vien
	{
		DiemTB = d;
	}

	float GetDiem()             //tra ve diem sinh vien
	{
		return DiemTB;
	}

	void SetsPrevious(SinhVien* a)       //caidat dia chi sinh vien truoc
	{
		sPrevious = a;
	}

	SinhVien* GetsPrevious()             //tra ve dia chi sinh vien truoc
	{
		return sPrevious;
	}

	void SetsNext(SinhVien* a)       //caidat dia chi sinh vien ke tiep
	{
		sNext = a;
	}

	SinhVien* GetsNext()             //tra ve dia chi sinh vien ke tiep
	{
		return sNext;
	}
};

