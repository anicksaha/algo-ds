/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    
    Node* _getAns(Node* quadTree1, Node* quadTree2) {
        
        if(!quadTree1 || !quadTree2) {
            return quadTree1!=NULL ? quadTree1 : quadTree2; 
        }
        
        if(quadTree1->isLeaf) {
            if (quadTree1->val) 
                return new Node(true, true, NULL, NULL, NULL, NULL);
            else 
                return quadTree2; 
        }
        else if(quadTree2->isLeaf) {
            if (quadTree2->val) 
                return new Node(true, true, NULL, NULL, NULL, NULL);
            else 
                return quadTree1; 
        }
        else { 
            Node* node = new Node(); 
            node->topLeft = _getAns(quadTree1->topLeft, quadTree2->topLeft);
            node->topRight = _getAns(quadTree1->topRight, quadTree2->topRight);
            node->bottomLeft = _getAns(quadTree1->bottomLeft, quadTree2->bottomLeft);
            node->bottomRight = _getAns(quadTree1->bottomRight, quadTree2->bottomRight);
    
            if(node->topLeft->val && node->topRight->val && node->bottomLeft->val && node->bottomRight->val) {
                if(node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf && node->bottomRight->isLeaf) {
                    node->val = true; 
                    node->isLeaf = true;
                    return node; 
                }
            }
            
            if(!node->topLeft->val && !node->topRight->val && !node->bottomLeft->val && !node->bottomRight->val) {
                if(node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf && node->bottomRight->isLeaf) {
                    node->val = false; 
                    node->isLeaf = true;
                    return node; 
                }
            }
            
            node->isLeaf = false;
            return node; 
        }
    }
    
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        
        if(!quadTree1 || !quadTree2) {
            return quadTree1!=NULL ? quadTree1 : quadTree2; 
        }
        
        return _getAns(quadTree1, quadTree2);
    }
};