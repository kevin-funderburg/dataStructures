#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}



// write definition for bst_insert here
void bst_insert(btNode *bst_root, int insInt)
{
    if (bst_root == 0) return;

    if (bst_root->left == 0 && bst_root->right == 0)
    {
        btNode *newRoot = new btNode;
        newRoot->data = insInt;
        bst_root = newRoot;
        return;
    }

    bool done = false;
    btNode *cursor = bst_root;
    while (!done)
    {
        if (cursor->data < insInt)
        {
            if (cursor->left == 0)
            {
                btNode *newNode = new btNode;
                newNode->data = insInt;
                cursor->left = newNode;
                done = true;
            } else {
                cursor = cursor->left;
            }
        }
        else if (cursor->data > insInt)
        {
            if (cursor->right == 0)
            {
                btNode *newNode = new btNode;
                newNode->data = insInt;
                cursor->right = newNode;
                done = true;
            } else {
                cursor = cursor->right;
            }
        }
        else
        {
            cursor->data = insInt;
        }
    }
    return;
}

// write definition for bst_remove here
bool bst_remove(btNode *bst_root, int remInt)
{
    if (bst_root == 0) return true;

    if (remInt < bst_root->data)
    {
        bst_remove(bst_root->left, remInt);
    }
    else if (remInt > bst_root->data)
    {
        bst_remove(bst_root->right, remInt);
    }
    else if (remInt == bst_root->data)
    {
        if (bst_root->left == 0)
        {
            btNode* oldroot_ptr = bst_root;
            bst_root = bst_root->right;
            delete oldroot_ptr;
        }
        else
            bst_remove_max(bst_root->left, bst_root->data);
    }


    return false;
}

// write definition for bst_remove_max here
void bst_remove_max(btNode *bst_root, int target)
{
    if (bst_root->right == 0)
    {
        int removed = bst_root->data;
        btNode* oldroot_ptr = bst_root;
        bst_root = bst_root->left;
        delete oldroot_ptr;
    }
    else
        bst_remove_max(bst_root->right, target);

}




