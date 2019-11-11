#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
#define N 300005
//#define f first
//#define s second
//#define int long long
using namespace std;

const int MOD=1e9+7;
string s, res;
int T, n, a, b, c;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
//    freopen("A.inp","r",stdin);
//    freopen("A.out","w",stdout);
    cin >> T;
    while(T --)
    {
        cin >> n;
        cin >> a >> b >> c;
        cin >> s;
        res = "";
        int dem = 0;
        s = ' ' + s;
        FOR(i, 1, n)
        {
            if(s[i] == 'R' && b > 0)
            {
                b --;
                dem ++;
                res += 'P';
            }
            else if(s[i] == 'P' && c > 0)
            {
                c --;
                dem ++;
                res += 'S';
            }
            else if(s[i] == 'S' && a > 0)
            {
                a --;
                dem ++;
                res += 'R';
            }
            else
            {
                res += 'A';
            }
        }
        if(dem * 2 >= n)
        {
            cout << "YES \n";
//            cout << res;
            for(int i = 0; i < res.size(); i ++)
            {
                if(res[i] == 'A')
                {
                    if(a) a --, cout << 'R';
                    else if(b) b--, cout << 'P';
                    else cout << 'S';
                }
                else cout << res[i];
            }
        }
        else cout << "NO";
        cout << "\n";
    }

}
