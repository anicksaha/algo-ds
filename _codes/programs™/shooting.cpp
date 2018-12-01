#include<iostream>

using namespace std;

int main()
{
    int  t;
    cin>>t;
    while(t--)
    {
        unsigned long long int ans,temp,n,idx;
        cin>>n;
        idx=(n/2)+1;
        
        //cout<<idx<<" @@ "<<endl;
        
        if(idx%2==1)
        {
            idx/=2;
            idx++;
            ans=(idx*idx)%10000001;
        }
            
        else
        {
            idx/=2;
            ans=(idx*(idx+1))%10000001;
        }
            
            
        cout<<ans<<endl;
    }
}