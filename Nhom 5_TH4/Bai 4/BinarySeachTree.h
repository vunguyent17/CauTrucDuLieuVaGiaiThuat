#pragma once
#include <iostream>
#include<math.h>
using namespace std;


struct Node
{
	unsigned int key;
	Node* left;
	Node* right;
};
typedef Node* Tree;

bool AddNode(Tree& root, unsigned int key)
{
	if (root)
	{
		if (root->key == key)
			return 0;
		if (root->key > key)
			return AddNode(root->left, key);
		return AddNode(root->right, key);
	}
	Node* p = new Node;
	p->key = key;
	p->left = NULL;
	p->right = NULL;
	root = p;
	p = NULL;
	delete p;
	return 1;
}

void InsertData(Tree& T)
{
	int x;
	cin >> x;
	if (x >= 0)
	{
		bool flag;
		flag = AddNode(T, x);
		if (flag)
			cout << "Successfully entered: " << x << endl;
		else
			cout << "Have already had: " << x << endl;
		InsertData(T);
	}

}

void Ascending(Tree& L)
{
	if (L != NULL)
	{
		Ascending(L->left);
		cout << L->key << "\t";
		Ascending(L->right);
	}
}

void Descending(Tree& L)
{
	if (L != NULL)
	{
		Descending(L->right);
		cout << L->key << "\t";
		Descending(L->left);
	}
}

Node* SeachNode(Tree& T, int x)
{
	if (T != NULL)
	{
		if (T->key == x)
			return T;
		if (T->key > x)
			return SeachNode(T->left, x);
		return SeachNode(T->right, x);
	}
	return NULL;
}

int Height(Tree& t)
{
	if (!t)
	{
		return -1;
	}
	int a = Height(t->left);
	int b = Height(t->right);
	return 1 + (a > b ? a : b);

}

void SwapLeft(Tree& t, Tree& l)
{
	if (l->right != NULL)
		SwapLeft(t, l->right);
	else
	{
		t->key = l->key;
		l = l->left;
	}
}

void SwapRight(Tree& t, Tree& r)
{
	if (r->left != NULL)
		SwapRight(t, r->left);
	else
	{
		t->key = r->key;
		r = r->right;
	}
}

void DeleteNode(Tree& T, int x)
{
	bool flag = 0;
	if (T != NULL)
	{
		if (T->key < x)
			DeleteNode(T->right, x);
		else if (T->key > x)
			DeleteNode(T->left, x);
		else
		{
			if (T->left == NULL)
				T = T->right;
			else if (T->right == NULL)
				T = T->left;
			else
			{
				if (Height(T->left) > Height(T->right))
				{
					SwapRight(T, T->right);
				}
				else
				{
					SwapLeft(T, T->left);
				}
			}
			flag = 1;
			cout << "--------->OK! Deleted.." << endl;
		}
	}
	else if (!flag)
		cout << "--------->Dont have the key!" << endl;
}

Tree turnRight(Tree& t)
{
	Node* b = t->left;
	Node* d = b->right;
	t->left = d;
	b->right = t;
	return b;
}

Tree turnLeft(Tree& t)
{
	Node* b = t->right;
	Node* c = b->left;
	t->right = c;
	b->left = t;
	return b;
}

Tree FixBalance(Tree& T)
{
	while (abs(Height(T->left) - Height(T->right))>1)
	{
		if (Height(T->left)>Height(T->right))
		{
			Tree p = T->left;
			if (Height(p->left) >= Height(p->right))
				T = turnRight(T);
			else
			{
				T->left = turnLeft(T->left);
				T = turnRight(T);
			}
		}
		else
		{
			Tree p = T->right;
			if (Height(p->right) >= Height(p->left))
				T = turnLeft(T);
			else
			{
				T->right = turnRight(T->right);
				T = turnLeft(T);
			}
		}
	}
	if (T->left != NULL)
		T->left = FixBalance(T->left);
	if (T->right != NULL)
		T->right = FixBalance(T->right);
	return T;
}

void PrintAtLevel(Tree & L, int i)
{
	if (L == NULL)
		return;
	if (i == 0)
		cout << L->key << "\t";
	else
	{
		PrintAtLevel(L->left, i-1);
		PrintAtLevel(L->right, i-1);
	}
}

void LevelPrint(Tree& L)
{
	int h = Height(L);
	if (h < 0)
		cout << "\n--------->Tree Is Null. Enter Tree, please!" << endl;
	else
	{
		for (int i = 0; i <= h; i++)
		{
			cout << "\nLevel " << i << " : ";
			PrintAtLevel(L, i);
			cout << "\n";
		}
	}
}

int CountNode(Tree& t)
{
	if (t == NULL)
		return 0;
	int	a = CountNode(t->left);
	int b = CountNode(t->right);
	return 1 + a + b;
}
