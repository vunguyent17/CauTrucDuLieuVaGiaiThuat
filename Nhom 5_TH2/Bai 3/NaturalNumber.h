#pragma once
#include"ChuSo.h"


class NaturalNumber
{
private:
	unsigned int sl;
	ChuSo* sHead;
	ChuSo* sTail;
public:
	NaturalNumber()
	{
		sHead = NULL;
		sTail = NULL;
		sl = 0;
	}

	void AddDauTien(ChuSo* temp, int nu)
	{
		temp->SetSo(nu);
		sHead = temp;
		sTail = temp;
	}

	void AddTail(ChuSo* temp, int nu)
	{
		temp->SetSo(nu);
		temp->SetPrevious(sTail);
		sTail->SetNext(temp);
		sTail = temp;
	}
	
	void AddHead(ChuSo* temp, int nu)
	{
		temp->SetSo(nu);
		temp->SetNext(sHead);
		sHead->SetPrevious(temp);
		sHead = temp;
	}

	void InputNumber()
	{
		sHead = NULL;
		sTail = NULL;
		sl = 0;
		int so;
		string stn, bien;
		getline(cin, stn);
		sl = stn.length();
		ChuSo* temp;
		for (unsigned int i = 0; i < sl; i++)
		{
			temp = new ChuSo;
			if (sHead == NULL && sTail == NULL)
			{
				bien.assign(stn, sl - (sl - i), 1);
				stringstream str2um(bien);
				str2um >> so;
				AddDauTien(temp, so);
			}
			else
			{
				bien.assign(stn, sl - (sl - i), 1);
				stringstream str2um(bien);
				str2um >> so;
				AddTail(temp, so);
			}
		}
		temp = NULL;
		delete temp;
	}

	NaturalNumber operator+(NaturalNumber b)
	{
		ChuSo* temptong;
		ChuSo* tempa = NULL;
		ChuSo* tempb = NULL;
		NaturalNumber tong;
		bool is = 0;
		unsigned int numbera;
		unsigned int numberb;
		unsigned int n;
		numbera = sl; numberb = b.sl;
		if (numbera < numberb)
			n = numbera;
		else
			n = numberb;
		if (sHead == NULL)
		{
			tong.sHead = b.sHead;
			tong.sTail = b.sTail;
			tong.sl = b.sl;
		}
		else if (b.sHead==NULL)
		{
			tong.sHead = sHead;
			tong.sTail = sTail;
			tong.sl = sl;
		}
		else
		{
			for (unsigned int i = 0; i < n; i++)
			{
				temptong = new ChuSo;
				if (tong.sHead == NULL && tong.sTail == NULL)
				{
					tempa = sTail;
					tempb = b.sTail;
					temptong->SetSo(tempa->GetSo() + tempb->GetSo() + is);
					if (temptong->GetSo() >= 10)
					{
						temptong->SetSo(temptong->GetSo() - 10);
						is = 1;
					}
					tong.sHead = temptong;
					tong.sTail = temptong;
					tempa = tempa->GetPrevious();
					tempb = tempb->GetPrevious();
					tong.sl++;
				}
				else
				{
					temptong->SetSo(tempa->GetSo() + tempb->GetSo() + is);
					is = 0;
					if (temptong->GetSo() >= 10)
					{
						temptong->SetSo(temptong->GetSo() - 10);
						is = 1;
					}
					tong.sHead->SetPrevious(temptong);
					temptong->SetNext(tong.sHead);
					tong.sHead = temptong;
					tempa = tempa->GetPrevious();
					tempb = tempb->GetPrevious();
					tong.sl++;
				}
			}
			long int tt = numbera - numberb;
			n = abs(tt);
			for (unsigned int i = 0; i < n; i++)
			{
				if (tempa == NULL)
				{
					temptong = new ChuSo;
					temptong->SetSo(tempb->GetSo() + is);
					is = 0;
					if (temptong->GetSo() >= 10)
					{
						temptong->SetSo(temptong->GetSo() - 10);
						is = 1;
					}
					tong.sHead->SetPrevious(temptong);
					temptong->SetNext(tong.sHead);
					tong.sHead = temptong;
					tempb = tempb->GetPrevious();
					tong.sl++;
				}
				else if (tempb == NULL)
				{
					temptong = new ChuSo;
					temptong->SetSo(tempa->GetSo() + is);
					is = 0;
					if (temptong->GetSo() >= 10)
					{
						temptong->SetSo(temptong->GetSo() - 10);
						is = 1;
					}
					tong.sHead->SetPrevious(temptong);
					temptong->SetNext(tong.sHead);
					tong.sHead = temptong;
					tempa = tempa->GetPrevious();
					tong.sl++;
				}
			}
			if (is)
			{
				temptong = new ChuSo;
				temptong->SetSo(1);
				is = 0;
				tong.sHead->SetPrevious(temptong);
				temptong->SetNext(tong.sHead);
				tong.sHead = temptong;
				tong.sl++;
			}
		}
		tempa = NULL;
		tempb = NULL;
		temptong = NULL;
		delete tempa;
		delete tempb;
		delete temptong;
		return tong;
	}

	NaturalNumber operator*(ChuSo* a)
	{
		NaturalNumber L;
		int bien;
		int is = 0;
		ChuSo* tempn = sTail;
		ChuSo* temp;
		for (unsigned int i = 0; i < sl; i++)
		{
			temp = new ChuSo;
			bien = (a->GetSo() * tempn->GetSo()) + is;
			is = 0;
			while (bien >= 10)
			{
				is = bien / 10;
				bien = bien % 10;
			}
			if (L.sHead == NULL && L.sTail == NULL)
			{
				L.AddDauTien(temp, bien);
				L.sl++;
				tempn = tempn->GetPrevious();
			}
			else
			{
				L.AddHead(temp, bien);
				L.sl++;
				tempn = tempn->GetPrevious();
			}
		}
		if (is > 0)
		{
			temp = new ChuSo;
			L.AddHead(temp, is);
			L.sl++;
		}
		temp = NULL;
		tempn = NULL;
		delete temp;
		delete tempn;
		return L;
	}

	NaturalNumber operator*(NaturalNumber b)
	{

		ChuSo* temp = sTail;
		NaturalNumber tich;
		for (unsigned int i = 0; i < sl; i++)
		{
			NaturalNumber tichtemp;
			tichtemp = b * temp;
			tichtemp.Nhan10Mu(i);
			temp = temp->GetPrevious();
			tich = tich + tichtemp;
			if (tich.sHead != tichtemp.sHead)
			{
				tichtemp.XoaNaturalNumber();
			}

		}
		return tich;
	}

	void XoaNaturalNumber()
	{
		ChuSo* temp = sHead;
		for (unsigned int i = 0; i < sl; i++)
		{
			temp->SetSo(NULL);
			temp = temp->GetNext();
		}
	}

	void Nhan10Mu(int n)
	{
		for (int i = 0; i < n; i++)
		{
			ChuSo* temp = new ChuSo;
			AddTail(temp, 0);
			sl++;
			temp = NULL;
			delete temp;
		}
	}

	void Output()
	{
		ChuSo* temp = sHead;
		for (unsigned int i = 0; i < sl; i++)
		{
			cout << temp->GetSo();
			temp = temp->GetNext();
		}
		cout << "\n";
		temp = NULL;
		delete temp;
	}
};

