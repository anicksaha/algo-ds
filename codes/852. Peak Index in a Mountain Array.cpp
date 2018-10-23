// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for(int i=1;i<A.size()-1;i++){
            if(A[i]>A[i-1] && A[i]>A[i+1])
                return i;
        }
     }
};