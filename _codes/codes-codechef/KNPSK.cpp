#include <bits/stdc++.h>
using namespace std;

long long ans[200010];
vector<int> one, two, copy1, copy2;

int main()
{
     //freopen("C:\\Users\\Anick\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\Anick\\Desktop\\out.txt","w",stdout);

	int c,w,n,W=0;
	cin>>n;

	for (int i = 0; i < n; i++)
    {
		cin>>w>>c;
        (w==1)?one.push_back(c):two.push_back(c);
		W += w;
	}

	sort(one.begin(),one.end());
	sort(two.begin(),two.end());

	copy1=one;
    copy2=two;

	long long curr=0;
	int flag;
	for (int w=2;w<=W;w+=2) //even
    {
        int TWOS = 0;
        int ONES = 0;

        if(two.size()>=1)
            TWOS=two.back();

        if(one.size()>=2)
        {
            flag=2;
            ONES= one.back();
            ONES+= one[one.size()-2];
        }
        else if(one.size() >= 1)
        {
            flag = 1;
            ONES= one.back();
        }

        if (TWOS > ONES)
        {
            curr+=TWOS;
            two.pop_back();
        }
        else
        {
            curr+=ONES;
            if(flag == 2)
            {
                one.pop_back();
                one.pop_back();
            }
            else
            {
                one.pop_back();
            }
        }
        ans[w]=curr;
	}

	// construct odd
	one = copy1, two = copy2;

	curr=0;
	if(one.size()>=1)
    {
		curr=one.back();
		one.pop_back();
	}
	ans[1]=curr;
	for (int w=3;w<=W; w+=2)
    {
        int TWOS = 0;
        int ONES = 0;

        if(two.size()>=1)
            TWOS=two.back();

        if(one.size()>=2)
        {
            flag=2;
            ONES= one.back();
            ONES+= one[one.size()-2];
        }
        else if(one.size() >= 1)
        {
            flag = 1;
            ONES= one.back();
        }

        if (TWOS > ONES)
        {
            curr+=TWOS;
            two.pop_back();
        }
        else
        {
            curr+=ONES;
            if(flag == 2)
            {
                one.pop_back();
                one.pop_back();
            }
            else
            {
                one.pop_back();
            }
        }
        ans[w]=curr;
	}

	for(int w=1;w<=W;w++)
		printf("%lld ",ans[w]);

	return 0;
}
