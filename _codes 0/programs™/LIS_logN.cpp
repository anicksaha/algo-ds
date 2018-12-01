#include<iostream>
#include<set>

#define pb push_back
#define mp make_pair

#define M 1000000007

using namespace std;


int LIS(int *arr, int n)
{
    set<int> aux;
    set<int>::iterator it;

    for(int i=0; i<n; i++)
    {
      aux.insert(arr[i]);
      it = aux.find(arr[i]);
      it++;

      if(it!=aux.end())
        aux.erase(it);
    }

    return aux.size();
}


int main()
{
   int n;
   cin>>n;
   int arr[n+1];

   for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<LIS(arr,n)<<endl;

    return 0;
}
