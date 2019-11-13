#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define int long long
#define M 1000000007
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
// Use pr(a,b,c,d,e) or cerr<<anything or prc(v.begin(),v.end()) or prc(v,v+n)
 
const int N = 100007;
 
 
 
int32_t main()
{
    int n;
    cin >> n;
    vector<int> a[n];
    int count = 0;
    int f= 0;
    while(count < n*n)
    {
        if(f == 0)
        {
            for(int i=0;i<n;i++)
            {
                a[i].pb(count);
                count++;
            }
            f = 1;
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                a[i].pb(count);
                count++;
            }
            f = 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j:a[i])
            cout << j+1 << " ";
        cout << "\n";
    }

    return 0;
}
