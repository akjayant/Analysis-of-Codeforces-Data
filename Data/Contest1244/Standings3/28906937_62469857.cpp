#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define dd double
#define oo 1001007000
#define ff float
#define ooo 1000000100000000000
#define iii pair<int,int>
#define vii vector<ll>
#define viii vector<iii>
#define sss pair<str,str>
#define str string
#define sii set<ll>
#define siii set<iii>
#define sz size
#define st size_t
#define r0 return 0
#define pb push_back
#define quickcin cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

const char E='\n';
const int N=70051;

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int o=1;o<=t;o++){
        int n;
        cin >> n;
        str s;
        cin >> s;
        int mn=30000,mx=-1;
        for (int i=0;i<n;i++){
            if (s[i]=='1'){
                mn=min(mn,i+1);
                mx=max(mx,i+1);
            }
        }
       
        int ans=n;
        if (mx==-1){
            ans=n;
            cout << ans << E;
            continue;
        }
        ans=max(ans,mn*2);
        ans=max(ans,mx*2);
        ans=max(ans,(n-mx+1)*2);
        ans=max(ans,(n-mn+1)*2);
        cout << ans << E;
    }
    r0;
}
