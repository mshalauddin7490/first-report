#include <bits/stdc++.h>

using namespace std;

void sortArray(int a[], int n)
{
for(int i=1; i<n; i++)
{
  int j=i-1;
  int temp = a[i];
  while(temp<a[j] && j>=0)
  {
    a[j+1]= a[j];
    j--;
  }
  a[j+1] = temp;
  
}
}
int main()
{
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sortArray(a, n);
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  int count = 0;
  int i = 0;
  int j = n - 1;
  while (i < j)
  {
    if (a[i] + a[j] == k)
    {
      count++;
      i++;
      j--;
    }
    else
    {
      j--;
    }
  }
  cout << count << endl;
  return 0;
}