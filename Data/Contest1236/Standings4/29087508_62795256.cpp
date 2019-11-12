#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 305;
int arr[N][N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
    #endif
    int n;
    cin >> n;
    int element = 1;
    for(int i = 1; i <= n; i++)
    {
      if(i & 1)
        for(int j = 1; j <= n; j++)
          arr[j][i] = element++;
      else
        for(int j = n ; j >= 1; j--)
          arr[j][i] = element++;
    }
    for(int i = 1; i <= n; i++)
    {
      for(int j = 1; j <= n; j++)
        cout << arr[i][j] << ' ';
      cout << '\n';
    }
    return 0;
}
