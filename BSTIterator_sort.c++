/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    TreeNode * it;
    stack<TreeNode *> my_stack;
    
    BSTIterator(TreeNode *root) {
        it = root;
        if(root!=NULL) pushright(it);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !my_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        
        it = my_stack.top();
        my_stack.pop();
        if(it->left!=NULL) pushright(it->left);
        return it->val;
    }
    
    void pushright(TreeNode * node){
        if(node->left!=NULL) my_stack.push(node->left);
        my_stack.push(node);
        TreeNode *temp = node;
        while(temp->right!=NULL){
            temp=temp->right;
            my_stack.push(temp);
        }
    }
    
    
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
