#include<bits/stdc++.h>
using namespace std;
#define int long long int
// #define lli long long int
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define endl '\n'
#define all(x) x.begin(),x.end()
#define f(i,j,l) for(i=j;i<l;i++)
 
int const mod = 1e9+7;
int power(int a,int b){
    int res = 1;
    while(b){
        if(b&1){
            res = res*a;
            // res %= mod;
        }
        a=a*a;
        // a%=mod;
        b=b/2;
    }
    return res;
}
 
// int inverse_mod(int x){
//     return power(x,mod-2);
// }
 
int const N = 2e5+5;

void solve(){
    int n;
    cin>>n;
    string s,t; cin>>s>>t;
    int i,j,l;
    j = 0;
    l = -1;
    int cnt[26]={0};
    for(i=0;i<n;i++) cnt[s[i]-'a']++;
    for(i=0;i<n;i++) cnt[t[i]-'a']++;
    for(i=0;i<26;i++){
        if(cnt[i]%2) {cout<<"No"<<endl;return;}
    }
    int a[n],b[n];
    for(i=0;i<n;i++){
        a[i] = s[i] - 'a';
        b[i] = t[i] - 'a';
    }

    cout<<"Yes"<<endl;
    vector<pii> ans;
    for(i=0;i<n;i++){
        if(a[i] != b[i]){
            for(j=i+1;j<n;j++){
                if(a[j] == a[i]){
                    swap(a[j] , b[i]);
                    ans.pb({j,i});
                    break;
                }
            }

            if(j == n){
                for(j = i+1;j<n;j++){
                    if(b[j] == a[i]){
                        swap(b[j] , a[j]);
                        ans.pb({j,j});
                        swap(a[j],b[i]);
                        ans.pb({j,i});
                        break;
                    }
                }
            }
        }
    }

    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++) cout<<ans[i].ff+1<<" "<<ans[i].ss+1<<endl;
}


int32_t main(){
    IOS;
    int t;
    t = 1;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        solve();
    }
    return 0;
}