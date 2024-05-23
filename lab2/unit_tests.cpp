
#include "treap.h"
#include "unit_tests.h"

void Test_insert() 
{
    int key_root = 15, key_r = 10, key_l = 5;
    struct TreapNode *root = nullptr;

    root = insert(root, key_root);
    assert(root->key == key_root && root != nullptr);

    root = insert(root, key_left);
    assert(root->l->key == key_left && root->l->degree <= root->degree && root->l != nullptr);

    root = insert(root, key_right);
    assert(root->r->key == key_right && root->r->degree <= root->degree && root->r != nullptr);

    printf("All insert tests passed!\n");

    freeTreap(root);
}


void Test_search() 
{
    struct TreapNode *root = newNode(10, 50);
    root->r = newNode(15, 40);
    root->l = newNode(5, 30);

    assert(search(root, 10)->key == root->key && search(root, 10)->degree == 50);
    assert(search(root, 15)->key == root->r->key && search(root, 15)->degree == 40);
    assert(search(root, 5)->key == root->l->key && search(root, 5)->degree == 30);

    printf("All search tests passed!\n");

    freeTreap(root);
}

void Test_delete() 
{
    struct TreapNode *root = newNode(10, 50);
    root->r = newNode(15, 40);
    root->l = newNode(5, 30);

    root = deleteNode(root, 15);
    assert(root->r == nullptr);

    root = deleteNode(root, 5);
    assert(root->l == nullptr);

    root = deleteNode(root, 10);
    assert(root == nullptr);

    root = newNode(10, 50);
    struct TreapNode *rNode = newNode(15, 40);
    struct TreapNode *lNode = newNode(5, 30);
    root->r = rNode;
    root->l = lNode;

    root = deleteNode(root, 10);
    assert(root->key == 15 && root->degree == 40 && root->r == nullptr && root->l == lNode);

    printf("All delete tests passed!\n");

    freeTreap(root);
}