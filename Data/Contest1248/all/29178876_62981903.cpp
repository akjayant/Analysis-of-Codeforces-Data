#include<iostream>
using namespace std;
const int maxN = 2e5 + 2;
int t;
int n, m;
int a[maxN];
int b[maxN];
long long ca[2], cb[2];
long long cnt = 0;
int main()
{
      ios::sync_with_stdio(false);
      cin >> t;
      while(t--)
      {
            cnt = ca[0] = ca[1] = cb[0] = cb[1] = 0;
            cin >> n;
            for(int i = 0; i < n; i++)
                cin >> a[i];
            for(int i = 0; i < n; i++)
                ++ca[a[i]%2];
            cin >> m;
            for(int i = 0; i < m; i++)
                cin >> b[i];
            for(int i = 0; i < m; i++)
                ++cb[b[i]%2];
            cnt = ca[0] * cb[0] + cb[1] * ca[1];
            cout << cnt << '\n';      
      }
      return 0;
}