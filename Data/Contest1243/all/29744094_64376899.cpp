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
        if(v.size()>2||v.size()==1){cout<<"No"<<endl;continue;}
        if(v.size()==0){sort(a.begin(),a.end());

            bool ok=0;for(int i=0;i<n-1;i++)if(a[i]==a[i+1])ok=1;
            if(ok)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
            continue;
        }
        if(a[v[0]]==a[v[1]]&&b[v[0]]==b[v[1]]){cout<<"Yes"<<endl;}
        else
            cout<<"No"<<endl;

    }
    return 0;
    }

