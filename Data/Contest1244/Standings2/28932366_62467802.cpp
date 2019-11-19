#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ifstream fin("AAtest.in.txt");
ll t,n,mit;
string s;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        mit=n;
        for(int i=0; i<n; i++) if(s[i]=='1'){
            mit=i;
            break;
        }
        for(int i=n-1; i>=0; i--) if(s[i]=='1'){
            if(n-i-1<mit) mit=n-i-1;
            break;
        }
        if(mit==n) cout<<n<<"\n";
        else cout<<2*n-2*mit<<"\n";
    }
}
