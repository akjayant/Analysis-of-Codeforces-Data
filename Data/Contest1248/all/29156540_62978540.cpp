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
int main(){fast;
	ll t;
	cin>>t;
	while(t--){
		ll n,i,m,x,o1=0,e1=0,o2=0,e2=0;
		cin>>n;
		for(i=0;i<n;i++) cin>>x,o1+=x%2,e1+=1-x%2;
		cin>>m;
		for(i=0;i<m;i++) cin>>x,o2+=x%2,e2+=1-x%2;
		cout<<o1*o2+e2*e1<<endl;
	}
}
