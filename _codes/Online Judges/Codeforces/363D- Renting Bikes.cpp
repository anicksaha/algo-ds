#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
int commonBudget, n, m, personal[N], price[N];

int main()
{
	cin>>n>>m>>commonBudget;
	for(int i=0;i<n;i++)
        cin>>personal[i];
	for(int i=0;i<m;i++)
        cin>>price[i];

	sort(price, price + m);
    sort(personal, personal + n);

	int low = 0, high = min(n, m)-1;
	int ans=-1;

	while(low<=high)
    {
		int mid=(low+high+1)>>1, remain=commonBudget;
		bool ok = true;

		for(int i=mid,x=n-1; i>=0; i--,x--)
        {
			if(personal[x]+remain>=price[i])
				remain-= max(0, price[i]-personal[x]);
			else
				ok=false;
		}
		if(ok)
            low=mid+1,ans=max(ans,mid);
		else
            high=mid-1;
	}

    // low -> till where bikes can be afforded :)
	cout<<ans+1<<" "<<max(0LL,accumulate(price, price + ans+1, 0LL)-commonBudget);
	return 0;
}
