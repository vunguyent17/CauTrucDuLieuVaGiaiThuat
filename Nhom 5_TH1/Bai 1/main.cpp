#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int*& a, int& n);
void Xuat(int* a, int n);
void XoaPhanTu(int* a, int& n, int k);
int Tim_Max(int* arr, int n);
void LietKePhanTuGiaTriLonNhat(int* a, int n);
int Tim_Min(int* arr, int n);
void LietKePhanTuGiaTriNhoNhat(int* a, int n);
int DemPhanTuAm(int* a, int n);
int AmDauTien(int* a, int n);
int AmLonNhat(int* a, int n);
int DuongDauTien(int* a, int n);
int DuongNhoNhat(int* a, int n);
int ktPhanTuTrongMang(int* a, int n, int x);
int DemSoPhanTuX(int* a, int n, int x);

int main()
{
	int* a;		//Mang a cac so nguyen
	int n;		//So luong cac phan tu trong mang

	int c;		//Cac lua chon yeu cau chuong trinh
	int temp;	//Bien phu
	int x;		//So nguyen nguoi dung nhap de tim kiem trong mang

	//a.Xuat mang 1 chieu noi tren ra man hinh.
	Nhap(a, n);
	Xuat(a, n);

	while (true)
	{
		do
		{
			cout << "Co cac lua chon sau:\n\t1. Xoa 1 phan tu tai chi so K trong mang."
				"\n\t2. Liet ke nhung phan tu mang gia tri lon nhat trong mang"
				"\n\t3. Liet ke nhung phan tu mang gia tri nho nhat trong mang"
				"\n\t4. Dem so phan tu co gia tri am trong mang"
				"\n\t5. Cho biet gia tri am lon nhat trong mang."
				"\n\t6. Cho biet gia tri duong nho nhat trong mang."
				"\n\t7. Tim mot phan tu co khoa bang X co hay khong trong mang(dung thuat toan tim kiem tuyen tinh)"
				"\n\t8. Dem so phan tu co gia tri bang X trong mang."
				"\n\t0. Ket thuc" 
				"\n\t-- Hay nhap mot con so: ";
			cin >> c;
			if (c < 0 || c>8)
			{
				cout << "Khong co lua chon co san, xin moi nhap lai." << endl;
			}
		} while (c < 0 || c>8);
		
		if (c == 0)
		{
			cout << "Chuong trinh ket thuc." << endl;
			break;
		}

		switch (c)
		{
		case 1:
			//b.Xoa 1 phan tu tai chi so K trong mang.
			int k;
			do
			{
				cout << "Ban muon xoa phan tu thu may? Chon mot so tu 0 den " << n-1 << ": ";
				cin >> k;
				if (k < 0 || k >= n)
				{
					cout << "Thu tu phan tu phai lon hon hoac bang 0 va nho hon " << n << ". Yeu cau nhap lai." << endl;
				}
			} while (k < 0 || k >= n);

			XoaPhanTu(a, n, k);
			cout << "Da xoa mot phan tu trong mang." << endl;
			Xuat(a, n);
			break;
		case 2:
			//c.Liet ke nhung phan tu mang gia tri lon nhat trong mang
			LietKePhanTuGiaTriLonNhat(a, n);
			break;
		case 3:
			//d.Liet ke nhung phan tu mang gia tri nho nhat trong mang
			LietKePhanTuGiaTriNhoNhat(a, n);
			break;
		case 4:
			//e.Dem so phan tu co gia tri am trong mang
			cout << "So phan tu co gia tri am trong mang: " << DemPhanTuAm(a, n) << endl;
			break;
		case 5:
			//f.Cho biet gia tri am lon nhat trong mang.
			temp = AmLonNhat(a, n);
			if (temp != 0)
			{
				cout << "Gia tri am lon nhat trong mang: " << temp << endl;
			}
			else
			{
				cout << "Khong co gia tri am trong mang." << endl;
			}
			break;
		case 6:
			//g.Cho biet gia tri duong nho nhat trong mang
			temp = DuongNhoNhat(a, n);
			if (temp != 0)
			{
				cout << "Gia tri duong nho nhat trong mang: " << temp << endl;
			}
			else
			{
				cout << "Khong co gia tri duong trong mang." << endl;
			}
			break;
		case 7:
			//h.Tim mot phan tu co khoa bang X co hay khong trong mang(dung thuat toan tim kiem tuyen tinh)
			cout << "Nhap gia tri x = ";
			cin >> x;

			temp = ktPhanTuTrongMang(a, n, x);
			if (temp >= 0)
			{
				cout << "Gia tri x co trong mang, la phan tu thu " << temp << endl;
			}
			else
			{
				cout << "Khong co gia tri " << x << " trong mang." << endl;
			}
			break;
		case 8:
			//i.Dem so phan tu co gia tri bang X trong mang.Neu khong co thi thong bao khong co.
			cout << "Nhap gia tri x = ";
			cin >> x;
			temp = DemSoPhanTuX(a, n, x);
			if (temp != 0)
			{
				cout << "So phan tu co gia tri " << x << " trong mang: " << temp << endl;
			}
			else
			{
				cout << "Khong co gia tri " << x << " trong mang." << endl;
			}
			break;
		default:
			break;
		}
		system("pause");
	}
	delete[]a;
	return 1;
}

