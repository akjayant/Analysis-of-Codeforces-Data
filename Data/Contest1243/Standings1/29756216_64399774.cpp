#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(), (a).end()
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define sz() size()
#define fr first
#define sc second
#define pb push_back
#define er erase
#define in insert
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>
#define mp make_pair
#define int long long
#define rc(s) return cout<<s,0
#define rcc(s) cout<<s,exit(0)
///#define cin fin
///#define cout fout
using namespace std;

const int mod=1e9+7;

int q,n;
vector<pair<int,int>>ans;
string s,t;


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    cin >> q;
    while(q--){
        cin >> n >> s >> t;
        ans.clear();
        map<char,int>wtf;
        string rs="Yes";
        for(int i=0;i<s.size();i++) wtf[s[i]]++;
        for(int i=0;i<t.size();i++) wtf[t[i]]++;
        auto it=wtf.begin();
        while(it!=wtf.end()){
            if((it->second)%2==1) rs="No";
            it++;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                for(int j=0;j<s.size();j++){
                    if(i!=j){
                    if((s[j]==t[i] || t[j]==t[i]) && (s[j]!=t[j])){
                        if(t[j]==t[i]){
                            ans.push_back({i+1,j+1});
                            swap(s[i],t[j]);
                            break;
                        }
                        else{
                            ans.push_back({j+1,j+1});
                            swap(s[j],t[j]);
                            ans.push_back({i+1,j+1});
                            swap(s[i],t[j]);
                            break;
                        }
                    }
                    }
                }
            }
        }
        cout << rs << '\n';
        if(rs=="Yes"){
            cout << ans.size() << '\n';
            for(int i=0;i<ans.size();i++){
                cout << ans[i].fr << ' ' << ans[i].sc << '\n';
            }
        }

    }
}
