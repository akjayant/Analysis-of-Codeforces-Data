#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define mod -1000000000000007
#define pb push_back
#define mp make_pair
#define PI 3.1415926535
#define pf push_front
#define ll long long int
#define ull unsigned long long int 
typedef pair<int,int>  pii;  
uint64_t seed = reinterpret_cast<uint64_t>(new char);
mt19937_64 rd(seed);
//uniform_int_distribution<int> rg(1, n);
//int RandomNumber = rg(rd);
// vector < int > v(N,-1);   sqrtl for square root of ll
// vector of size N with initial value -1 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;
#define gc getchar_unlocked
 
const int N=100005;
int ans=0;
vector <int> v[N];
void dfs(vector <int> u)
{
    ans++;
    //unordered_map <int,int> ma;
    unordered_map <int,int> ba;
    int len,i,j,k,l;
    len=u.size();
    set <int> x;
    for(i=1;i<len;i++) {   
        ba[u[i]]=1;
        x.insert(u[i]);
    }
    queue <int> q;
    q.push(u[0]);
    while(!q.empty())
    {
        i=q.front();  q.pop();
        set <int> tt;
        for(auto pk : v[i])
        {
            if(ba[pk]==1){
                tt.insert(pk);   x.erase(pk);
            }
        }
        for(auto pk : x){
            ba[pk]=0;
            q.push(pk);
        }
        x=tt;
        if(x.size()==0)  return;
    }
    vector <int> xd;
    for(auto pk : x)  xd.pb(pk);
    dfs(xd);
    
}
int main ()     
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,l,m,n,p;
    cin>>n>>m;
    while(m--)
    {
        cin>>i>>j;
        v[i].pb(j);  v[j].pb(i);
    }
    vector <int> u;
    for(i=1;i<=n;i++)  u.pb(i);
    dfs(u);
    cout<<(ans-1)<<endl;
    return 0;
}