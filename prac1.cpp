#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long int n, k;
  cin>>n>>k;
  long long int a[n];
  for(long long int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  for(long long int i=0; i<k; i++)
  {
    for(long long int j=0; j<n-1; j++)
    {
      if(a[j]<a[j+1])
      {
        long long int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
  cout<<a[n-k]<<" ";
    for(long long int i=0; i<k; i++)
  {
    for(long long int j=0; j<n-1; j++)
    {
      if(a[j]>a[j+1])
      {
        long long int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
  cout<<a[n-k]<<endl;
  return 0;
}