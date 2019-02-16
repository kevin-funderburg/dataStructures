#include "btNode.h"
#include <iostream>
#include <cmath>
using namespace std;

// returns number of nodes in the tree
int  tree_size(btNode* avl_root)
{
   if (avl_root == 0) return 0;
   return 1 + tree_size(avl_root->left) + tree_size(avl_root->right);
}

// returns height of the tree
int height(btNode* root)
{
   if (root == 0) // base case
      return -1;
   int heightLST = height(root->left),
       heightRST = height(root->right);
   return (heightLST > heightRST) ? 1 + heightLST : 1 + heightRST;
}

// return true if AVL tree, otherwise false
bool isAVL(btNode* root)
{
   if(root == 0) return true;
   int heightLST,
       heightRST;
   if (root->right != 0 || root->left != 0)
   {
      heightLST = height(root->left);
      heightRST = height(root->right);
      if ( abs(heightLST - heightRST) > 1 ||
           abs(heightRST - heightLST) > 1)
         return false;
   }
   return isAVL(root->left) && isAVL(root->right);
}

// a non-fancy way to display binary tree
void tree_print(btNode* root, int level)
{
   tree_print_aux(root, root, level);
}

// recursive helper function called by tree_print
void tree_print_aux(btNode* root, btNode* ptr, int level)
{
    if (ptr != 0)
    {
        tree_print_aux(root, ptr->right, level + 1);
        cout << '\n';
        if (ptr == root) cout << "ROOT-=< ";
        for (int i = 0; i < level && ptr != root; ++i)
            cout<<"        ";
        cout << ptr->data;
        tree_print_aux(root, ptr->left, level + 1);
    }
}

// releases dynamically allocated node memory use by
// the tree to heap and set the tree to empty tree
void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

//////////////////////////////////////////////////////////////////////

// wrapper function that initiates recursive process of avl_insert_aux
// (return value from the initiating call not captured/used)
void avl_insert(btNode*& avl_root, int insInt)
{
   avl_insert_aux(avl_root, insInt);
}

// adds item (with data insInt) to tree rooted at avl_root
// tree is unchanged if a matching item already exists
// return value is the change in depth in the tree
// (for use by ancestor nodes to correct balance factors)
int avl_insert_aux(btNode*& avl_root, int insInt)
{

    if (avl_root == NULL)                // Empty tree
    {
        avl_root = new btNode;
        avl_root->data = insInt;
        avl_root->left = avl_root->right = NULL;
        return 1;
    }
    else if (avl_root->data == insInt)      // insInt is already in tree so do nothing
        return 0;

    //TODO - figure out what to do with this variable
    int heightChange = 0, test1, test2;

    /// A recursive call is made to add the new item to the appropriate subtree of the current node,
    /// capturing the return value (change in height) in a local variable.
    if (insInt < avl_root->data)
        heightChange += avl_insert_aux(avl_root->left, insInt);

    else if (insInt > avl_root->data)
        heightChange += avl_insert_aux(avl_root->right, insInt);

//    cout << "inserting: " << insInt << endl;
//    cout << "node count: " << tree_size(avl_root) << endl;

    test1 = height(avl_root->right);
    test2 = height(avl_root->left);
    if (test1 > test2)
        cout << "right > left: " << test1 << " > " << test2 << endl;
    else if (test2 > test1)
        cout << "right < left: " << test1 << " < " << test2 << endl;
    else
        cout << "right = left: " << test1 << " = " << test2 << endl;

//    cout << "test : " << test << endl;
    /// If the height of the "added-to" subtree has not changed, then the balance factor of the
    /// current node should also remain unchanged.
    if (heightChange != 0)
    {
        avl_root->bf = height(avl_root->right) - height(avl_root->left);

        /// If the height of the "added-to" subtree has increased, then 3 cases are possible:

        // Height is unchanged
        if (avl_root->bf == 0)
            return 0;

        // bf is still tolerable
        else if (avl_root->bf == 1 || avl_root->bf == -1)
            return 1;

        /// CASE 3
        /// The "added-to" subtree was previously TALLER than the other subtree of the
        /// current node and the "added-to" subtree grew taller when the new node is added.
        ///      Adding the new node makes the tree rooted at current node INTOLERABLY out of
        ///      balance (one subtree is now 2 taller than the other) such that appropriate
        ///      rotation operations must be applied to correct the imbalance.

        /// If "balance factor at current node" and "balance factor at root of subtree
        /// that grew taller" have same sign, single rotation is sufficient; otherwise, 
        /// double rotation is needed.
        //TODO - maybe can check the height of the subtrees and use that to decide how to pass to the rebalancers
        else
        {
            // right left case
            if (avl_root->bf < 0 && insInt < avl_root->left->data)
                rebalanceL(avl_root);

            // left right case
            else if (avl_root->bf > 0 && insInt > avl_root->right->data)
                rotateL(avl_root);

            // left left case
            else if (avl_root->bf > 0 && insInt < avl_root->left->data)
                rebalanceR(avl_root);

            // right right case
            else if (avl_root->bf < 0 && insInt > avl_root->right->data)
                rebalanceL(avl_root);

//            avl_root->bf = height(avl_root->right) - height(avl_root->left);    // update bf after rotation

        }

    }


//    return heightChange;
}

// rebalances an out-of-balance node with taller LST
// does single or double rotation depending on left child's bf
void rebalanceL(btNode*& avl_root)
{
    if (avl_root->bf < 0 && avl_root->left->bf < 0) {
        rotateR(avl_root);
    } else if (avl_root->bf > 0 && avl_root->left->bf > 0) {
        rotateL(avl_root);
    } else {
        rotateL(avl_root);
        rotateR(avl_root);
    }

    avl_root->bf = height(avl_root->right) - height(avl_root->left);    // update bf after rotation
}

// rebalances an out-of-balance node with taller RST
// does single or double rotation depending on right child's bf
void rebalanceR(btNode*& avl_root)
{
    if (avl_root->bf < 0 && avl_root->right->bf < 0) {
        rotateL(avl_root);
    } else if (avl_root->bf > 0 && avl_root->right->bf > 0) {
        rotateR(avl_root);
    } else {
        rotateL(avl_root);
        rotateR(avl_root);
    }

    avl_root->bf = height(avl_root->right) - height(avl_root->left);    // update bf after rotation
}

// does single left rotation of the tree
// does NOT update bf's (any needed update is to be done @ caller level)
void rotateL(btNode*& avl_root)
{
    struct btNode *x = avl_root->right;
    struct btNode *T2 = x->left;

    // Perform rotation
    avl_root->left = x;
    x->right = T2;
}

// does single right rotation of the tree
// does NOT update bf's (any needed update is to be done @ caller level)
void rotateR(btNode*& avl_root)
{
    struct btNode *x = avl_root->left;
    struct btNode *T2 = x->right;

    // Perform rotation
    x->right = avl_root;
    avl_root->left = T2;
}
