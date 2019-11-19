#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

void solve(){
    LL n;
    cin>>n;
    LL tmp=n, p=1;
    int cnt=0;
    for(LL i=2;i*i<=n&&cnt<2;i++){
        if(n%i==0){
            while(n%i==0)n/=i;
            p=i;
            cnt++;
        }
    }
    if(n!=1)
        p=n,cnt++;
    if(cnt>=2)
        cout<<1<<endl;
    else if(cnt==1)
        cout<<p<<endl;
    else
        cout<<tmp<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
