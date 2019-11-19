//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 1000000007
#define fi first
#define se second
#define pii pair<int,int>
#define int long long
#define endl '\n'
#define pll pair<long long,long long>
#define LONGLONG_MAX 10000000000000000
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int a[n];
    map<int,int>m,m1;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
    	m[a[i]]=i;
    	if(m1.find(a[i])==m1.end())m1[a[i]]=i;
    }
    int i=m[a[0]]+1,j=m1[a[n-1]]-1;
    int x=a[0],z=a[n-1];
    while(i<=j+1&&k>=min(i,n-j-1)){
        //cout<<i<<" "<<j<<endl;
    	if(i<n-j-1){
    		int y=min(k,(a[i]-x)*i);
    		x+=y/i;
    		k-=y;
    		i=m[a[i]]+1;
    	}
    	else{
    		int y=min(k,(z-a[j])*(n-j-1));
    		z-=y/(n-j-1);
    		k-=y;
    		j=m1[a[j]]-1;
    	}
    }
    //cout<<i<<" "<<j;
    cout<<z-x;
    return 0;
}