#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long



int main()
{
        ios_base::sync_with_stdio(false);
            cin.tie(NULL);

            ll t,n,m,par[2],nep[2],tmp;
            cin>>t;
            while(t--){
                    par[0]=par[1]=nep[0]=nep[1]=0;
                cin>>n;
                for(int i=0;i<n;i++){
                    cin>>tmp;
                    if( tmp%2==0 ) par[0]++;
                    else nep[0]++;
                }
                cin>>m;
                for(int i=0;i<m;i++){
                    cin>>tmp;
                    if(tmp%2==0)par[1]++;
                    else nep[1]++;
                }
                ll res=par[0]*par[1]+nep[0]*nep[1];
               // cout<<endl;
                cout<<res<<endl;
               // cout<<endl;
            }

            return 0;
}








