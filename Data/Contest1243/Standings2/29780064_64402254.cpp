#include<bits/stdc++.h>
#include<string.h>
#define ll long long
#define pb push_back
#define fast_io cin.tie(0);cout.tie(0);ios::sync_with_stdio(0)
#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define deb4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define deb5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define deb6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define inf 100000000000000000
#define ff first
#define ss second

#define MAX_CHAR 256

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

//#define ordered_set tree< pair<ll,ll>, null_type,less< pair<ll,ll> >, rb_tree_tag,tree_order_statistics_node_udate>

//ll mod=1000000000+7;
//ll fact[550];
//ll invs[550];
//vector < pair<ll,ll> >interval;
//ll m1[100001],m2[100001];
//vector < pair<ll,ll> > val[100001];
//ll val[100001];
//ll cnt[100001];
//ll sub[100001];
//vector < pair<ll,ll> > deph[200001],depl[200001];
//map <ll,ll> index;
//map <ll,ll> mp;
//ll h[200001],l[200001];
//ll depth[100001];
//vector <ll> child[100001];
//vector <ll> undir[101];
// vector <ll> adj[200001];
// ll vis[200001];
// ll col[200001];
// ll cnt;
//ll vis2[100001];
//map <pair<ll,ll>,ll> wt,groot;
//ll flag;
//map <ll,ll> g;
//ll n,m;
//ll cnt[101];
//ll dist;
//ll tot=0;
//vector <ll> a;
//ll cnt;
//ll nodes;
//vector <ll> comp[200001];
//vector <ll> grp[100001];
//ll p[100001];
//ll s[100001];
//ll dis[300001];
//map < pair<ll,ll>,ll > mp;
//vector <ll> ans;
//map < pair<ll,ll>,ll > e;
//ll ans[200001];
//vector <ll> arr;
//map <ll,ll> m;
//ll k;
//ll par[100001];
//ll d[100001];
//ll days[100001];
//map < pair<ll,ll>,ll > m;
//ll tree[4*1000001];
//ll arr[1000000];
//string s[100000],revs[100000];
//ll dp[100000][2];
//ll c[100000];
//ll h[100001];
// ll p[100001],c[100001];

// void bfs(ll x) {
//     queue <ll> q;
//     q.push(x);
//     vis[x]=1;
//     ans[x]=1;
//     ll k,flag;
//     vector <ll>::iterator it;
//     while(!q.empty()){
//         k = q.front();
//         q.pop();
//         if(!par[k]){
//             ans[k]=1;
//         }
//         else{
//             ans[k]=ans[par[k]]+val[par[k]]+2*(e[make_pair(k,par[k])]-val[par[k]]);
//         }
//         //cout << k << endl;
//         flag=0;
//         for (it=adj[k].begin();it!=adj[k].end();it++) {
//             if(vis[*it]==0) {
//                 flag=1;
//                 q.push(*it);
//                 vis[*it]=1;
//                 val[k]=min(val[k],e[make_pair(k,*it)]);
//             }
//         }
//         if(flag==0){
//             leaf.pb(ans[k]);
//         }
//     }
// }

//ll a,b;

//vector <ll> sum;

// ll dfs(ll ver, ll c, ll q, ll limit){
//     // cout << ver << " => ";
//     // deb3(col[ver],c,cnt);
//     if(cnt==limit) return 0;
//     vis[ver]=q;
//     if(col[ver]==c){
//         cnt++;
//         // deb1(cnt);
//     }
//     else if(col[ver]!=0){
//         vis[ver]=0;
//         return -1;
//     }
//     ll cur,ret;
//     ll flag=0;
//     for(ll x=0;x!=adj[ver].size();x++){
//         cur=adj[ver][x];
//         // deb2(cur,vis[cur]);
//         if(vis[cur]!=q){
//             ret = dfs(cur,c,q,limit);
//             if(ret==0){
//                 flag=1;
//             }
//         }
//     }
//     if(flag==0){
//         if(col[ver]==0){
//             vis[ver]=0;
//             return -1;
//         }
//         else return 0;
//     }
//     else return 0;
// }

