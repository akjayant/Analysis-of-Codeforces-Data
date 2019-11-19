
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<pair<long long,long long> >v,va;
vector<long long>c,k;
vector<pair<long long,pair<long long,long long> > >vc;
long long x[20005],y[20005],z[20005],u[20005];
long long root(int p){
    if(x[p]==p)return p;
    else return x[p]=root(x[p]);
}
int main()
{
    fastio;
    long long a=0,b=0,d,e,f=0,l,g,m,n,i,j,t,p,q;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a>>b;
        v.push_back({a,b});
    }
    for(i=0;i<n;i++){
        cin>>a;
        c.push_back(a);
    }
    for(i=0;i<n;i++){
        cin>>a;
        k.push_back(a);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            d=v[i].first-v[j].first;
            e=v[i].second-v[j].second;
            d=abs(d)+abs(e);
            d*=(k[i]+k[j]);
            vc.push_back({d,{i,j}});
        }
    }
    sort(vc.begin(),vc.end());
    for(i=0;i<n;i++){
        x[i]=i;
        y[i]=c[i];
        z[i]=1;
        u[i]=i;
    }
    l=vc.size();
    f=0;e=0;
    for(i=0;i<l;i++){
        p=vc[i].second.first;
        q=vc[i].second.second;
        p=root(p);
        q=root(q);
        if(p==q)continue;
        else{
            d=max(y[p],y[q]);
            if(d>vc[i].first){
                    if(z[p]<z[q])swap(p,q);
                    z[p]+=z[q];
                    z[q]=0;
                    x[q]=p;
                    if(y[p]>y[q]){
                        u[p]=u[q];
                    }
                    y[p]=min(y[p],y[q]);
                    e++;
                    f+=vc[i].first;
                    p=vc[i].second.first;
                    q=vc[i].second.second;
                    va.push_back({p,q});
            }
        }
    }
    vector<long long>ans;
    for(i=0;i<n;i++){
        if(z[i]){
            f+=y[i];
            ans.push_back(u[i]);
        }
    }
    cout<<f<<'\n';
    l=ans.size();
    cout<<l<<'\n';
    for(i=0;i<l;i++){
        cout<<ans[i]+1<<' ';
    }
    cout<<'\n'<<e<<'\n';
    for(i=0;i<e;i++){
        cout<<va[i].first+1<<' '<<va[i].second+1<<'\n';
    }
    return 0;
}
