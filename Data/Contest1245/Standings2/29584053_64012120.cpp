#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod= 1e9+7;
long double PI = acosl(-1);
const ll infl = 1e15;
const int inf = 2e9;
const int nmax = 1e5+10;
const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;


ll f[nmax];
ll fsum[nmax];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int tc;
    tc = 1;
    while(tc--){

        f[0] = 1, f[1] = 1;
        fsum[1] = 2, fsum[0] = 1;

        for(int i=2; i<nmax; i++){
            f[i] = 1LL + fsum[i-2];
            fsum[i] = (f[i] + fsum[i-1]) %mod;
            f[i]%=mod, fsum[i]%=mod;
        }

        string s;
        cin>>s;
        bool wmase = false;
        for(char ch : s){
            if(ch=='m' or ch=='w') wmase = true;
        }
        if(wmase) cout<<"0", exit(0);

        vector<pair<int, char> >v;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='u'){
                if(v.size()){
                    if(v.back().second=='u') v.back().first++;
                    else v.push_back({1,'u'});
                }
                else{
                    v.push_back({1,'u'});
                }
            }
            else if(s[i]=='n'){
                if(v.size()){
                    if(v.back().second=='n') v.back().first++;
                    else v.push_back({1,'n'});
                }
                else{
                    v.push_back({1,'n'});
                }
            }
            else{
                v.push_back({0, 'a'});
            }
        }
        vector<int>tmp;
        for(auto z : v){
            if(z.first)
                tmp.push_back(z.first);
        }

        ll ans = 1;
        for(int z : tmp)
            ans = (ans * f[z]) % mod;

        cout<<ans<<"\n";
    }
}
