#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 1000000007
#define INF 1000000000
#define MX 300010
#define pi 2.0*acos(0.0)

typedef pair<int, int> PII;

int freq[50];

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int tc;
    cin >> tc;
    FOR(tt, 1, tc)   {
        int n;
        string s1, s2;
        cin >> n >> s1 >> s2;
        vector<int> mis;
        MEM(freq, 0);
        int chk = 0;
        FOR(i, 0, n - 1)   {
            if(s1[i] != s2[i])    {
                mis.PB(i);
            }
            else    {
                freq[ s1[i] - 'a' ]++;
                chk = max(chk, freq[ s1[i] - 'a' ]);
            }
        }
        if(mis.size() == 2 || mis.size() == 0)    {
        }
        else    {
            cout << "No\n";
            continue;
        }

        if(mis.size() == 0)    {
            if(chk >= 2)    {
                cout << "Yes\n";
            }
            else    {
                cout << "No\n";
            }
            continue;
        }

        if(mis.size() == 2)    {
            if((s1[ mis[0] ] == s1[ mis[1] ]) && (s2[ mis[0] ] == s2[ mis[1] ]))    {
                cout << "Yes\n";
            }
            else    {
                cout << "No\n";
            }
        }

    }
    return 0;
}
