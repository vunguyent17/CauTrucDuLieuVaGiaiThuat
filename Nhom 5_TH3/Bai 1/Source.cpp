#include "StackClass.h"

int main() {
    int lc;
    StackClass S;
    //ta thực hiện thêm một vài phần tử vào stack
    //cụ thể ta sẽ thêm những số sau: 10, 11, 12, 13, 14, 15, 16
    cout << "Danh sach cac so bao gom: 10, 11, 12, 13, 14, 15, 16";
    for (int i = 10; i <= 16; i++) {
        S.push(i);
    }
    do {
        cout << "\n\n\t\t ============== Menu ==============";
        cout << "\n\t1. Hien thi phan tu dau Stack";
        cout << "\n\t2. Xoa phan tu dau Stack";
        cout << "\n\t3. Xuat cac phan tu cua Stack";
        cout << "\n\t0. Ket thuc";
        cout << "\n\n\t\t ============== End ==============";
        cout << "\nNhap lua chon ban muon chon: ";
        cin >> lc;
        switch (lc) {
        case 0: break;
        case 1:
            cout << "Phan tu dau tien trong Stack: " << S.top();
            break;
        case 2:
            S.pop();
            cout << "Xoa phan tu top thanh cong !!!" << endl;
            S.Xuat();
            break;
        case 3:
            S.Xuat();
            break;
        default:
            cout << "\nNhap sai, vui long nhap lai!";
        }
    } while (lc);
}