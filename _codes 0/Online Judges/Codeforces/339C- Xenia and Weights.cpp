#include<bits/stdc++.h>
using namespace std;

bool w[11];
vector<int>ans;
int m;

bool getans(int idx,bool lpan,bool rpan,int prev,int left,int right)
{
    if(idx==m+1)
        return true;

    vector<int>temp;
    int left_new,right_new;

    vector<int>::iterator it;

    for(int i=1;i<=10;i++)
    if(w[i]==true && i!=prev)
        temp.push_back(i); // weights that can be used now

    if(lpan)
    {
        for(it=temp.begin();it!=temp.end();it++)
        if( *it+left>right)
        {
            left_new=*it+left;

            if(getans(idx+1,false,true,*it,left_new,right))
            {
                ans.push_back(*it);return true;
            }
        }
    }
    else
    {
        for(it=temp.begin();it!=temp.end();it++)
        if(*it+right>left)
        {
            right_new=*it+right;
            if(getans(idx+1,true,false,*it,left,right_new))
            {
                ans.push_back(*it);
                return true;
            }
        }
    }

    return false;

}

int main()
{
    string s;
    cin>>s;
    cin>>m;

    for(int i=0;i<10;i++)
        if(s[i]=='1')
            w[i+1]=true;

    bool flag;

    flag=getans(1,true,false,0,0,0); // idx - lpan - rightpan - previous - Ledt Weight - Right Weight

    vector<int>::iterator it;

    if(flag==false)
        cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        for(it=ans.end()-1;it>=ans.begin();it--)
            cout<<*it<<" ";
    }

    return 0;
}
