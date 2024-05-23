#include "treap.h"

TreapNode* rightRotate(TreapNode* y) 
{
    TreapNode* x = y->l;
    TreapNode* T2 = x->r;
    x->r = y;
    y->l = T2;

    return x;
}

TreapNode* leftRotate(TreapNode* x) 
{
    TreapNode* y = x->r;
    TreapNode* T2 = y->l;
    y->l = x;
    x->r = T2;

    return y;
}

TreapNode* newNode(int key, int degree) 
{
    TreapNode *node;
    node = (TreapNode *) malloc(sizeof(TreapNode));
    if (node != nullptr) 
    {
        node->key = key;
        node->degree = degree;
        node->l = nullptr;
        node->r = nullptr;
    }
    return node;
}

TreapNode* search(TreapNode* root, int key) 
{
    if (root == nullptr || root->key == key)
        return root;

    if (root->key < key)
        return search(root->r, key);

    return search(root->l, key);
}

TreapNode* insert(TreapNode* root, int key) 
{
    if (!root) 
    {
        int random_priority = rand();
        return newNode(key, random_priority);
    }

    if (key <= root->key) 
    {
        root->l = insert(root->l, key);

        if (root->l->degree > root->degree)
            return rightRotate(root);
    } 
    else 
    {
        root->r = insert(root->r, key);

        if (root->r->degree > root->degree)
            return leftRotate(root);
    }
    return root;
}




TreapNode* deleteNode(TreapNode* root, int key) 
{
    if (root == nullptr)
        return root;
    if (key < root->key) 
    {
        root->l = deleteNode(root->l, key);
    } 
    else if (key > root->key) 
    {
        root->r = deleteNode(root->r, key);
    } 
    else 
    {
        if (root->l == nullptr) 
        {
            TreapNode* temp = root->r;
            free(root);
            return temp;
        } 
        else if (root->r == nullptr) 
        {
            TreapNode* temp = root->l;
            free(root);
            return temp;
        } 
        else if (root->l->degree < root->r->degree) 
        {
            root = leftRotate(root);
            root->l = deleteNode(root->l, key);
        } 
        else 
        {
            root = rightRotate(root);
            root->r = deleteNode(root->r, key);
        }
    }
    return root;
}

void inorder(TreapNode* root) 
{
    if (root) 
    {
        inorder(root->l);
        printf("key: %d | degree: %d", root->key, root->degree);
        if (root->l)
            printf(" | l child: %d", root->l->key);
        if (root->r)
            printf(" | r child: %d", root->r->key);
        printf("\n");
        inorder(root->r);
    }
}

void printTreap(TreapNode* root, int space, int count) 
{
    if (root == nullptr)
        return;
    space += count;

    printTreap(root->r, space, count);

    printf("\n");
    for (int i = count; i < space; ++i)
        printf(" ");

    printf("(%d, %d)\n", root->key, root->degree);
    printTreap(root->l, space, count);
}

void freeTreap(TreapNode* root) 
{
    if (root == nullptr)
        return;
    freeTreap(root->l);
    freeTreap(root->r);
    free(root);
}
