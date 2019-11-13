#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define MAX 100005
#define pb push_back
#define T int t;cin>>t;while(t--)
#define vi vector<int>
#define ff first
#define ss second
using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<vi> a(n);
    int temp = 0;
    int flow = 1;
    for(int i=1;i<=n*n;i++){
    	if(flow==0 && temp==0) flow=1;
    	if(flow==0 && temp==n-1) flow=-1;
    	if(temp==0 && flow==-1){
    		flow =0;
    	}
    	if(temp==n-1 && flow==1){
    		flow=0;
    	}
    	a[temp].pb(i);
    	temp+=flow;
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cout<<a[i][j]<<" ";
    	}
    	cout<<endl;
    }
	return 0;
}