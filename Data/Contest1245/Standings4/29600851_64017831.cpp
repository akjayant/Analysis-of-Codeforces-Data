#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int MAXN = 1e5+50;
const int INF = 0X3f3f3f3f;
const int MOD = 1e9+7;
char s[MAXN];
LL a[MAXN];
int main(){
    cin>>s;
    int len = strlen(s);
    LL res = 1;
    a[1] = a[0] = 1;
    for(int i=2;i<=len;i++) a[i] = (a[i-1]+a[i-2])%MOD;
    for(int i=0;i<len;i++){
        if(s[i]=='m' || s[i]=='w') { cout<<0<<endl;return 0; }
        if(s[i]=='u'){
            int cnt = 0,k = i;
            while(s[k]=='u')
                cnt++,k++;
            if(cnt>=2)
                res = (a[cnt]*res%MOD)%MOD;
            i = k-1;
        }
        else if(s[i]=='n'){
            int cnt = 0,k = i;
            while(s[k]=='n')
                cnt++,k++;
            if(cnt>=2)
                res = (a[cnt]*res%MOD)%MOD;
            i = k-1;
        }
    }
    cout<<res<<endl;
    return 0;
}
