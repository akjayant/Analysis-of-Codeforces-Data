#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        string a,b;
        cin>>n>>a>>b;

        vector<int> v;
        for(int i=0;i<n;i++)if(a[i]!=b[i])v.pb(i);
        if(v.size()==0){

                cout<<"Yes"<<endl<<2<<endl;
                cout<<1<<' '<<1<<endl<<1<<' '<<1;
            continue;
        }
        bool ok=1;
        vector<pair<int,int > > c;
        for(int i=0;i<n;i++)
        {
            if(a[i]==b[i])continue;
            for(int j=i+1;j<n;j++){

                if(b[j]==b[i]){swap(a[i],b[j]);c.pb(mp(i+1,j+1));break;}
            }
            if(a[i]==b[i])continue;
            for(int j=i+1;j<n;j++){

                if(a[j]==a[i]){swap(a[j],b[i]);c.pb(mp(j+1,i+1));break;}
            }
            if(a[i]!=b[i]){
                swap(a[i],b[i]);c.pb(mp(i+1,i+1));
                for(int j=i+1;j<n;j++){

                if(b[j]==b[i]){swap(a[i],b[j]);c.pb(mp(i+1,j+1));break;}
                if(a[i]==b[i])continue;
            for(int j=i+1;j<n;j++){

                if(a[j]==a[i]){swap(a[j],b[i]);c.pb(mp(j+1,i+1));break;}
            }
            }
            }
            if(a[i]!=b[i])ok=0;
        }
        if(ok){
            cout<<"Yes\n"<<c.size()<<endl;
            for(int i=0;i<c.size();i++)
                cout<<c[i].ff<<' '<<c[i].ss<<endl;
        }
        else
            cout<<"No"<<endl;


    }
    return 0;
    }
