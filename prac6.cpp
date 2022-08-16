#include <bits/stdc++.h>

using namespace std;

void sortArray(int a[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i; j++)
    {
      if (a[j] > a[j + 1])
      {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}
int binarySearch(int *a, int lb, int ub, int val)
{
  if (lb <= ub)
  {
    int mid = (ub + lb) / 2;
    if (val == a[mid])
    {
      return mid;
    }
    else if (val < a[mid])
    {
      ub = mid - 1;
       binarySearch(a, lb, ub, val);
    }
    else
    {
      lb = mid + 1;
      binarySearch(a, lb, ub, val);
    }
  }
  else
  {
    return -1;
  }
 
}
int main()
{
  int n, val;
  cin >> n >> val;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sortArray(a,n);
  int x = binarySearch(a, 0, n - 1, val);
  if(x==-1)
  {
    cout<<"The searched value doesnt exits"<<endl;
  }
  else
  {
  cout<< x+1 << endl;
  }

  return 0;
}