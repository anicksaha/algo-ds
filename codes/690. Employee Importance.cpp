/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    
    vector<int> ADJ[2001];
    int _importance[2001];
    
    void getAns(int node, int& ans) {
        ans+=_importance[node];
        for(int i=0;i<ADJ[node].size();i++) {
            getAns(ADJ[node][i],ans);
        }    
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        
        for(int i=0;i<employees.size();i++) {
            ADJ[employees[i]->id] = employees[i]->subordinates;
            _importance[employees[i]->id] = employees[i]->importance;
        }    
        
        getAns(id,ans);
        
        return ans;
    }
};