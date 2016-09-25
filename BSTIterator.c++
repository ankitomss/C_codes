/* * BSTIterator.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: ankitverma
 */

#include <iostream>
#include <stack>

using namespace std;

/**
 * Definition for binary tree */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class BSTIterator {
public:
    TreeNode * it;
    stack<TreeNode *> my_stack;

    BSTIterator(TreeNode *root) {
        it = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !my_stack.empty();
    }

    /** @return the next smallest number */
    int next() {

        TreeNode *temp_it=it;
        if(it==NULL) return -1;

        if(temp_it->left == NULL) {
            it = my_stack.top();
	    my_stack.pop();
            return it->val;
        }

        //my_stack.push(temp_it);

                temp_it=temp_it->left;
                my_stack.push(temp_it);
                while(temp_it->right != NULL) {
                    temp_it = temp_it->right;
                    my_stack.push(temp_it);
                }
                it=my_stack.top();
		my_stack.pop();
                return it->val;



    }


};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */




