/**** Tạo hàng đợi Queue bằng danh sách liên kết đơn ****/
#include <iostream>
#include <iomanip>
using namespace std;

/* tạo cấu trúc của Node trong danh sách liên kết */
struct Node {
    Node* next;
    int data;
};

/* tạo cấu trúc của hàng đợi Queue */
struct Queue {
    Node* head, * tail;
};

/* khởi tạo rỗng cho Node trong danh sách liên kết */
void Init(Queue& q) {
    q.head = q.tail = NULL;
}

/* hàm tạo một Node mới */
Node* createNode(int x) {
    Node* p = new Node;
    if (!p) exit(1);
    p->next = NULL;
    p->data = x;
    return p;
}

/* hàm thêm phần tử vào đầu trong hàng đợi Queue */
void Push(Queue& q, Node* p) {
    //kiểm tra nếu hàng đợi rỗng thì phần tử thêm vào chính là pHead và pTail
    if (!q.head) q.head = q.tail = p;
    //Nếu trong danh sách đã tồn tại phần tử thì cho pNext của pTail trỏ tới node p
    //khi đó node p chính là pTail
    else {
        q.tail->next = p;
        q.tail = p;
    }
}

/* hàm lấy phần tử đầu trong hàng đợi, nhưng không xóa nó */
int Top(Queue q) {
    //kiểm tra nếu hàng đợi tồn tại phần tử thì ta thực hiện return phần tử đầu tiên
    if (q.head) {
        return q.head->data;
    }
    //Nếu trong hàng đợi rỗng thì return 0 và kết thúc hàm
    else
        cout << "(Queue rong) " << endl;
        return 0;
}

/* hàm xóa phần tử đầu trong hàng đợi */
int Pop(Queue& q) {
    //kiểm tra nếu hàng đợi tồn tại thì thực hiện các câu lệnh
    if (q.head) {
        //tạo mới một Node p (là node thay thế cho node cần xóa)
        Node* p = q.head;
        int x = p->data;
        //trỏ con trỏ Next đến phần tử tiếp theo để có thể xóa phần tử đầu
        q.head = q.head->next;
        //sau khi return thì thực hiện xóa nó khỏi hàng đợi
        delete p;
        cout << "Xoa thanh cong, vui long nhap 2 de kiem tra lai!!";
        return x;
    }
    cout << "Queue rong." << endl;
    return 0;// tuong duong queue rong
}

/* hàm nhập các phần tử vào hàng đợi */
void nhap(Queue& q) {
    int n, x;
    cout << "Nhap so phan tu ban muon them vao trong Queue: ";
    cin >> n;
    while (n--) {
        cout << "\nNhap phan tu trong hang doi: "; cin >> x;
        Node* p = createNode(x);
        Push(q, p);
    }
}
/* hàm xuất các phần tử trong hàng đợi */
void xuat(Queue q) {
    Node* p = q.head;
    while (p) {
        cout << setw(4) << p->data;
        p = p->next;
    }
    cout << endl;
}

/* hàm menu để hiển thị menu và gọi các hàm đã tạo */
void menu(Queue q) {
    int lc;
    do {
        cout << "\n\n\t\t ============== Menu ==============";
        cout << "\n\t1. Nhap phan tu cho hang doi";
        cout << "\n\t2. Xuat phan tu trong hang doi";
        cout << "\n\t3. Hien thi phan tu dau tien cua hang doi";
        cout << "\n\t4. Xoa phan tu dau tien cua hang doi";
        cout << "\n\t0. Thoat";
        cout << "\n\n\t\t ============== End ==============";
        cout << "\nNhap lua chon ban muon chon: ";
        cin >> lc;
        switch (lc) {
        case 0: break;
        case 1:
            nhap(q);
            break;
        case 2:
            cout << "Cac phan tu trong hang doi Queue la: ";
            xuat(q);
            break;
        case 3:
            cout << "Phan tu dau tien cua hang doi la: " << Top(q);
            break;
        case 4:
            Pop(q);

            break;
        default: cout << "\nNhap sai, vui long nhap lai!";
        }
    } while (lc);
}

/* hàm main để hiển thị menu*/
int main() {
    Queue q;
    Init(q);
    menu(q);
    cout << "\n---------------------------------\n";
}