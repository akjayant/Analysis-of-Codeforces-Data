#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second

using namespace std;


#define sim template < class c

#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ,cout.tie(0);

    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        int a,b,c; cin >> a >> b >> c;
        string s;  cin >> s;
        string ans;
        int sum = n;
        for(int i = 0;i < n;i++)
        {
            if(s[i] == 'R' && b > 0)ans.push_back('P'),b--;
            else if(s[i] == 'P' && c > 0)ans.push_back('S'),c--;
            else if(s[i] == 'S' && a > 0)ans.push_back('R'),a--;
            else {
                sum--;
                ans.push_back('#');
            }
        }
        if(sum >= (n + 1 >> 1)){
            cout << "YES\n";
            for(int i = 0;i < n;i++)
            {
                if(ans[i] != '#')cout << ans[i];
                else{
                    if(a > 0){
                        cout << "R";
                        a--;
                    }
                    else if(b > 0)
                    {
                        cout << "P";
                        b--;
                    }
                    else {
                        cout << "S";
                        c--;
                    }
                }
            }
            cout << "\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
