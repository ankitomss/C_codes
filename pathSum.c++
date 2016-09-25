#include<iostream>
using namespace std;

/**
 * Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(NULL==root)
            return false;
        if(root->val == sum && root->left == NULL && root->right == NULL)
            return true;
        
        sum=sum-root->val;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
            
    }
};

int main()
{

}
