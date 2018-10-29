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


//TODO: decide if this is working correctly, getting address values in result
// write definition for bst_insert here
void bst_insert(btNode*& bst_root, int insInt)
{
    if (bst_root == 0)
    {
       bst_root = new btNode;
       bst_root->data = insInt;
       bst_root->left = bst_root->right = 0;
//        return true;
return;
    }
    bool done = false;
    btNode *cursor = bst_root;
    while (!done)
    {
        if (cursor->data == insInt)
        {
            cursor->data = insInt;
//            return false;
            return;
        }
        if (insInt < cursor->data)
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
//    return true;
    return;
}

// write definition for bst_remove here
bool bst_remove(btNode*& bst_root, int remInt)
{
    if (bst_root == 0) return true;

    if (remInt < bst_root->data)
        bst_remove(bst_root->left, remInt);

    else if (remInt > bst_root->data)
        bst_remove(bst_root->right, remInt);

    else if (remInt == bst_root->data)
    {
       if (bst_root->left == 0 && bst_root->right == 0) // root has no children
       {
           btNode* oldroot_ptr = bst_root;
           bst_root = 0;
           delete oldroot_ptr;
       }
       else if (bst_root->left != 0 && bst_root->right == 0)    // root has 1 (left) child
       {
            btNode* oldroot_ptr = bst_root;
            bst_root = bst_root->left;
            delete oldroot_ptr;
       }
       else if (bst_root->left == 0 && bst_root->right != 0)    // root has 1 (right) child
       {
            btNode* oldroot_ptr = bst_root;
            bst_root = bst_root->right;
            delete oldroot_ptr;
       }
       else if (bst_root->left != 0 && bst_root->right != 0)    // root has 2 children
       {
           bst_remove_max(bst_root->left, bst_root->data);
       }
       return true;
    }
    return false;
}

// write definition for bst_remove_max here
void bst_remove_max(btNode*& bst_root, int& removed)    //TODO: this function doesn't seem to be working correctly
{
    if (bst_root == 0) return;

    if (bst_root->right == 0)
    // TODO: copy root nodes data into the data field ref parameter
    // delete root node and make left child (may be 0) the new root
    {
        btNode* oldroot_ptr = bst_root;
        removed = bst_root->data;
        bst_root = bst_root->left;
        delete oldroot_ptr;
    }
    else
        bst_remove_max(bst_root->right, removed);
}




