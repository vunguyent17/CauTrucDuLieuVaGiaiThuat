#include <iostream>
using namespace std;

//khai báo cấu trúc Node
struct Node {
    int data;
    Node* next;
};


//khai báo cấu trúc stack
struct Stack {
    Node* head;
    Node* tail;
};

void Init(Stack& s)
{
    s.head = NULL;
    s.tail = NULL;
}

//kiểm tra stack rỗng
bool isEmpty(Stack s) {
    return (s.head == NULL);
}

//tạo Node
Node* createNode(int data) {
    Node* p = new Node();
    if (p == NULL) {
        return NULL;
    }
    p->data = data;
    p->next = NULL;

    return p;
}

void push(Stack& s, int data) {
    // tạo một Node mới
    Node* ptr = createNode(data);
    // kiểm tra stack rỗng
    if (isEmpty(s)) {
        s.head = ptr;
        s.tail = ptr;
    }
    //nếu tồn tại phần tử ta trỏ đến phần tử đầu danh sách
    else {
        ptr->next = s.head;
        s.head = ptr;
    }
}


void Xuat(Stack s)
{
    Node* p = s.head;
    while (p!= NULL)
    {
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
}

int top(Stack s) {
    if (!isEmpty(s)) {
        return s.head->data;
    }
    else {
        cout << "Stack is empty!" << endl;
        return 0;
    }
}

int pop(Stack& s) {
    if (!isEmpty(s)) {
        //tạo Node x và gán cho bằng s.head
        Node* x = s.head;
        int k = x->data;
        // cho s = s trỏ đến next
        s.head = x->next;

        if (s.head == NULL)
        {
            s.tail = NULL;
        }
        // thực hiện xóa node x
        delete(x);
        cout << "Xoa thanh cong !!" << endl;
        return k;
    }
    else {
        cout << "Stack rong!" << endl;
        return 0;
    }
}

int main() {
    int lc;
    Stack s;
    Init(s);
    push(s, 10);
    push(s, 11);
    push(s, 12);
    push(s, 13);
    push(s, 14);
    push(s, 15);
    push(s, 16);
    cout << "Danh sach cac so bao gom: " << endl;
    Xuat(s);
    do {
        cout << "\n\n\t\t ==================== Menu ====================";
        cout << "\n\t1. Hien thi phan tu dau Stack";
        cout << "\n\t2. Xoa phan tu dau Stack";
        cout << "\n\t3. Xuat cac phan tu cua Stack";
        cout << "\n\t0. Ket thuc";
        cout << "\n\n\t\t ==================== End ====================";
        cout << "\nNhap lua chon ban muon chon: ";
        cin >> lc;
        switch (lc) {
        case 0: break;
        case 1:
            cout << "Phan tu dau tien trong Stack: " << top(s);
            break;
        case 2:
            pop(s);
            Xuat(s);
            break;
        case 3:
            Xuat(s);
            break;
        default: cout << "\nNhap sai, vui long nhap lai!";
        }
    } while (lc);
}