/*ll dfs2(ll ver,ll d){
    vis[ver]=1;
    val[ver]=d;
    ll cur;
    ll ret=0;
    ll flag=0;
    for(ll x=0;x!=adj[ver].size();x++){
        cur=adj[ver][x];
        if(!vis[cur]){
            flag=1;
            ret+=dfs2(cur,d+1);
        }
        cnt[ver]=ret;
    }
    if(flag==0){
        return 1;
    }
    else{
        return ret;
    }
}*/

/*ll dfs(ll ver,ll par,ll grtsum,ll sum,ll revsum){
    //deb2(sum,grtsum);
    vis[ver]=1;
    ll cur,temp;
    ll ret;
    ll my;
    ll my_ans=0;
    pair <ll,ll> edg;
    for(ll x=0;x!=adj[ver].size();x++){
        cur = adj[ver][x];
        if(!vis[cur]){
            edg.first=ver;
            edg.second=cur;
            temp=groot[edg];
            if(temp==1){
                grtsum+=wt[edg];
            }
            else{
                flag=0;
                grtsum=0;
            }
            //deb1(wt[edg]);
            sum+=wt[edg];
            revsum+=wt[edg];
            my=sum+grtsum;
            //deb1(my);
            my_ans=max(my_ans,my);
            if(revsum-grtsum<grtsum){
                revsum=2*grtsum;
            }
            ret=dfs(cur,ver,grtsum,sum,revsum);
            my_ans=max(my_ans,ret);
        }
    }
    return my_ans;
}*/

/*ll dfs2(ll ver,ll par){
    vis2[ver]=1;
    ll cur;
    pair <ll,ll> edg;
    edg.first=ver;
    edg.second=par;
    ll flag=0;
    ll my_ans=0;
    for(ll x=0;x!=adj[ver].size();x++){
        cur = adj[ver][x];
        if(!vis2[cur]){
            flag=1;
            my_ans=max(my_ans,dfs2(cur,ver));
        }
    }
    return my_ans+wt[edg];
}*/

//ll m=1000000007;

/*ll invmod(ll a,ll n,ll mod){
    ll result = 1;
    while(n>0){
        if(n%2==1){
            result = (result*a)%mod;
        }
        a = (a*a)%mod;
        n = n/2;
    }
    return result;
}

ll fact(ll a,ll mod){
    if(a==0)return 1;
    return (a*fact(a-1,mod))%mod;
}

ll choose(ll n,ll r,ll mod){
    if(n<r)return 0;
    ll num=fact(n,mod);
    ll den=(fact(r,mod)*fact(n-r,mod))%mod;
    return (num*invmod(den,mod-2,mod))%mod;
}*/

/*void build(ll node,ll start,ll end,ll cnt){
    if(start==end){
        tree[node]++;
        return;
    }
    ll mid=(start+end)/2;
    if(cnt<=mid)build(2*node+1,start,mid,cnt);
    else build(2*node+2,mid+1,end,cnt);
    tree[node] = tree[2*node+1] + tree[2*node+2];
}*/

/*ll query(ll node,ll start,ll end,ll lef,ll riht){
    if(end<lef || start>riht){
        return 0;
    }
    else if(start>=lef && end<=riht){
        return tree[node];
    }
    else{
        ll mid=(start+end)/2;
        //cout << mid << "\n";
        //cout << (query(2*node+1,start,mid,lef,riht)) << "\n";
        //cout << (query(2*node+2,mid+1,end,lef,riht)) << "\n";
        return query(2*node+1,start,mid,lef,riht) + query(2*node+2,mid+1,end,lef,riht);
    }
}*/

//ll step[4000001];
//map < pair<ll,ll> ,ll> mp;
//ll w[300001];

//multiset <ll> s[300001];

//ll mod=998244353;

/*ll fact(ll a){
    if(a==0){
        return 1;
    }
    return (a*fact(a-1))%mod;
}*/

//ll mod=1000000000+7;

// ll mod = 998244353;
//
// ll power(ll a,ll y){
//     if(y==0)return 1;
//     ll p = power(a, y/2) % mod;
//     p = (p * p) % mod;
//     return (y%2==0)? p : (a * p) % mod;
// }

