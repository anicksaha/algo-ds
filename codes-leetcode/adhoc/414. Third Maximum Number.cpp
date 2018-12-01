// https://leetcode.com/problems/third-maximum-number/description/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> S(nums.begin(), nums.end());
        vector<int> vec(S.begin(), S.end());
        return vec.size()>=3 ? vec[vec.size()-3] : vec[vec.size()-1];
    }
};