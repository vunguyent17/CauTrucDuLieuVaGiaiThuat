#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* pNext;	//Chua dia chi node ke tiep ma no tro toi
};

struct List {
	Node* pHead;
	Node* pTail;
};

void Init(List& l) {	//Khong tao List rong
	l.pHead = l.pTail = NULL;
}

Node* createNode(int x) {	//Tao thong tin cho node
	Node* p = new Node;
	if (p == NULL) exit(1);
	p->pNext = NULL;
	p->info = x;
	return p;
}

bool isEmpty(List l) { // k tra xem lieu List co rong hay k.
	if (l.pHead == NULL) return true;
	return false;
}

//Cau 1a.1: Them nut vao dau danh sach:
void addHead(List& L, Node* p)
{
	if (L.pHead == NULL)
	{
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else
	{
		p->pNext = L.pHead;		// con tro pNext cua p tro toi dia chi cua node pHead(ban dau)
		L.pHead = p;			// cap nhat node pHead(luc sau)
	}
}

void addHead(List& l, int x) {
	Node* p = createNode(x);
	addHead(l, p);
}

//Cau 1a.2: Them nut vao cuoi danh sach:
void addTail(List& L, Node* p)
{
	if (L.pHead == NULL)
	{
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else
	{
		L.pTail->pNext = p;
		L.pTail = p;
	}
}

void addTail(List& l, int x) {
	Node* p = createNode(x);
	addTail(l, p);
}

//Cau 1a.3: Nhap xuat danh sach da nhap:
void inputList(List& L)
{
	cout << "Bat dau nhap cac so nguyen duong (viec nhap ket thuc khi ta nhap 1 so am)." << endl;
	int x = 0;
	do
	{
		cout << "Nhap mot so: ";
		cin >> x;
		if (x>=0)
		{
			addTail(L, x);
		}
	} while (x>=0);
	cout << "Qua trinh nhap ket thuc." << endl;
}

void printList(List L)
{
	Node* p;
	p = L.pHead;
	while (p != NULL)
	{
		printf("%d\t", p->info);
		p = p->pNext;
	}
}

// Cau 1b: Dem so nut trong dsach:
int countMember(List& L)
{
	Node* p = L.pHead;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->pNext;
	}
	return count;
}

//Cau 1c: Tim mot nut co thanh phan du lieu bang X.
Node* search(List l, int x) {
	Node* p = l.pHead;
	while (p != NULL) {
		if (p->info == x) return p;
		else p = p->pNext;
	}
	return NULL;
}

void addMid(List& l, Node* p, Node* q) { // chen node p vao sau node q;
	if (q != NULL) {
		p->pNext = q->pNext;
		q->pNext = p;
		if (l.pTail == q)
		{
			l.pTail = p;
		}
	}
	else addHead(l, p);
}

void addMid(List& l, int x, int k) { // chen node co info = x vao sau node co info  = k;
	Node* p = search(l, k);
	if (p != NULL) {
		Node* q = createNode(x);
		addMid(l, q, p);
	}
	else cout << "\nKhong tim thay node co info = k.";
}

void addAtK(List& l, int x, int k) { // chen vi tri bat ki;
	if (isEmpty(l) || k <= 1)
		addHead(l, x);
	else if (k >= countMember(l))
		addTail(l, x);
	else 
	{
		Node* p = createNode(x);
		Node* q = new Node, * w = new Node;
		Node* r = l.pHead;
		int dem = 0;
		while (r != NULL)
		{
			dem++;
			q = r;
			if (dem == k) break;
			else r = r->pNext;
		}
		w = l.pHead;
		while (w != NULL && w->pNext != q) w = w->pNext;
		w->pNext = p;
		p->pNext = r;
	}
}

//1d.1. Xoa 1 nut dau danh sach lien ket don.
void delHead(List& l) { 
	if (!isEmpty(l)) {
		Node* p = l.pHead;
		l.pHead = l.pHead->pNext;		// cap nhat l.pHead
		if (l.pHead == NULL)			// truong hop sau khi xoa danh sach rong
			l.pTail = NULL;
		delete p;		// xoa bo node pHead ban dau
	}
}

//1d.2. Xoa 1 nut cuoi danh sach lien ket don.
void delTail(List& l) {
	if (!isEmpty(l)) {
		if (l.pHead->pNext == NULL)		//truong hop chi co 1 node trong list
		{
			l.pHead = NULL;
			l.pTail = NULL;
		}
		else
		{
			Node* p = l.pHead;
			Node* q = new Node;
			while (p->pNext != l.pTail) p = p->pNext;		// tim node ngay truoc pTail
			q = p;		// gan node nay cho node q
			p = p->pNext;		// p chinh la node pTail can xoa
			l.pTail = q;		 // cap nhat l.pTail
			l.pTail->pNext = NULL;		 // cap nhat node pNext cho l.pTail
			delete p;
		}
	}
}

void delAtK(List& l, int k) {	 //xoa mot node co gia tri bang k
	if (k <= 1) delHead(l);
	else if (k >= countMember(l)) delTail(l);
	else {
		int dem = 0;
		if (l.pHead != NULL) {
			Node* p = l.pHead;
			Node* q = new Node;
			while (p != NULL) { // tim node thu k.
				dem++;
				q = p;
				if (dem == k) break; // tim thay thi break
				else p = p->pNext; // k thi tim tiep
			}
			Node* r = l.pHead;
			while (r->pNext != q) r = r->pNext; // tim node k-1
			r->pNext = q->pNext; // cho node pNext cua node k-1 tro toi node k+1;
			delete q;
		}
	}
}

//1e. Hay sap xep danh sach lien ket don giam dan theo thanh thanh phan du lieu.
void QuickSort(List& l, int x) {	//Sap xep kieu QuickSort cho list l, x = 1 sap xep tang dan, x = 0 sap xep giam dan
	List l1, l2;
	Node* tag, * p;

	if (l.pHead == l.pTail) return;
	Init(l1);
	Init(l2);
	
	tag = l.pHead;
	l.pHead = l.pHead->pNext;		// cap nhat lai l.pHead
	tag->pNext = NULL;		// co lap tag

	while (l.pHead != NULL) {
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		p->pNext = NULL;

		if (x == 0 && p->info >= tag->info || x == 1 && p->info <= tag->info) 
			addHead(l1, p->info);		// <= sap xep tang dan , >= sap xep giam dan
		else 
			addHead(l2, p->info);

	}
	QuickSort(l1,x);		// goi de qui sap xep l1, l2
	QuickSort(l2,x);
	
	if (l1.pHead != NULL) {		// truong hop l1 khong rong
		l.pHead = l1.pHead;		// lay pHead cua l1 gan cho pHead cua l;
		l1.pTail->pNext = tag;
	} 
	else l.pHead = tag;		// truong hop l1 rong

	tag->pNext = l2.pHead;
	if (l2.pHead != NULL) l.pTail = l2.pTail;
	else l.pTail = tag;
}

/*1f. Hay chen 1 nut co truong du lieu bang X(X nhap tu ban phim), 
sao cho sau khi chen danh sach van tang dan theo truong du lieu.*/
void chenGiuNguyenThuTuTangDan(List& L, Node* p)
{
	QuickSort(L,1);		//sap xep du lieu theo chieu tang dan
	Node* temp = L.pHead;
	if (temp == NULL || p->info <= temp->info)
	{
		addHead(L, p);
		return;
	}
	while (temp != NULL) {

		if ((temp->pNext == NULL && p->info >= temp->info)
			|| (temp->info <= p->info && p->info <= temp->pNext->info))
		{
			addMid(L, p, temp);
			return;
		}
		temp = temp->pNext;
	}
	return;
}

void menu() {
	List l;
	Init(l);
	inputList(l);
	printList(l);
	int k, x, lc;
	Node* p;
	do {
		cout << "\n__________________MENU__________________\n1_Chen dau.\n2_Chen cuoi."
			<< "\n3_Chen sau vi tri node info = k.\n4_Chen vao vi tri bat ki."
			<< "\n5_Xoa phan tu dau List."
			<< "\n6_Xoa phan tu o cuoi List.\n7_Xoa node o vi tri k."
			<< "\n8_Dem so nut trong danh sach lien ket don"
			<< "\n9_Xuat thong tin List."
			<<"\n10_Tim mot nut co thanh phan du lieu bang X."
			<< "\n11_Sap xep giam dan." 
			<< "\n12_Sap xep tang dan va chen nut sao cho sau khi chen danh sach van tang dan theo truong du lieu."
			<< "\n0_Thoat.\n_Ban chon ? ";
		cin >> lc;
		switch (lc) {
		case 0: break;
		case 1: cout << "Nhap x: "; cin >> x; addHead(l, x); printList(l); break;
		case 2: cout << "Nhap x: "; cin >> x; addTail(l, x); printList(l); break;
		case 3: cout << "Nhap x, k: "; cin >> x >> k; addMid(l, x, k); printList(l); break;
		case 4: cout << "Nhap x, vi tri k: "; cin >> x >> k; addAtK(l, x, k); printList(l); break;
		case 5: delHead(l); printList(l); break;
		case 6: delTail(l); printList(l); break;
		case 7: cout << "Nhap vi tri k: "; cin >> k; delAtK(l, k); printList(l); break;
		case 8: cout << "So nut trong danh sach don: " << countMember(l); break;
		case 9: printList(l); break;
		case 10:
			cout << "Nhap x: ";
			cin >> x;
			p = search(l, x);
			if (p != NULL)
				cout << "Node co gia tri: " << p->info << ", pNext = " << p->pNext << endl;
			else
				cout << "Khong co node mang gia tri nay trong danh sach." << endl;
			break;
		case 11: QuickSort(l, 0); cout << "\nDanh sach sau khi sap xep giam dan: " << endl; printList(l); break;
		case 12: cout << "\nNhap x: "; cin >> x; chenGiuNguyenThuTuTangDan(l, createNode(x));
			cout << "\nDanh sach sau khi sap xep tang dan va them x: " << endl; printList(l); break;
		}
	} while (lc != 0);
}

int main() {
	menu();
	return 0;
}