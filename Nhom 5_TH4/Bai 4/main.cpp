#include"BinarySeachTree.h";

int main()
{
	cout << "************Bai04-ThucHanh4************";
	cout << "\n\n-----------------------------------------------------------------------";
	cout << "\nChon'1'--> (Nhap Cay);"
		"\nChon'2'--> (In Tang Dan, Giam Dan);"
		"\nChon'3'--> (Tim Nut);"
		"\nChon'4'--> (Dem SoLuong Nut);"
		"\nChon'5'--> (Tinh Height);"
		"\nChon'6'--> (Xuat Theo Level);"
		"\nChon'7'--> (Xoa Nut);"
		//"\nChon'8'--> (Xuat theo so do);"
		"\nChon'0'--> (Ket Thuc)";
	cout << "\n||||Your Choice: ";
	Tree T;
	T = NULL;
	int k = -1;
	do
	{
		if (k != -1)
			cout << "\n\n||||Your Choice Again: ";
		cin >> k;

		if (k == 1)
		{
			while (T)
			{
				DeleteNode(T, T->key);
			}
			T = NULL;
			cout << "Enter a positive integer (enter a negative integer to stop): " << endl;
			InsertData(T);
			if (T)
			{
				T = FixBalance(T);
			}
			cout << "--------->OK!" << endl;
		}
		else if (k == 2)
		{
			if (!T)
				cout << "\n--------->Tree Is Null. Enter Tree, please!" << endl;
			else
			{
				cout << "\n--------->Ascending of the values : ";
				Ascending(T);
				cout << "\n--------->Descending of the values : ";
				Descending(T);
			}
		}
		else if (k == 3)
		{
			if (!T)
				cout << "\n--------->Tree Is Null. Enter Tree, please!" << endl;
			else
			{
				int x;
				cout << "Enter the key: ";
				cin >> x;
				Node* key;
				key = SeachNode(T, x);
				if (!key)
					cout << "\n--------->Dont have the key in data!" << endl;
				else
				{
					cout << "\n--------->The Key's Address Is: " << key;
					cout << " / With Value: " << key->key << endl;
				}
			}
		}
		else if (k == 4)
		{
			int x;
			x = CountNode(T);
			cout << "\n--------->Node's quantity of tree : " << x << endl;
		}
		else if (k == 5)
		{
			int x;
			x = Height(T);
			if (x<0)
				cout << "\n--------->Tree Is Null. Enter Tree, please!" << endl;
			else 
				cout << "\n--------->Height of tree : " << x << endl;
		}
		else if (k == 6)
		{
			LevelPrint(T);
		}
		else if (k == 7)
		{
			if (!T)
				cout << "\n--------->Tree Is Null. Enter Tree, please!" << endl;
			else
			{
				int x;
				cout << "\n Enter the key : ";
				cin >> x;
				DeleteNode(T, x);
				T = FixBalance(T);
			}
		}
		/*else if (k == 8)
		{
			if (T)
			{
				cout << "\n--------->Print tree: " << endl;
				MapPrint(T);
			}
			else
			{
				cout << "\n--------->Tree Is Null." << endl;
			}
		}*/
	} while (k != 0);
	return 0;
}