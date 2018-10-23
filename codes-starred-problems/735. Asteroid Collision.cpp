class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> S;
        
        for(int i=0;i<asteroids.size();i++) {
                
            bool currDie = false;
            while(!S.empty() && asteroids[i]<0 && S.top()>0) {
                if (S.top() < -asteroids[i]) {
                    S.pop();
                } else if (S.top() == -asteroids[i]) {
                    S.pop();
                    currDie = true;
                    break;
                } else if(S.top() > -asteroids[i]){
                    currDie = true;
                    break;
                }
            }   
            if(!currDie)
                S.push(asteroids[i]);
        }

        vector<int> ANS;
        while(!S.empty()) {
            ANS.push_back(S.top());
            S.pop();
        }
        reverse(ANS.begin(), ANS.end());
        return ANS;
    }
};