//http://www.csse.monash.edu.au/~lloyd/tildeAlgDS/Sort/Flag/

#include<bits/stdc++.h>
using namespace std;

/*
Lo := 1; Mid := 1; Hi := N;

while Mid <= Hi do
    Invariant: a[1..Lo-1]=0 and a[Lo..Mid-1]=1 and a[Hi+1..N]=2; a[Mid..Hi] are unknown.
    case a[Mid] in
        0: swap a[Lo] and a[Mid]; Lo++; Mid++
        1: Mid++
        2: swap a[Mid] and a[Hi]; Hi--
*/

int main()
{
    int arr[]={3,3,3,2,1,2,1,1,2};
    int low,mid,high;
    low=0;
    mid=0;
    high=sizeof(arr)/sizeof(int) - 1;


    while(mid<high)
    {
        if(arr[mid]==1)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==2)
            mid++;
        else if(arr[mid]==3)
        {
            swap(arr[mid],arr[high]);
            high--;
        }

    } // while

    for(int i=0;i<9;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
