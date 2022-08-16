#include <bits/stdc++.h>

using namespace std;


int main()
{
  int n;
  cin >> n;
  int a[n];
  int counter[n];
  memset(counter, 0, sizeof(counter));
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    counter[a[i]]++;
  }
  int count = 0;
  for(int i=0; i<n; i++)
  {
    if(counter[i]>0)
    {
      count++;
    }
  }
  cout<<count<<endl;
  return 0;
}