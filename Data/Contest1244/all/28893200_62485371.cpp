#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
vector <ll> a[100010];
ll mem[100010][4][4], b[100010][3], v[100010];
ll dp(ll x, ll pa, ll l1, ll l2){
    if(mem[x][l1][l2]!=-1)
        return mem[x][l1][l2];
    ll res=0;
    set<ll> st;
    st.insert(1);
    st.insert(2);
    st.insert(0);
    if(st.find(l1)!=st.end())
        st.erase(l1);
    if(st.find(l2)!=st.end())
        st.erase(l2);
    res=1e15;
    if(a[x].size()==1 && pa!=-1){
        for(auto tmp:st){
            res=min(res, b[x][tmp]);
        }
        mem[x][l1][l2]=res;
        return res;
    }
    for(auto tmp:st){
        if(a[x][0]==pa){
            res=min(res, b[x][tmp]+dp(a[x][1], x, l2, tmp));
        }
        else{
            res=min(res, b[x][tmp]+dp(a[x][0], x, l2, tmp));
        }
    }
    mem[x][l1][l2]=res;
    return res;
}
void get_ans(ll x, ll pa, ll l1, ll l2){
    ll res=0;
    set<ll> st;
    st.insert(1);
    st.insert(2);
    st.insert(0);
    if(st.find(l1)!=st.end())
        st.erase(l1);
    if(st.find(l2)!=st.end())
        st.erase(l2);
    res=1e15;
    ll tmp1;
    if(a[x].size()==1 && pa!=-1){
        for(auto tmp:st){
            if(b[x][tmp]<res){
                res=min(res, b[x][tmp]);
                tmp1=tmp;
            }
        }
        v[x]=tmp1;
        return;
    }
    ll tmp2;
    for(auto tmp:st){
        if(a[x][0]==pa){
            tmp2=b[x][tmp]+dp(a[x][1], x, l2, tmp);
            if(tmp2<res){
                res=tmp2;
                tmp1=tmp;
            }
        }
        else{
            tmp2=b[x][tmp]+dp(a[x][0], x, l2, tmp);
            if(tmp2<res){
                res=tmp2;
                tmp1=tmp;
            }
        }
    }
    v[x]=tmp1;
    if(a[x][0]==pa){
        get_ans(a[x][1], x, l2, tmp1);
    }
    else{
        get_ans(a[x][0], x, l2, tmp1);
    }
}
int main(){
    ll n;
    while(cin>>n){
        ll ans=0;
        for(ll j=0; j<3; ++j){
            for(ll i=1; i<=n; ++i){
                scanf("%lld",&b[i][j]);
            }
        }
        bool l=1;
        ll x, y;
        for(ll i=0; i<n-1; ++i){
            scanf("%lld%lld",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
            if(a[x].size()>2 || a[y].size()>2){
                l=0;
            }
        }
        if(l){
            ans=-1;
            memset(mem, -1, sizeof mem);
            for(ll i=1; i<=n; ++i){
                if(a[i].size()==1){
                    ans=dp(i, -1, 3, 3);
                    get_ans(i, -1, 3, 3);
                    break;
                }
            }
            cout<<ans<<endl;
            ll tmp=0;
            for(ll i=1; i<=n; ++i){
                printf("%lld ",v[i]+1);
                tmp+=b[i][v[i]];
            }
            assert(tmp==ans);
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
  return 0;
}


