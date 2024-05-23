#pragma once

#include <iostream>
#include <cstdlib>
#include <malloc.h>
#include <cstdio>

using namespace std;

struct TreapNode 
{
    int key;
    int degree;
    TreapNode *l;
    TreapNode *r;

};


TreapNode *rightRotate(TreapNode *y);

TreapNode *leftRotate(TreapNode *x);

TreapNode *newNode(int , int degree);

TreapNode *search(TreapNode *root, int key);

TreapNode *insert(TreapNode *root, int key);

TreapNode *deleteNode(TreapNode *root, int key);

void inorder(TreapNode *root);

void printTreap(TreapNode *root, int space, int count);

void freeTreap(TreapNode* root);