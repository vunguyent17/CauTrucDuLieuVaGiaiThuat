#include "QueueString.h"

int main()
{
	QueueString Q;
	Q.Nhap();
	int so_lan = 0;
	cout << "Ban muon chay dong chu nay bao nhieu lan: ";
	cin >> so_lan;
	Q.ChayChu(so_lan);
	return 1;
}