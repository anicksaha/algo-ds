#include <bits/stdc++.h>


using namespace std;

int n;

int a[1010];

void heapify(int x)
{
    int largest=x;

    int left=x<<1;
    int right=(x<<1)+1;

    if(left<=n && a[left]>a[largest])
          largest=left;
    if(right<=n && a[right]>a[largest])
         largest=right;


    if(largest!=x)
    {
        swap(a[x],a[largest]);
        heapify(largest);
    }
}

void buildheap(int n)
{
    for(int i=n/2;i>=1;i--)
    {
        heapify(i);
    }

}
int main()
{


  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];


  buildheap(n);

  cout<<a[1]<<endl;
  int l=n;
  for(int i=1;i<l;i++)
  {
      swap(a[1],a[n]);
      n--;
      heapify(1);
      cout<<a[1]<<endl;
  }

}
