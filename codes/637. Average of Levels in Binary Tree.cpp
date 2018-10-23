// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

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
    
    double _average(vector<int> data) {
        double sum = 0;
        for(int i=0;i<data.size();i++) {
            sum+=data[i];
        }
        sum/=data.size();
        return sum;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ANS;
        
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
                ANS.push_back(_average(levelNodes));
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
        
        return ANS;
    }
};