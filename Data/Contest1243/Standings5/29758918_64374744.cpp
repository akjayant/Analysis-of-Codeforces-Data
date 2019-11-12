#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
      int n;
      cin >> n;
      int i,a[n];
      for(i=0;i<n;i++)
      {
          cin >> a[i];
      }
      sort(a,a+n);
      int c=0;
      int k=1;
      for(i=n-1;i>=0;i--)
      {
          if(a[i]>=k)
          {
              c++;
              k++;
          }
          else
          {
              break;
          }
      }
      cout << c << "\n";
    }
}
