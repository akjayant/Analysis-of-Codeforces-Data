#pragma GCC optimize ("03")
#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define F first
#define S second 
using namespace std;
long long n, m, k, q, a[100005];
int main(){ios_base::sync_with_stdio(false);
    cin>>q; 
    while(q--){k=1;
    	cin>>n;
    	for (int i=1; i<=n; i++){
    		cin>>a[i]; a[i]=-a[i];
		}
		sort(a+1, a+n+1);
		while(k<=n && -a[k]>=k)k++;
		cout<<k-1<<endl;
	}
    
    
    
    
    return 0;
}