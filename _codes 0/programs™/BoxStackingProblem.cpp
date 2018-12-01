/* Dynamic Programming implementation of Box Stacking problem */
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

/* Representation of a box */
struct Box
{
  // h –> height, w –> width, d –> depth
  int h, w, d;
};

int compare (Box A,Box B)
{
    if((A.d*A.w)>(B.d*B.w))
        return true;
    return false;
}

/* Returns the height of the tallest stack that can be formed with give type of boxes */
int maxStackHeight( Box arr[], int n )
{
   /* Create an array of all rotations of given boxes
      For example, for a box {1, 2, 3}, we consider three
      instances{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}} */
   Box rot[3*n];
   int index = 0;
   for (int i = 0; i < n; i++)
   {
        int a,b,c;
        a=arr[i].h,b=arr[i].w,c=arr[i].d;
      // Copy the original box
      rot[index].h = a;
      rot[index].d = b;
      rot[index].w = c;
      index++;

      // First rotation of box
      rot[index].h = b;
      rot[index].d = c;
      rot[index].w = a;
      index++;

      // Second rotation of box
      rot[index].h = c;
      rot[index].d = a;
      rot[index].w = b;
      index++;
   }

   // Now the number of boxes is 3n
   n = 3*n;

   sort(rot,rot+n,compare);
   int msh[n]; // maximum stack height :: DP
   for (int i = 0; i < n; i++ )
      msh[i] = rot[i].h;

   /* Compute optimized msh values in bottom up manner */
   for (int i = 1; i < n; i++ )
    for (int j = 0; j < i; j++ )
    if (  ((rot[i].w < rot[j].w && rot[i].d < rot[j].d) || (rot[i].w < rot[j].d && rot[i].d < rot[j].w) ) && msh[i] < msh[j] + rot[i].h)
    {
        msh[i] = msh[j] + rot[i].h;
    }


   /* Pick maximum of all msh values */
   int max = *max_element(msh,msh+n);

   return max;
}


int main()
{
  while(1)
  {
      int n;
      cin>>n;
      if(n==0)
        break;
      Box arr[n];
      for(int i=0;i<n;i++)
        cin>>arr[i].h>>arr[i].w>>arr[i].d;
      printf("%d\n",maxStackHeight (arr, n) );
  }
  return 0;
}
