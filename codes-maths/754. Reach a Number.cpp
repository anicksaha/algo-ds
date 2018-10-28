class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);        
        int k = 1;
        while (1) {
            target-=k;
            if(target<=0)
                break;
            k++;
        }
        int delta = abs(target);
        
        if(delta==0 || delta%2==0) {
            return k;
        } else {
            if(k&1) { 
                // K is odd  
                k++; // delta is odd.
                k++; // delta becomes even
                return k;
            } else {
                // K is even
                k++; // delta becomes even
                return k;
            }
        }
    }
};