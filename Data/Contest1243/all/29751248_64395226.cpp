#pragma GCC optimize ("03")
#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define F first
#define S second 
using namespace std;
long long n, m, k, q, ans1[100005], ans2[100005], o, u, d, f[50];
string a, b;
int main(){ios_base::sync_with_stdio(false);
    cin>>n;m=n; k=sqrt(n);
    for (int i=2; i<=k; i++){
    	if(n%i==0){
			while(n%i==0){n/=i;}
			if(n==1){cout<<i; return 0;}
			else{cout<<1; return 0;}
		}
	}
	cout<<m;
    
    return 0;
}