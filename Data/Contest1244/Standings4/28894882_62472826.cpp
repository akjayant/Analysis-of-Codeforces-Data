#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
//    freopen("1244B.inp","r",stdin);
//    freopen("1244B.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        s=" "+s;
        int LM=0, RM=0;
        for (int i=1; i<=n; i++){
            if (s[i]=='1'){
                LM=max(LM,n-i+1);
                RM=max(RM,i);
            }
        }
        int k=max(LM,RM);
        if (k!=0) cout<<k*2<<'\n';
        else cout<<n<<'\n';
    }
}
