#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        string ans="";
        int win=0;
        int cnt[n]={};
        int r=1,p=2,ss=3;
        for(int i=0;i<n;i++){
            if(s[i]=='R' && b) b--,cnt[i]=p,win++;
            if(s[i]=='P' && c) c--,cnt[i]=ss,win++;
            if(s[i]=='S' && a) a--,cnt[i]=r,win++;
        }
        if(win>=(n+1)/2){
            cout << "YES\n";
            for(int i=0;i<n;i++){
                if(cnt[i]==p) ans+='P';
                else if(cnt[i]==r) ans+='R';
                else if(cnt[i]==ss) ans+='S';
                else{
                    if(a) ans += 'R',a--;
                    else if(b) ans += 'P',b--;
                    else if(c) ans += 'S',c--;
                }
            }
            cout << ans << "\n";
        }
        else cout << "NO\n";

    }
}