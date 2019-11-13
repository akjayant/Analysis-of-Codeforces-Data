#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1e5+5;
const int mod=1e9+7;
char s[N];
int f[N];

void init();
void work();
int ca=1;
int main(){
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
//    init();
//    int T;cin>>T;
//    while(T--)
    work();
    return 0;
}
void work(){
    cin>>s+1;
    int n=strlen(s+1);
    f[1]=1,f[2]=2;
    for(int i=3;i<=n;i++) f[i]=(f[i-1]+f[i-2])%mod;
    int ans=1;
    for(int i=1;i<=n;){
        if(s[i]=='m'||s[i]=='w') ans=0;
        if(s[i]=='u'||s[i]=='n'){
            int j=i+1;
            while(j<=n&&s[j]==s[i]) j++;
            ans=1LL*ans*f[j-i]%mod;
            i=j;
        }else i++;
    }
    cout<<ans;
}
