class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        unordered_map<int,int> M;
        int currSum = 0;
        for(int i=0;i<nums.size();i++) {
            currSum+=nums[i];
            if(nums[i]==0) {
                return {i,i};  
            } else if(currSum==0) {
                return {0,i};
            }
            if(M.find(currSum) == M.end()) {
                M[currSum] = i;
            } else {
                return {M[currSum]+1,i};
            }
        }
    }
};