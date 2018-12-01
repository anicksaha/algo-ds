// https://leetcode.com/problems/sum-of-left-leaves/description/

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
    
    bool isLeaf(TreeNode* node) {
        return (!node->left && !node->right); 
    }
    
    void getSum(TreeNode* node, int& sum, bool isLeft) {
        if(!node) {
            return;
        }
        
        if(isLeaf(node) && isLeft) {
            sum+=(node->val);
        }

        getSum(node->left,sum,true);
        getSum(node->right,sum,false); 
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        getSum(root,sum,false);
        return sum;
    }
};