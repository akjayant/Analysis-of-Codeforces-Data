
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<pair<long long,long long> >v;
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    cin>>t;
    while(t--)
    {
        string s,ss,sa,sb;
        cin>>n>>s>>ss;
        sa="";
        sb="";
        v.clear();
        f=1;
        for(i=0; i<n; i++)
        {
            if(s[i]!=ss[i])
            {
                for(j=i+1;j<n;j++){
                    if(s[j]==s[i]){
                        swap(s[j],ss[i]);
                        v.push_back({j,i});
                        break;
                    }
                }
                if(j==n){
                    for(j=i+1;j<n;j++){
                        if(s[i]==ss[j]){
                            v.push_back({i+1,j});
                            swap(s[i+1],ss[j]);
                            v.push_back({i+1,i});
                            swap(s[i+1],ss[i]);
                            break;
                        }
                    }
                    if(j==n)f=0;
                }
            }
        }
        if(!f){
            cout<<"No\n";
        }
        else {
            cout<<"Yes\n";
            cout<<v.size()<<'\n';
            for(i=0;i<v.size();i++){
                cout<<1+v[i].first<<' '<<1+v[i].second<<'\n';
            }
        }


    }
    return 0;
}
