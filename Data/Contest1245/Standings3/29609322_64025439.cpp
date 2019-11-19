#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define PB push_back
#define LL long long
#define pii pair<int,int>
#define MEM(x,y) memset(x,y,sizeof(x))
#define bug(x) cout<<"debug "#x" is "<<x<<endl;
#define FIO ios::sync_with_stdio(false);
#define ALL(x) x.begin(),x.end()
#define LOG 20
const int inf =1e9;
const int maxn =3e5+7;
const int mod = 1e9+7;
vector<pair<LL,pair<int,int>>> E;
int get_father(int x,vector<int> &fa){
    if(fa[x] == x) return x;
    return fa[x] = get_father(fa[x],fa);
}
void combin(int x,int y,vector<int> &fa){
    int fx = get_father(x,fa), fy = get_father(y,fa);
    if(fy != fx)
        fa[fx] = fy;
    return;
}
LL _x[maxn],_y[maxn],_k[maxn],_c[maxn];
void addedge(int u,int v,LL co){
    E.PB({co,{u,v}});
}
int main(){
    FIO;
    int n,m,k,x,y,z;
    int S=0;
    cin >> n;
    LL ans=0;
    vector<int> father(n+5,0);
    for(int i = 0;i <= n+3;i++) father[i] = i;
    for(int i=0;i<n;i++)cin>>_x[i]>>_y[i];
    for(int i=0;i<n;i++)cin>>_c[i],addedge(S,i+1,_c[i]);
    for(int i=0;i<n;i++)cin>>_k[i];
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
        LL co=(_k[i]+_k[j])*(abs(_x[i]-_x[j])+abs(_y[i]-_y[j]));
        addedge(i+1,j+1,co);
    }
    vector<int> a1;
    vector<pii> a2;
    sort(E.begin(),E.end());
    for(auto e: E){
        LL w = e.first,u = e.second.first,v = e.second.second;

        if(get_father(u,father) != get_father(v,father)){
            combin(u,v,father);
            ans += w;
            if(u==0||v==0) a1.PB(u+v);
            else a2.PB({u,v});
        }
    }
    cout << ans << endl;
    cout<<a1.size()<<endl;
    for(auto e: a1){
        cout<<e<<" ";
    }
    cout<<a2.size()<<endl;
    for(auto e: a2){
        cout<<e.X<<" "<<e.Y<<endl;
    }
    return 0;
}



