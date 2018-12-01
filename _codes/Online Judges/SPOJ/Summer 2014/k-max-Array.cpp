#include<bits/stdc++.h>
using namespace std;

int arr[1000001];

void printKMax(int n, int k)
{
    deque<int>  Qi(k);

    int i;
    for (i=1;i<= k;i++)
    {
        while((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }

    for (i=k+1;i<=n;i++)
    {
        cout<< arr[Qi.front()]<<" ";

        while((!Qi.empty()) && Qi.front()<=i-k)
            Qi.pop_front();

        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();

        Qi.push_back(i);
    }

    cout << arr[Qi.front()];
}

// Driver program to test above functions
int main()
{
    //int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n ,k;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cin>>k;
    printKMax(n, k);
    return 0;
}
