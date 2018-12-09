#include<iostream>
#include<set>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int arr[1010];
int l[1010];


int main()
{
	int t,n,ans;
    scanf("%d",&t);
    while(t--)
	{

    scanf("%d",&n);

   	for(int i=0;i<n;i++)
   	{
		scanf("%d",&arr[i]);
		l[i]=1;
	}


    for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                     if(arr[i]>=arr[j] && l[i]<l[j]+1)
                              l[i]=l[j]+1;

    ans=*max_element(&l[0],&l[n]);

    printf("%d\n",ans);

	}

	return 0;
}
