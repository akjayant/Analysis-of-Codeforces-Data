#include "bits/stdc++.h"
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 100000000007;

typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

// Print fn to print array

void fn(int p, vi &parent, vector<bool> &visited, vector<vi> &arr){
	visited[p]=true;
	for(int i=0;i<arr[p].size();i++){
		if(visited[arr[p][i]]==false){
			parent[p]=arr[p][i];
			fn(arr[p][i],parent,visited,arr);
		}
	}
}

void fn1(int a, int b, int p, ll &res, vi &res1, vll &c1, vll &c2, vll &c3, vi &parent){
	if(parent[p]==-1) return;
	if(min(a,b)==1 && max(a,b)==2){
		int c = 3;
		res1[parent[p]]=c;
		res+=(c3[parent[p]-1]);
		fn1(b,c,parent[p],res,res1,c1,c2,c3,parent);
	}
	else if(min(a,b)==1 && max(a,b)==3){
		int c = 2;
		res1[parent[p]]=c;
		res+=(c2[parent[p]-1]);
		fn1(b,c,parent[p],res,res1,c1,c2,c3,parent);
	}
	else{
		int c = 1;
		res1[parent[p]]=c;
		res+=(c1[parent[p]-1]);
		fn1(b,c,parent[p],res,res1,c1,c2,c3,parent);
	}
}

int main(){
	int t;
	t = 1;
	while(t--){
    	ll n;
    	cin >> n;
    	vll c1(n);
    	vll c2(n);
    	vll c3(n);
    	for(int i=0;i<n;i++) cin >> c1[i];
    	for(int i=0;i<n;i++) cin >> c2[i];
    	for(int i=0;i<n;i++) cin >> c3[i];

    	vector<vi> arr(n+1);
    	for(int i=0;i<n-1;i++){
    		int a,b;
    		cin >> a >> b;
    		arr[a].PB(b);
    		arr[b].PB(a);
    	}

    	if(n==1){
    		cout << min(c1[0],min(c2[0],c3[0]));
    		return 0;
    	}

    	int p;
    	for(int i=1;i<n+1;i++){
    		if(arr[i].size()>2){
    			cout << -1 << endl;
    			return 0;
    		}
    		if(arr[i].size()==1) p=i;
    	}

    	vector<int> parent(n+1,-1);
    	vector<bool> visited(n+1, false);
    	fn(p,parent,visited,arr);

    	ll res1=c1[p-1]+c2[parent[p]-1],
    		res2=c1[p-1]+c3[parent[p]-1],
    		res3=c2[p-1]+c3[parent[p]-1],
    		res4=c2[p-1]+c1[parent[p]-1],
    		res5=c3[p-1]+c1[parent[p]-1],
    		res6=c3[p-1]+c2[parent[p]-1];
    	vi res(n+1);
    	res[p]=1;
    	res[parent[p]]=2;
    	fn1(1,2,parent[p],res1,res,c1,c2,c3,parent);
    	ll res8 = res1;
    	// cout << res8 << endl;
    	// for(int i=1;i<=n;i++) cout << res[i] << " "; cout << endl;

    	vi res7(n+1);
    	res7[p]=1;
    	res7[parent[p]]=3;
    	fn1(1,3,parent[p],res2,res7,c1,c2,c3,parent);
    	if(res2<res8){
    		res=res7;
    		res8 = res2;
    	}
    	// cout << res8 << endl;
    	// for(int i=1;i<=n;i++) cout << res[i] << " "; cout << endl;
    	res7[p]=2;
    	res7[parent[p]]=3;
    	fn1(2,3,parent[p],res3,res7,c1,c2,c3,parent);
    	if(res3<res8){
    		res=res7;
    		res8 = res3;
    	}
    	// cout << res8 << endl;
    	// for(int i=1;i<=n;i++) cout << res[i] << " "; cout << endl;
    	res7[p]=2;
    	res7[parent[p]]=1;
    	fn1(2,1,parent[p],res4,res7,c1,c2,c3,parent);
    	if(res4<res8){
    		res=res7;
    		res8 = res4;
    	}
    	// cout << res8 << endl;
    	// for(int i=1;i<=n;i++) cout << res[i] << " "; cout << endl;
    	res7[p]=3;
    	res7[parent[p]]=1;
    	fn1(3,1,parent[p],res5,res7,c1,c2,c3,parent);
    	if(res5<res8){
    		res=res7;
    		res8 = res5;
    	}
    	// cout << res8 << endl;
    	// for(int i=1;i<=n;i++) cout << res[i] << " "; cout << endl;
    	res7[p]=3;
    	res7[parent[p]]=2;
    	fn1(3,2,parent[p],res6,res7,c1,c2,c3,parent);
    	if(res6<res8){
    		res=res7;
    		res8 = res6;
    	}

    	cout << res8 << endl;
    	for(int i=1;i<=n;i++) cout << res[i] << " "; cout << endl;
	}	
	return 0;
}