/*ll invmod(ll a){
    return power(a, mod-2);
}*/

//vector <ll> v[100000];
//vector <ll> pref[100000];

//ll isNode[1000001];

/*ll helper(ll B,ll cnt){
    ll temp=1;
    for(ll x=2;x<=cnt;x++){
        temp*=(B+cnt-x);
    }
    for(ll x=2;x<=cnt-1;x++){
        temp/=x;
    }
    return temp;
}*/

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */

/*ll parent[20][100001];
ll level[100001];

void par_dfs(ll k, ll par, ll lvl)
{
    parent[0][k]=par;
    level[k]=lvl;
    for(ll i=0;i<adj[k].size();i++)
    {
        ll it=adj[k][i];
        if(it==par)
            continue;
        par_dfs(it, k, lvl+1);
    }
}

void precompute()
{
    for(ll i=1;i<20;i++)
        for(ll j=1;j<=100000;j++)
            if(parent[i-1][j])
                parent[i][j]=parent[i-1][parent[i-1][j]];
}*/

/*ll LCA(ll u, ll v)
{
    if(level[u]<level[v])
        swap(u,v);
    ll diff=level[u]-level[v];
    for(ll i=20-1;i>=0;i--)
    {
        if((1<<i) & diff)
        {
            u=parent[i][u];
        }
    }
    if(u==v)
        return u;
    for(ll i=20-1;i>=0;i--)
    {
        if(parent[i][u] && parent[i][u]!=parent[i][v])
        {
            u=parent[i][u];
            v=parent[i][v];
        }
    }
    return parent[0][u];
}*/

/*void recur(ll cur,ll d,ll n){
    //if(a.size()>1000000)cout << "Culprit\n";
    a.pb(cur);
    vis[cur]=1;
    if(d>dist){
        a.pop_back();
        vis[cur]=0;
        return;
    }
    if(cur==n){
        tot++;
        for(ll x=0;x!=a.size();x++){
            cnt[a[x]]++;
        }
        vis[cur]=0;
        a.pop_back();
        return;
    }
    ll i;
    for(i=0;i!=adj[cur].size();i++){
        if(!vis[adj[cur][i]])recur(adj[cur][i],d+1,n);
    }
    a.pop_back();
    vis[cur]=0;
}*/

// ll ans;
// ll pre[100001];
// ll a[100001];
// pair <ll,ll> dg[100001];
//
// void binary_search(ll time,ll l,ll r){
//     if(l>r)return;
//     ll mid=(l+r)/2;
//     //if(i==0)deb2(mid,tot);
//     if(leaf[mid]<=time){
//         out=mid;
//         binary_search(time,mid+1,r);
//     }
//     else{
//         binary_search(time,l,mid-1);
//     }
// }

// ll a[1000000];
// ll vis[1000001];

// ll my_ceil_div(ll p,ll q){
//     if(p%q==0){
//         return (p/q);
//     }
//     else{
//         return ((p/q)+1);
//     }
// }

// bool compare(pair<ll,ll> &a, pair<ll,ll> &b){
//     return (a.second < b.second);
// }

// bool str_compare(string s1,string s2){
//     ll i=0,j=0;
//     while(s1[i]!='\0' && s2[j]!='\0'){
//         if(s1[i]<s2[j]){
//             return true;
//         }
//         else if(s1[i]>s2[j]){
//             return false;
//         }
//         i++;
//         j++;
//     }
//     if(s1[i]=='\0'){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// ll vis[50001][50001];
// ll lef[50001][50001];
// ll righ[50001][50001];
// ll u[50001][50001];
// ll d[50001][50001];

// ll prime[1000001];

int main(){
    fast_io;

    ll n,i;
    cin >> n;
    ll ans=n;
    for(i=2;i<=sqrt(n);i++){
    	if(n%i==0){
    		if(i*i==n){
    			ans=__gcd(ans,i);
    		}
    		else{
    			ans=__gcd(ans,i);
    			ans=__gcd(ans,n/i);
    		}
    	}
    }
    cout << ans;
}
