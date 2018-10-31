#include <iostream>
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
void bst_insert(btNode*& bst_root, int insInt)
{
    if (bst_root == 0)
    {
        bst_root = new btNode;
        bst_root->data = insInt;
        bst_root->left = bst_root->right = 0;
    }
    else
    {
        bool done = false;
        btNode *cursor = bst_root;
        while (!done)
        {
            if (cursor->data == insInt) {
                cursor->data = insInt;
                done = true;
            }
            else if (insInt < cursor->data)
            {
                if (cursor->left == 0)
                {
                    cursor->left = new btNode;
                    cursor->left->data = insInt;
                    cursor->left->left = cursor->left->right = 0;
                    done = true;
                } else {
                    cursor = cursor->left;
                }
            }
            else if (insInt > cursor->data)
            {
                if (cursor->right == 0)
                {
                    cursor->right = new btNode;
                    cursor->right->data = insInt;
                    cursor->right->right = cursor->right->left = 0;
                    done = true;
                } else {
                    cursor = cursor->right;
                }
            }
        }
    }
}

// write definition for bst_remove here
bool bst_remove(btNode*& bst_root, const int remInt)
{
    if (bst_root == 0) return false;

    if (remInt < bst_root->data)
        return bst_remove(bst_root->left, remInt);

    else if (remInt > bst_root->data)
        return bst_remove(bst_root->right, remInt);

    else if (remInt == bst_root->data)
    {
        if (bst_root->left == 0 || bst_root->right == 0)
        {
            btNode* old_bst_root = bst_root;

            if (bst_root->left == 0)
                bst_root = bst_root->right;

            else if (bst_root->right == 0)
                bst_root = bst_root->left;

            else
                bst_root = 0;

            delete old_bst_root;
        } else {
            bst_remove_max(bst_root->left, bst_root->data);
        }
        return true;
    }
}

// write definition for bst_remove_max here
void bst_remove_max(btNode*& bst_lst_root, int& removed)
{
    if (bst_lst_root == 0) return;

    if (bst_lst_root->right == 0)
    {
        if (bst_lst_root->left != 0)
        {
            btNode *oldroot = bst_lst_root;
            removed = bst_lst_root->data;
            bst_lst_root = bst_lst_root->left;
            delete oldroot;
        }
        else
        {
            removed = bst_lst_root->data;
            delete bst_lst_root;
            bst_lst_root = 0;
        }
        return;
    }
    else
        bst_remove_max(bst_lst_root->right, removed);
}