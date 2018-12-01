// https://leetcode.com/problems/toeplitz-matrix/description/

class Solution {
public:
    
    // Another approach
    bool isToeplitzMatrix_0(vector<vector<int>>& matrix) {
        for (int i=1;i<matrix.size();i++)
            for (int j=1;j<matrix[0].size();j++)
                if (matrix[i-1][j-1]!=matrix[i][j])
                    return false;
        return true;
    }
    
    
    /* 
    Same diagonal (i1,j1) and (i2,j2) if (i1-j1) == (i2-j2)
    */
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        map<int,int> diagonalGroups;
        
        for (int i=0;i<matrix.size();i++) {
            for (int j=0;j<matrix[0].size();j++) {
                if(diagonalGroups.find(i-j)!=diagonalGroups.end()) {
                    if(diagonalGroups[i-j] != matrix[i][j])
                        return false;
                } else {
                    diagonalGroups[i-j] = matrix[i][j];
                }
            }
        }
        return true;
    }
};