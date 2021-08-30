#pragma once
#include <iostream>

using namespace std;

struct KiTu {
    char info;
    int count;
};

// Khai bao cau truc node
struct TNode {
    KiTu key;
    TNode *pLeft;
    TNode *pRight;
};

// Khai bao cau truc cay
typedef TNode *Tree;

// Create Tree
void CreateTree(Tree &T)
{
    T = NULL;
}

// Create Node
TNode* CreateNode(KiTu x)
{
    TNode *p;
    p = new TNode;
    if (p == NULL)
    {
        exit(1);
    }
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

// Insert a node to tree (recursion)
int InsertRecursion(Tree &T, KiTu x)
{
    if (T)
    {
        if (T->key.info == x.info)
        {
            T->key.count++;
            return 0;
        }
        else if (x.info > T->key.info)
        {
            return InsertRecursion(T->pRight, x);
        }
        else
        {
            return InsertRecursion(T->pLeft, x);
        }
    }
    T = CreateNode(x);
    return 1;
}

// List: preOrder
void preOrder(Tree Root)
{
    if (Root)
    {
        cout << "(" << Root->key.info << "," << "count=" << Root->key.count << ")\n";
        preOrder(Root->pLeft);
        preOrder(Root->pRight);
    }
}

// List: inOrder
void inOrder(Tree Root)
{
    if (Root)
    {
        inOrder(Root->pLeft);
        cout << "(" << Root->key.info << "," << "count=" << Root->key.count << ")\n";
        inOrder(Root->pRight);
    }
}

// List: postOrder
void postOrder(Tree Root)
{
    if (Root)
    {
        postOrder(Root->pLeft);
        postOrder(Root->pRight);
        cout << "(" << Root->key.info << "," << "count=" << Root->key.count << ")\n";
    }
}
