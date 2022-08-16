#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long int n, q, l, r;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  long long int prefix_sum[n];
  memset(prefix_sum, 0, sizeof(prefix_sum));
  prefix_sum[0] = a[0];
  for (long long int i = 1; i < n; i++)
  {
    if(a[i]>0)
    {
      prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }
    else
    {
      prefix_sum[i] = prefix_sum[i - 1];
    }
  }
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> l >> r;
    if (l == 1)
    {
      cout << prefix_sum[r - 1] << " ";
    }
    else
    {
      cout << prefix_sum[r - 1] - prefix_sum[l - 2] << " ";
    }
  }
  return 0;
}