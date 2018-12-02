#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(a[i]>a[j])
                {
                    ans++;
                    swap(a[i],a[j]);
                }

        cout<<"Optimal train swapping takes "<<ans<<" swaps."<<endl;
    }
}
