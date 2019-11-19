#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    int t,n,sol,l,r,nr;
    cin>>t;
    while(t--){
        cin>>n>>s;
        l=1e9, r=-1;
        nr=0;
        for(int i=0;i<n;++i){
            if(s[i] == '1'){
                l=min(l, i);
                r=max(r,i);
                ++nr;
            }
        }
        sol=n+nr;
        if(r!=-1){
            sol=max(sol, (r+1)*2);
            sol=max(sol, (n-l)*2);
        }
        cout<<sol<<'\n';
    }
    return 0;
}
