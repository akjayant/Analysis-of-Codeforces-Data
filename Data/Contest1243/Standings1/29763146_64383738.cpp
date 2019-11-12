#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e3+5;
const ll MOD=1e9+7;
const ll INF=1e18;
ll t,n,cnt;
string str1,str2;
char c[MAXN];
void solve(){
    cnt=0;
    if(str1==str2){
        printf("YES\n");
    }
    else{
        for(ll i=0;i<n;i++){
            if(str1[i]!=str2[i]){
                c[++cnt]=str1[i];
                c[++cnt]=str2[i];
                if(cnt>4){
                    printf("NO\n");
                    return;
                }
            }
        }
        if(cnt==2){
            printf("NO\n");
        }
        else{
            if(c[1]==c[3]&&c[2]==c[4]){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        cin>>str1;
        cin>>str2;
        solve();
    }
}