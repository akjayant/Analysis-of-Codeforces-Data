#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
#include <fstream>
#include <queue>
#include <iomanip>
#include <iterator>
#include <map>
#include <unordered_map>
#include <set>
#define fast ios_base::sync_with_stdio(false)
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vvi vector<vi >
#define pi pair<ll,ll>
#define vvpi vector<vector<pi > >
#define vpi vector<pi >
#define vppi vector<pair<ll,pi > >
#define vs vector<string>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define fs first
#define se second
#define crz(v,n,c) v.clear(),v.resize(n,c)
#define print(v) for(ll it=0;it<v.size();it++) cout<<v[it]<<" ";cout<<endl
#define printp(v) for(ll it=0;it<v.size();it++) cout<<v[it].first<<" "<<v[it].second<<endl
using namespace std;
int main(){
	ll n,m,i,k=1e9+7,s,f,x;
	cin>>n>>m;f=max(n,m);
	vvi v(f,vi(4,0));
	v[0][0]=1;
	for(i=1;i<f;i++){
		v[i][0]=v[i][2]=(v[i-1][0]-v[i-1][2]+k)%k;
		v[i][1]=v[i][3]=(v[i-1][1]-v[i-1][3]+k)%k;
		v[i][0]=(v[i][0]+v[i-1][1])%k;
		v[i][1]=(v[i][1]+v[i-1][0])%k;
	}s=(v[n-1][0]+v[n-1][1])%k;
	x=(v[m-1][0]+v[m-1][1])%k;
	x=(2*x-2+k)%k;
//	for(i=0;i<n;i++){print(v[i]);}
	s=(2*s+x)%k;
	cout<<s<<endl;
}
