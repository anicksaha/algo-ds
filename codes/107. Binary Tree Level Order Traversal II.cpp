// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ANS;
        if(!root) {
            return ANS;
        }
        
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(nullptr);
        vector<int> levelNodes;
        
        while(!Q.empty()) {
            TreeNode* front = Q.front();
            Q.pop();
            
            if(!front) {
                ANS.push_back(levelNodes);
                levelNodes.clear();
                if(!Q.empty()){
                  Q.push(nullptr);  
                } 
            } else {
                levelNodes.push_back(front->val);
                if(front->left)Q.push(front->left);
                if(front->right)Q.push(front->right);
            }
        }
        reverse(ANS.begin(), ANS.end());
        return ANS;
    }
};