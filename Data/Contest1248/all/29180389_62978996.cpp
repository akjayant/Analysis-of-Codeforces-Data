#include<bits/stdc++.h>
#define ms(x) memset(x,0,sizeof(x))
#define sws ios::sync_with_stdio(false)
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
typedef long long ll;
const int maxn=1e6+2;
const ll mod=1e9+7;
const int up=4;
int main(){
    int n;
    sws;
    int t;
    cin>>t;
    while(t--){
         int odd=0,even=0;
        cin>>n;
       for(int i=1;i<=n;i++){
          int x;
          cin>>x;
          if(x%2==0) even++;
          else odd++;
        }
        int m;
        cin>>m;
        ll ans=0;
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            if(x%2==0) ans+=even;
            else ans+=odd;
        }
        cout<<ans<<endl;
    }

}


