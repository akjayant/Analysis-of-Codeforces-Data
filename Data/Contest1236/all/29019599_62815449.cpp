//amitgomi
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
// #define mp(x,y) make_pair(x,y)
#define mod 1000000007
#define sc(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
 
///////////////////////////////////////////////////////////
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// ordered_set st;
// st.order_of_key(l);
// double PI=3.1415926535897932384626;
// ll bin_expo(ll a,ll b, ll m){ ll res =1; a %= m; while(b!=0){ if(b%2==1) res = (res*a)%mod; a = (a*a)%mod; b = b/2; } return res; }
// ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); } 
///////////////////////////////////////////////////////////////////////////////////////////////////
 
int n,m,k;
set<int > ho[100005],vo[100005];
 
 
inline int erse(int x1,int y1,int x2,int y2){
	// cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
	for(int i=x1;i<x2;i++){
		for(int j=y1;j<y2;j++){
			if(i>=0 && ho[i].find(j)==ho[i].end()){
				return 0;
			}
			ho[i].erase(j);
			vo[j].erase(i);
		}
	}
	return 1;
}
 
int solve(){
	int x1=1,y1=1,x2=n,y2=m;
	int x=1,y=1,d=0;
	// cout<<"hi"<<endl;
	while(x1<=x2 && y1<=y2){
		// cout<<x<<' '<<y<<' '<<d<<"  "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
		if(d==0){
			int rx1=x1,ry1=y2+1,rx2=x2+1,ry2=y2+1;
			if(!ho[x1].empty()){
				ry1 = (*(ho[x1].begin()));
			}
			if(rx1<rx2 && ry1<ry2 &&erse(rx1,ry1,rx2,ry2)==0){
				// cout<<"No"<<endl;
				return 0;
			}
			x1++;
			y2 = ry1-1;
			x=x1;
			y = y2;
			if(x>=0 && ho[x].find(y)!=ho[x].end()){
				return erse(x1,y1,x2+1,y2+1);
			}
			d = (d+1)%4;
		}
		else if(d==1){
			int rx1=x2+1,ry1=y1,rx2=x2+1,ry2=y2+1;
			if(!vo[y2].empty()){
				rx1 = (*(vo[y2].begin()));
			}
			if(rx1<rx2 && ry1<ry2 &&erse(rx1,ry1,rx2,ry2)==0){
				// cout<<"No"<<endl;
				return 0;
			}
			y2--;
			x2 = rx1-1;
			y = y2;
			x=x2;
			if(x>=0 && ho[x].find(y)!=ho[x].end()){
				return erse(x1,y1,x2+1,y2+1);
			}
			d = (d+1)%4;
		}
 
		else if(d==2){
			int rx1=x1,ry1=y1,rx2=x2+1,ry2=y1;
			if(!ho[x2].empty()){
				auto it = ho[x2].end();
				it--;
				ry2 = (*(it))+1;
			}
			if(rx1<rx2 && ry1<ry2 &&erse(rx1,ry1,rx2,ry2)==0){
				// cout<<"No"<<endl;
				return 0;
			}
			x2--;
			y1 = ry2;
			x=x2;
			y = y1;
			if(x>=0 && ho[x].find(y)!=ho[x].end()){
				return erse(x1,y1,x2+1,y2+1);
			}
			d = (d+1)%4;
		}
 
		else if(d==3){
			int rx1=x1,ry1=y1,rx2=x1,ry2=y2+1;
			if(!vo[y1].empty()){
				auto it = vo[y1].end();
				it--;
				rx2 = (*(it))+1;
			}
			if(rx1<rx2 && ry1<ry2 &&erse(rx1,ry1,rx2,ry2)==0){
				// cout<<"No"<<endl;
				return 0;
			}
			y1++;
			x1 = rx2;
			x=x1;
			y = y1;
			if(x>=0 && ho[x].find(y)!=ho[x].end()){
				return erse(x1,y1,x2+1,y2+1);
			}
			d = (d+1)%4;
		}
	}
	return 1;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	// cin>>n>>m>>k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++){
		int a,b;
		// cin>>a>>b;
	scanf("%d%d",&a,&b);
		ho[a].insert(b);
		vo[b].insert(a);
	}
	// cout<<"hi"<<endl;
	if(solve()==1){
		printf("Yes\n");
		// cout<<"Yes"<<endl;
	}
	else
		printf("No\n");
		// cout<<"No"<<endl;
	return 0;
}