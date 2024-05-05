#include "treap.h"
#include "unit_tests.h"

void Test_insert() 
{
    int key_root = 15, key_r = 10, key_l = 5;
    struct TreapNode* root = nullptr;
    root = insert(root, key_root);
    assert(search(root, key_root) != nullptr && search(root, key_root)->key == key_root);

    root = insert(root, key_r);
    assert(search(root, key_r) != nullptr && search(root, key_r)->key == key_r);
    assert(search(root, key_r)->degree <= root->degree); 

    root = insert(root, key_l);
    assert(search(root, key_l) != nullptr && search(root, key_l)->key == key_l);
    assert(search(root, key_l)->degree <= root->degree); 
    printf("Tests completed!\n");
}

void Test_delete() 
{
    int key_root = 5, key_r = 10, key_l = 15,;
    struct TreapNode* root = nullptr;
    root = insert(root, key_root);
    root = insert(root, key_r);
    root = insert(root, key_l);
    
    root = deleteNode(root, key_r);
    assert(search(root, key_r) == nullptr); 
    assert(search(root, key_root) != nullptr); 

    root = deleteNode(root, key_l);
    assert(search(root, key_l) == nullptr); 
    assert(search(root, key_r) != nullptr); 
    assert(search(root, key_r) != nullptr);

    root = deleteNode(root, key_root);
    assert(search(root, key_root) == nullptr); 
   
    if (root != nullptr) 
    {
        if (root->l != nullptr) 
        {
            assert(root->degree >= root->l->degree);
        }
        if (root->r != nullptr) 
        {
            assert(root->degree >= root->r->degree);
        }
    }
    printf("Tests completed\n");
}