void Nhap(int*& a, int& n)
{
	do
	{
		cout << "Nhap so luong phan tu cua mang: ";
		cin >> n;
		if (n<=0)
		{
			cout << "So luong phan tu cua mang phai la mot so duong. Xin hay nhap lai." << endl;
		}
	} while (n<=0);
	
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "\tNhap phan tu thu " << i << ": ";
		cin >> a[i];
	}
}

void Xuat(int* a, int n)
{
	cout << "Cac phan tu trong day la: ";
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << a[i];
	}
	cout << endl;
}

//b.Xoa 1 phan tu tai chi so K trong mang.
void XoaPhanTu(int* a, int& n, int k)
{
	n = n - 1;
	for (int i = k; i < n; i++)
	{
		a[i] = a[i + 1];
	}
}

//c.Liet ke nhung phan tu mang gia tri lon nhat trong mang
int Tim_Max(int* arr, int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}


void LietKePhanTuGiaTriLonNhat(int* a, int n)
{
	int ln = Tim_Max(a, n);
	cout << "Gia tri lon nhat trong mang la: " << ln << endl;
	cout << "Cac phan tu mang gia tri lon nhat: ";
	for (int i = 0; i < n; i++)
	{
		if (ln == a[i])
		{
			cout << setw(4) << a[i];
		}
	}
	cout << endl;
}

//d.Liet ke nhung phan tu mang gia tri nho nhat trong mang
int Tim_Min(int* arr, int n) {
	int min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

void LietKePhanTuGiaTriNhoNhat(int* a, int n)
{
	int nn = Tim_Min(a, n);
	cout << "Gia tri nho nhat trong mang la: " << nn << endl;
	cout << "Cac phan tu mang gia tri nho nhat: ";
	for (int i = 0; i < n; i++)
	{
		if (nn == a[i])
		{
			cout << setw(4) << a[i];
		}
	}
	cout << endl;
}

//e.Dem so phan tu co gia tri am trong mang
int DemPhanTuAm(int* a, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			dem++;
		}
	}
	return dem;
}

//f.Cho biet gia tri am lon nhat trong mang.
int AmDauTien(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			return a[i];
		}
	}
	return 0;
}

int AmLonNhat(int* a, int n)
{
	int kq = AmDauTien(a, n);
	if (kq < 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] < 0 && kq < a[i])
			{
				kq = a[i];
			}
		}
	}
	return kq;
}

//g.Cho biet gia tri duong nho nhat trong mang.
int DuongDauTien(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			return a[i];
		}
	}
	return 0;
}

int DuongNhoNhat(int* a, int n)
{
	int kq = DuongDauTien(a, n);
	if (kq > 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] > 0 && kq > a[i])
			{
				kq = a[i];
			}
		}
	}
	return kq;
}

//h.Tim mot phan tu co khoa bang X co hay khong trong mang(dung thuat toan tim kiem tuyen tinh)
int ktPhanTuTrongMang(int* a, int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//i.Dem so phan tu co gia tri bang X trong mang.Neu khong co thi thong bao khong co.
int DemSoPhanTuX(int* a, int n, int x)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			dem++;
		}
	}
	return dem;
}
