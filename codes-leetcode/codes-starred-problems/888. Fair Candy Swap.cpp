class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        
        /*
        > Note that the problem statement says that Alice and Bob need to exchange one candy each, no more or no less.
        > Assume x needs to be removed and y needs to be added to A to equalize, so:
        > Sum(A) - x + y = Sum(B) - y + x
        > Sum(A) - Sum(B) = -2y + 2x
        > x = ((Sum(A) - Sum(B)) / 2) + y
        > lets call ((Sum(A) - Sum(B)) / 2), delta
        */
        
        int sumA = 0;
        for(int i=0;i<A.size();i++)
            sumA+=A[i];
        
        int sumB = 0;
        for(int i=0;i<B.size();i++)
            sumB+=B[i];
        
        int delta = (sumA - sumB) / 2;
        
        set<int> searchA;
        for(auto x : A) {
            searchA.insert(x);
        }
        
        for(auto y : B) {
            if (searchA.count(delta + y) > 0) {
                return vector<int>{delta + y, y};
            }
        }
    }
};