#include <bits/stdc++.h>

using namespace std;
int n,q,c,k,r,p,sc,a,b,o,aa,lsc,bb,cc,jj,arr[102];
string s,t;
char a1,a2,b1,b2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>q;
    for(int l=0;l<q;l++){
        cin>>n;
        cin>>s>>t;
        c=0;
        for(int i=0;i<n;i++){
            if(s[i]==t[i]) continue;
            c++;
            if(c>2) break;
            if(c==1) {a1=s[i]; b1=t[i]; continue;}
            if(c==2) {a2=s[i]; b2=t[i]; continue;}
        }
        if(c>2 || c==1){cout<<"No"<<'\n';continue;}
        if(a1==a2 && b2==b1){cout<<"Yes"<<'\n';continue;}
        else{cout<<"No"<<'\n';continue;}
    }
}
