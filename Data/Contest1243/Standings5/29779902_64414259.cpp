#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ss second
#define ff first
#define INF 1000000000000000001
#define PI 3.14159265358979323846L
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<pair<ll,ll> > vll;
typedef vector<pair<int,int> > vii ;
typedef pair<ll,ll> pll ;

int main()
{
    fast;
    int _ = 1;
    cin >> _;
    while(_--)
    {
        ll n, cnt[26] = {0}, ans = 1, x , y;
        cin >> n;
        string s, t;
        stack<int> a[26], b[26];
        cin >> s >> t;
        char c;
        for(int i = n - 1; i > -1; i--)
        {
            if(s[i] != t[i])
            {
                a[s[i] - 'a'].push(i);
                b[t[i] - 'a'].push(i);
                cnt[s[i] - 'a']++;
                cnt[t[i] - 'a']++;
            }
        }
        vii arr;
        for(int i = 0; i < 26; i++)
        {
            if(cnt[i] % 2) ans = 0;
        }
        if(ans) cout << "YES\n";
        else
        {
            cout << "NO\n";
            continue;
        }
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
            {
                bool done = 0;
                for(int j = i + 1; j < n; j++)
                {
                    if(s[i] == s[j] && s[j] != t[j])
                    {
                        arr.pb({j + 1, i + 1});
                        c = s[j];
                        s[j] = t[i];
                        t[i] = c;
                        done = 1;
                        break;
                    }
                }
                if(!done)
                {
                    for(int j = i + 1; j < n; j++)
                    {
                        if(s[i] == t[j] && s[j] != t[j])
                        {
                            for(int k = i + 1; k < n; k++)
                            {
                                if(k == j) continue;
                                if(s[k] != t[k])
                                {
                                    arr.pb({k + 1, j + 1});
                                    c = t[j];
                                    t[j] = s[k];
                                    s[k] = c;
                                    arr.pb({k + 1, i + 1});
                                    c = t[i];
                                    t[i] = s[k];
                                    s[k] = c;
                                    done = 1;
                                    break;
                                }
                                if(done) break;
                            }
                        }
                        if(done) break;
                    }
                }
                if(!done)
                {
                    arr.pb({i + 1, i + 1});
                    c = s[i];
                    s[i] = t[i];
                    t[i] = c;
                    i--;
                }
            }
        }
        cout << arr.size() << "\n";
        for(int i = 0; i < arr.size(); i++) cout << arr[i].ff << " " << arr[i].ss << "\n";
    }
    return 0;
}
