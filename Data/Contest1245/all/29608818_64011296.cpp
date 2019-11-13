#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define ll long long
#define int long long
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define mod 1000000007
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

signed main(){
    ios_base::sync_with_stdio(false); //fast io
    cin.tie(NULL);
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        int a,b,c; cin>>a>>b>>c;
        string alice; cin>>alice;
        map<char, int> m;
        for (auto f: alice){
            m[f]++;
        }
        
        m['R'] = min(m['R'], b);
        m['P'] = min(m['P'], c);
        m['S'] = min(m['S'], a);

        int ans = m['R']+m['P']+m['S'];

        a-=m['S'];
        b-=m['R'];
        c-=m['P'];

        n = ceil((float)n/2);

        if(ans>=n){
            cout<<"YES\n";
            for (auto f: alice)
            {
                if(m[f]!=0){
                    if(f=='R')cout<<'P';
                    if(f=='P')cout<<'S';
                    if(f=='S')cout<<'R';
                    m[f]--;
                }else{
                    if(a!=0) {cout<<'R'; a--;}
                    else if(b!=0) {cout<<'P'; b--;}
                    else if(c!=0) {cout<<'S'; c--;}
                }
            }
            cout<<endl;
        }
        else cout<<"NO\n";
    }
    return 0;
}
