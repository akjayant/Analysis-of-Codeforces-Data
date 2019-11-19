#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
ll x[2222], y[2222], c[2222], k[2222];
int par[2222], l[2222], cnt, sz[2222];
int pa(int x){
    if(par[x]==x)
        return x;
    return par[x]=pa(par[x]);
}
bool col(int x){
    int tmp=pa(x);
    if(l[tmp])
        return 0;
    cnt+=sz[tmp];
    l[tmp]=1;
    return 1;
}
bool join(int x, int y){
    int tmp1=pa(x), tmp2=pa(y);
    int sz1=sz[tmp1], sz2=sz[tmp2];
    int l1=l[tmp1], l2=l[tmp2];
    if(l1&&l2){
        return 0;
    }
    if(l1||l2){
        if(!l1){
            cnt+=sz1;
        }
        if(!l2){
            cnt+=sz2;
        }
    }
    par[tmp1]=tmp2;
    sz[tmp2]=sz1+sz2;
    l[tmp2]=(l1||l2);
    return 1;
}
int main(){
    int n;
    while(cin>>n){
        ll ans=0;
        cnt=0;
        for(int i=1; i<=n; ++i){
            scanf("%lld%lld",x+i,y+i);
            par[i]=i;
            l[i]=0;
            sz[i]=1;
        }
        vector <pair<ll, pair<int, int> > > v;
        vector <pair<int, int> > v1;
        vector <int> v2;
        for(int i=1; i<=n; ++i){
            scanf("%lld",c+i);
            v.push_back(mk(c[i], mk(i, i)));
        }
        for(int i=1; i<=n; ++i){
            scanf("%lld",k+i);
            for(int j=1; j<i; ++j){
                v.push_back(mk((k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])), mk(i, j)));
            }
        }
        sort(v.begin(), v.end());
        pair<ll, pair<int, int> > tmp;
        ll a, b;
        for(int i=0; i<v.size(); ++i){
            tmp=v[i];
            a=tmp.sc.fs;
            b=tmp.sc.sc;
//            cout<<tmp.fs<<" "<<a<<" "<<b<<endl;
            if(a==b){
                if(col(a)){
                    ans+=tmp.fs;
                    v2.push_back(a);
                }
                if(cnt==n){
                    break;
                }
                continue;
            }
            if(pa(a)==pa(b)){
                continue;
            }
            if(join(a, b)){
                ans+=tmp.fs;
                v1.push_back(mk(a, b));
            }
//            cout<<cnt<<" "<<ans<<endl;
            if(cnt==n){
                break;
            }
        }
        assert(cnt==n);
        cout<<ans<<endl;
        cout<<v2.size()<<endl;
        for(int i=0; i<v2.size(); ++i){
            cout<<v2[i]<<" ";
        }
        cout<<endl;
        cout<<v1.size()<<endl;
        for(int i=0; i<v1.size(); ++i){
            cout<<v1[i].fs<<" "<<v1[i].sc<<endl;
        }
    }
  return 0;
}


