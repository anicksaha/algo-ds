class Solution {
public:
    
    string _convert(int hours, int minutes) {
        string H = to_string(hours);
        string M = (minutes<10) ? "0" + to_string(minutes) : to_string(minutes);
        return H+":"+M;
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> ANS;
       
        for(int i=0;i<pow(2,4);i++) {
            int hours = 0;
            for(int _i=0;_i<32;_i++) 
                hours|=(i & (1<<_i));
            
            for(int j=0;j<pow(2,6);j++) {
                int minutes = 0;
                for(int _j=0;_j<32;_j++) 
                    minutes|=(j & (1<<_j));
                
                if(__builtin_popcount(hours) + __builtin_popcount(minutes) == num && hours<12 && minutes<60) {
                    ANS.push_back(_convert(hours,minutes));
                }
            }
        }
        
        return ANS;
    }
};