#include<bits/stdc++.h>
#pragma GCC optimize ("-ffloat-store")
#define ll long long
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define maxn 100002
#define pb push_back
#define X first
#define Y second
#define mod 1000000007
#define base 17
//#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define db(x) ;
using namespace std;
typedef pair<int,int> ii;
int deg[maxn];
int n,m,a,b;
vector<int> ke[maxn];
bool mark[maxn];
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> n >> m;
    For(i,1,m){
    	cin >> a >>b;
    	deg[a]++;
    	deg[b]++;
    	ke[a].pb(b);
    	ke[b].pb(a);
	}
	priority_queue<ii> PQ;
	For(i,1,n){
		PQ.push({deg[i],i});
	}
	int ans = 0;
	For(i,1,n-1){
		ii e;
		while(1){
			e = PQ.top();
			PQ.pop();
			if(mark[e.Y]==true || e.X != deg[e.Y]){
				continue;
			}
			break;
		}
		mark[e.Y] = true;
		if(e.X == n-i){
			ans++;
		}
		for(int &x:ke[e.Y]){
			deg[x]--;
			PQ.push({deg[x],x});
		}
	}
	cout << ans;
}
