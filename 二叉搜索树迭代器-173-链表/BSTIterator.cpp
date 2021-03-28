#include <iostream>
#include <vector>
#include "../basic_tool/basic.h"

using namespace std;

class BSTIterator
{
private:
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    vector<int> inorderTraval(TreeNode *root)
    {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    vector<int> arr;
    int tag;

public:
    BSTIterator(TreeNode *root)
    {
        tag = 0;
        arr = inorderTraval(root);
    }

    int next()
    {
        return arr[tag++];
    }

    bool hasNext()
    {
        return (tag < arr.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */