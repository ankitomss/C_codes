#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int start=0;
        int end=inorder.size();
        return _buildTree(preorder, inorder, start, end-1);
    }
    
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if(start == end){
            return new TreeNode(inorder[start]);
        }
        if(start > end) {
            return NULL;
        }
        
        int prei = findfirst(preorder, inorder, start, end);
        int ini=search(inorder, preorder[prei]);
        TreeNode * node = new TreeNode(preorder[prei]);
        node->left = _buildTree(preorder, inorder, start, ini-1);
        node->right = _buildTree(preorder, inorder, ini+1, end);
        return node;
    }
    
    int findfirst(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        int len = preorder.size();
        int pos=len+10;
        int index;
        vector<int>::iterator it;
        for(int i=start; i<=end; i++) {
            it = find(preorder.begin(), preorder.end(), inorder[i]);
            index = distance(preorder.begin(), it);
            pos = min(pos, index);
        }
        return pos;
    }
    
    int search(vector<int>& inorder, int val){
        vector<int>::iterator it;
        it = find(inorder.begin(), inorder.end(), val);
        int index = distance(inorder.begin(), it);
        return index;
    }

	void printTree(TreeNode* node){
		if (node == NULL) return;

		printTree(node->left);
		cout << node->val;
		printTree(node->right);

	}
};

int main(){
	vector<int> inorder;
	vector<int> preorder;
	inorder.push_back()
}

