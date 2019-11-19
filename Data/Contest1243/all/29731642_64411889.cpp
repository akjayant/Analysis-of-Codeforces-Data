
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+100;
const int mod = 1e9+7;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f3f;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define fep(i,a,b) for(int i=(a);i>=(b);i--)
inline bool read(ll &num) {
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
            num*=10,num+=in-'0';
    } 
    if(IsN) num=-num;
    return true;
}
int sum[N];
vector<int> G[N];
set<int> st;
struct Dsu
{
	int pre[N], siz[N];
	void Init(){
		for (int i = 0; i < N; ++i)
			pre[i] = i, siz[i] = 1;
	}
	int Find(int x){
		return pre[x] == x ? x : pre[x] = Find(pre[x]);
	}
}d;
int main()
{
	d.Init();
	int n, m, u, v;
	cin >> n >> m;
    rep(i,1,m){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans=n-1;
	rep(i,1,n)
	{
		for (int j:G[i]){
			int f = d.Find(j);
			++sum[f];
		}
		for (auto it = st.begin(); it != st.end();){
			int j = d.Find(*it);
			if (sum[j] < d.siz[j])
				d.pre[j] = i, d.siz[i] += d.siz[j], st.erase(it++), --ans;
			else
				++it;
		}
		for (int j : G[i]){
			int f = d.Find(j);
			sum[f] = 0;
		}
		st.insert(i);
	}
	cout << ans << endl;
	return 0;
}
