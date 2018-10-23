// https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ANS;
        if(!root) {
            return ANS;
        }
        
        queue<Node*> Q;
        Q.push(root);
        Q.push(nullptr);
        vector<int> levelNodes;
        
        while(!Q.empty()) {
            Node* front = Q.front();
            Q.pop();
            
            if(!front) {
                ANS.push_back(levelNodes);
                levelNodes.clear();
                if(!Q.empty()){
                  Q.push(nullptr);  
                } 
            } else {
                levelNodes.push_back(front->val);
                vector<Node*> children = front->children;
                for(int i=0;i<children.size();i++) {
                    Q.push(children[i]);
                }
            }
        }
        
        return ANS;
    }
};