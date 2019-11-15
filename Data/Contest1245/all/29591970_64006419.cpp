#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;

int main(){
    ll t,a,b,c,i,n,j,k;
    char s;
    vector <char> ans(100);
    cin>>t;
    for (i=0; i<t; i++){
        for (j=0; j<100; j++)
            ans[j]='#';
        cin>>n>>a>>b>>c;
        k=0;
        for (j=0; j<n; j++){
            cin>>s;
            if (s=='R' && b>0){
                b--; k++;
                ans[j]='P';
            };
            if (s=='P' && c>0){
                c--; k++;
                ans[j]='S';
            };
            if (s=='S' && a>0){
                a--; k++;
                ans[j]='R';
            };
        };
        if (2*k>=n){
            cout<<"Yes"<<endl;
            for (j=0; j<n; j++){
                if (ans[j]!='#')
                    cout<<ans[j];
                else{
                    if (a>0) {cout<<'R'; a--;}
                    else if (b>0) {cout<<'P'; b--;}
                        else {cout<<'S'; c--;};
                }
            }
            cout<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
};
