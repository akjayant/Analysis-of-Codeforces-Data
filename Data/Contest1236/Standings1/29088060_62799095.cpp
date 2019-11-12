#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double rl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define mp make_pair

#if 1
#define dbg(x) cerr << #x << ": " << (x) << endl;
#else
#define dbg(x)
#endif // 1

const int MX=309;
int res[MX][MX];
int n;

/*
int score()
{
    int result=n*n;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {

            int curr=0;
            for(int u=0; u<n; u++)
            {
                for(int v=0; v<n; v++) curr+=res[i][u]>res[j][v];
            }

            result=min(result, curr);
            result=min(result, n*n-curr);

        }
    }

    return result;
}
*/

int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);


    cin >> n;

    for(int j=0; j<n; j++)
    {
        int base=j*n;

        for(int i=0; i<n; i++)
        {
            if(j%2==0)
            res[i][j]=base+i;
            else
            res[i][j]=base+(n-1-i);
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) cout << 1+res[i][j] << ' ';
        cout << '\n';
    }

    //int max_poss=(n*n)/2;
    //dbg(score());
    //dbg(max_poss);

    return 0;
}
