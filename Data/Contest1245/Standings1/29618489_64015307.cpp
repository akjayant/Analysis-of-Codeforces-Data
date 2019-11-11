#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int >
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define LL long long
using namespace std;
const int INF=0x3f3f3f3f,N=2e6+5,MOD=1e9+7;

void Add(int &x,int y){
    x=(0ll+x+y)%MOD;
}
int Solve(){
    string str;
    cin>>str;
    int n=str.size();
    for(int i=0;i<n;i++)if(str[i]=='w'||str[i]=='m'){
        cout<<"0"<<endl;
        return 0;
    }
    vi f(n,0);
    f[0]=1;
    for(int i=1;i<n;i++){
        f[i]=f[i-1];
        if(str[i]=='u'){
            if(i>0&&str[i-1]=='u'){
                if(i==1)Add(f[i],1);
                else Add(f[i],f[i-2]);
            }
        }
        else if(str[i]=='n'){
            if(i>0&&str[i-1]=='n'){
                if(i==1)Add(f[i],1);
                else Add(f[i],f[i-2]);
            }
        }
    }
    cout<<f[n-1]<<endl;
    return 0;
}
void Pre(){
}
int main() {
#ifndef ONLINE_JUDGE
//  freopen("in.txt","r",stdin);
//  freopen("o1.txt","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    Pre();
    while(Solve());
    return 0;
}

