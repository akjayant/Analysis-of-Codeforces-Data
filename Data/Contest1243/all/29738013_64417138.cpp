#include <bits/stdc++.h>

#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sz size()
#define m_p make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef vector <pii> vpi;
typedef vector <pll> vpl;

ll n , Q, i, k, m;
string s, s1;
vector <pll> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    while(Q--)
    {
        cin >> n;
        cin >> s >> s1;
        ans.clear();
        for(i = 0; i < n; i++)
        {
            if(s[i] != s1[i])
            {
                bool f = 0;
                for(int j = i + 1; j < n; j++)
                {

                    if(s[j] == s1[j]) continue;
                    if(s1[j] == s1[i])
                    {
                        ans.pb({i + 1, j + 1});
                        swap(s[i], s1[j]);
                        f = 1;
                        break;
                    }
                }
                if(f == 1)continue;
                for(ll j = i + 1; j < n; j++)
                {
                    if(s[j] == s1[j])continue;
                    if(s[j] == s1[i]){
                        ans.pb({j + 1, j + 1});
                        swap(s[j], s1[j]);
                        ans.pb({i + 1, j + 1});
                        swap(s[i], s1[j]);
                        f = 1;
                        break;
                    }
                }
            }
        }

        if(s == s1 && ans.size() <= n * 2)
        {
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for(auto it : ans) cout << it.ft << " " <<it.sd << endl;
        }
        else cout << "No" << endl;;
    }
    return 0;
}
