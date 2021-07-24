#include "DaThuc.h"
#include <string>

using namespace std;

int main()
{
    DaThuc dt;
    DaThuc temp[10];
    DaThuc kq;
    string control;
    int flag;
    int flag_3d;
    int x;
    float gia_tri;
    while (true)
    {
        cout << "(1) Nhap/Xuat da thuc\n(2) Xac dinh bac cua da thuc\n(3) Tinh gia tri da thuc\n(4) Cong, tru, nhan, da thuc\n";
        cout << "Nhap lua chon (1 -> 4): ";
        cin >> flag;
        switch (flag)
        {
            case 1:
            {
                NhapDaThuc(dt);
                XuatDaThuc(dt);
                break;   
            }
            case 2:
            {
                NhapDaThuc(dt);
                XuatDaThuc(dt);
                SapXepDaThuc(dt);
                cout << "Bac cua da thuc: " << dt.bac << endl;
                XuatDaThuc(dt);
                break;   
            }
            case 3:
            {
                NhapDaThuc(dt);
                XuatDaThuc(dt);

                cout << "Tinh gia tri cua don thuc tai x = ";
                cin >> x;
                gia_tri = TinhGiaTriDaThuc(dt, x);
                cout << "=> P(" << x << ")" << "= " << gia_tri << endl;
                break;
            }
            case 4:
            {
                
                for (int i=0; i<2; i++){
                    cout << "Nhap da thuc thu " << i + 1 << ":" << endl;
                    NhapDaThuc(temp[i]);
                    XuatDaThuc(temp[i]);
                    cout << endl;
                }
                cout << "(1) Cong; (2) Tru; (3) Nhan" << endl;
                cout << "Nhap lua chon (1->3): ";
                cin >> flag_3d;
                switch (flag_3d)
                {
                case 1:
                    kq = CongDaThuc(temp[0], temp[1]);
                    cout << "P1(x) + P2(x) = ";
                    XuatDaThuc(kq);
                    break;
                
                case 2:
                    kq = TruDaThuc(temp[0], temp[1]);
                    cout << "P1(x) + P2(x) = ";
                    XuatDaThuc(kq);
                    break;
                
                case 3:
                    kq = NhanDaThuc(temp[0], temp[1]);
                    cout << "P1(x) * P2(x) = ";
                    XuatDaThuc(kq);
                    break;
                    break;
                }

                break;
            }
        }
        cout << endl;        
        cout << "Tiep tuc ? (y/n) ";
        cin.ignore();
        cin >> control;
        if (control == "y")
            continue;
        else
        {
            cout << endl;
            cout << "Cam on ban da su dung chuong trinh!";
            break;
        }
    }
    return 1;
}
