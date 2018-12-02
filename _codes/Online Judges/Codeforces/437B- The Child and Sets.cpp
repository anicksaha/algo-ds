#include<bits/stdc++.h>
using namespace std;

list<int> nums[100010];
int cnt[100010];

vector<int> idx;
vector<int> Times;
int main()
{
    int sum,limit;
    cin>>sum>>limit;

    int two_max_power=0;

    for(int i=1;i<=limit;i++)
    {
        int temp=i & (~i + 1);
        nums[temp].push_back(i);
        two_max_power=max(two_max_power,temp);
        cnt[temp]++; // lowbit representation of that number : eg - 101000100 -> 000000100
    }

    int total=0;

    for(int i=two_max_power; i>=1; i>>=1)
    {
        if(cnt[i]>0 && sum>=i)
        {
            int times=sum/i;
            if(cnt[i]>=times)
            {
                sum-=(times*i);
                cnt[i]-=times;
                idx.push_back(i);
                Times.push_back(times);
                total+=times;
            }
            else
            {
                sum-=(cnt[i]*i);
                idx.push_back(i);
                Times.push_back(cnt[i]);
                total+=cnt[i];
                cnt[i]=0;
            }
        }

    }  //FOR


    if(sum!=0)
    {
        cout<<"-1"<<endl;
        return 0;
    }

    list<int>::iterator it;
    cout<<total<<endl;
    int j;

    for(int i=0;i<idx.size();i++)
        for(it=nums[idx[i]].begin(),j=0; j<Times[i]; j++,it++)
           cout<<*it<<" ";

    return 0;
}
