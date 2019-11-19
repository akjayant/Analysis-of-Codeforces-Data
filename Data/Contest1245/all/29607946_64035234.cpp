#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;
 
#define ll long long int 
#define pb push_back
#define mp make_pair 
#define fi first 
#define se second 
#define pbb pop_back
#define pii pair<ll,ll>

ll read(){ 
	char ch;
 	for(ch = getchar();ch<0x30||ch>0x39;ch=getchar());
 	ll x = ch - 0x30;
	for(ch = getchar();ch>=0x30&&ch<=0x39;ch=getchar())
		x = x*10+ch-0x30;
 	return x;
}
ll X[2005],Y[2005],A[2005],C[2005];
ll vis[2005];
struct node{
	ll type;// -1 alone, 
	ll cost;
	ll id;
	friend bool operator<(node a,node b){
		return a.cost > b.cost;
	}
};
node mk(ll p,ll q, ll r){ // id,type,cost
	node re;
	re.id = p; re.type = q; re.cost = r;
	return re;
}
vector<ll>AA,P,Q;
int main(){
	ll sum = 0;
 	ll n = read();	
 	for(int i=0;i<n;i++){
 		X[i] = read();
 		Y[i] = read();
 	}
 	ll mip = 0;
 	for(int i=0;i<n;i++){
 		A[i] = read();
 	}
 	for(int i=0;i<n;i++)
 		C[i] = read();
 	priority_queue<node>que;
 	for(int i=0;i<n;i++){
 		que.push(mk(i,-1,A[i]));
 	}
 	ll cnt = 0;
 	while(cnt < n){
 		node tp = que.top();que.pop();
 		if(vis[tp.id]) continue;
 		cnt++;
 		sum += tp.cost;
 		vis[tp.id] = 1;
 		// cout << tp.id << "--" << endl;
 		if(tp.type == -1) AA.pb(tp.id);
 		else {P.pb(tp.id);Q.pb(tp.type);}
 		for(int i=0;i<n;i++){
 			if(vis[i]) continue;
 			ll co = (abs(X[i]-X[tp.id])+abs(Y[i]-Y[tp.id]))*(C[i]+C[tp.id]);
 			if(co < A[i]){
 				que.push(mk(i,tp.id,co));
 			}
 		}
 	}
 	cout << sum << endl;
 	cout << AA.size() << endl;
 	for(int i=0;i<AA.size();i++){
 		cout << AA[i]+1 << " ";
 	}
 	puts("");
 	cout<< P.size() << endl;
 	for(int i=0;i<P.size();i++){
 		cout << P[i]+1 << " " << Q[i]+1	 << endl;
 	}
	return 0;
}
