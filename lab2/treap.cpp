#include "treap.h"

TreapNode* rightSpin(TreapNode* y)
{
	TreapNode* x = y->l, * T2 = x->r;
	x->r = y;
	y->l = T2;
	return x;
}

TreapNode* leftSpin(TreapNode* x)
{
	TreapNode* y = x->r, * T2 = y->l;
	y->l = x;
	x->r = T2;
	return y;
}

TreapNode* newNode(int key)
{
	TreapNode* curr = new TreapNode;
	curr->key = key;
	curr->degree = rand() % 100;
	curr->l = curr->r = nullptr;
	return curr;
}

TreapNode* search(TreapNode* root, int key)
{

	if (root == nullptr || root->key == key)
	{
		return root;
	}

	if (root->key < key) 
	{
		return search(root->r, key);
	}
	return search(root->l, key);
}


TreapNode* insert(TreapNode* root, int key)
{
	if (!root)
	{
		return newNode(key);
	}

	if (key <= root->key)
	{
		root->l = insert(root->l, key);
		if (root->l->degree > root->degree)
		{
			root = rightSpin(root);
		}
	}
	else
	{
		root->r = insert(root->r, key);
		if (root->r->degree > root->degree)
		{
			root = leftSpin(root);
		}
	}
	return root;
}

TreapNode* deleteNode(TreapNode* root, int key)
{
	if (search(root, key) == nullptr)
	{
		printf("\nKey %d not found\n", key);
		return nullptr;
	}

	if (root == nullptr)
	{
		return root;
	}

	if (key < root->key)
	{
		root->l = deleteNode(root->l, key);
	}

	else if (key > root->key)
	{
		root->r = deleteNode(root->r, key);
	}

	else if (root->l == nullptr)
	{
		TreapNode* temp = root->r;
		delete(root);
		root = temp;
	}

	else if (root->r == nullptr)
	{
		TreapNode* temp = root->l;
		delete(root);
		root = temp;
	}

	else if (root->l->degree < root->r->degree)
	{
		root = leftSpin(root);
		root->l = deleteNode(root->l, key);
	}
	else
	{
		root = rightSpin(root);
		root->r = deleteNode(root->r, key);
	}
	return root;
}

#include <cstdio>

void Order(TreapNode* root) {
	if (root) {
		Order(root->l);
		printf("key: %d | priority: %d", root->key, root->degree);
		if (root->l)
			printf(" | left child: %d", root->l->key);
		if (root->r)
			printf(" | right child: %d", root->r->key);
		printf("\n");
		Order(root->r);
	}
}

void printTreap(TreapNode* root, int space = 0, int count = 12) {
	if (root == nullptr)
	{
		return;
	}
	space += count;
	printTreap(root->r, space);
	printf("\n");
	for (int i = count; i < space; ++i)
		printf(" ");

	printf("(%d, %d)\n", root->key, root->degree);
	printTreap(root->l, space);
}