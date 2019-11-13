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

string s1, s2;

int get_pos_s1(int pos, char ch)    {
    FOR(i, 0, pos)   {
        if(s1[i] == ch)    {
            return i;
        }
    }
    return -1;
}

int get_pos_s2(int pos, char ch)    {
    FOR(i, 0, pos)   {
        if(s2[i] == ch)    {
            return i;
        }
    }
    return -1;
}

vector<PII> ans;

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int tc;
    cin >> tc;
    FOR(tt, 1, tc)   {
        ans.clear();
        int n;
        cin >> n >> s1 >> s2;
        bool chk = 1;
        ROF(i, n - 1, 1)   {
            if(s1[i] == s2[i])    {
                continue;
            }
            int pos = get_pos_s2(i - 1, s2[i]);
            if(pos == -1)    {
                pos = get_pos_s1(i - 1, s2[i]);
                if(pos == -1)    {
                    chk = 0;
                    break;
                }
                swap(s1[pos], s2[pos]);
                ans.PB(MP(pos + 1, pos + 1));
                i++;
                continue;
            }
            else    {
                swap(s2[pos], s1[i]);
                ans.PB(MP(i + 1, pos + 1));
            }
        }
        if(s1[0] != s2[0])    {
            chk = 0;
        }

        if(!chk)    {
            cout << "No\n";
            continue;
        }
        else    {
            cout << "Yes\n";
            cout << ans.size() << "\n";
            FOR(i, 0, (int)ans.size() - 1)   {
                cout << ans[i].F << " " << ans[i].S << "\n";
            }
        }
    }

    return 0;
}
