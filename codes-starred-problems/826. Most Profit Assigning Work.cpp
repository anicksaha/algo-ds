class Solution {
public:
    struct Job {
        int profit;
        int difficulty;
        bool operator<(const Job &X) const { 
            return (difficulty<X.difficulty);
        }
    };
        
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int N = difficulty.size();
        vector<Job> jobs;
        for (int i=0;i<N;i++) {
            jobs.push_back(Job{profit[i],difficulty[i]});
        }
                           
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
    
        int ans = 0;
        int bestProfit = 0;
        int j = 0;

        for(int i=0;i<worker.size();i++) {
            while(j<N && worker[i]>=jobs[j].difficulty)
                bestProfit = max(bestProfit,jobs[j++].profit);
            ans+=bestProfit;
        }

        return ans;
    }
};