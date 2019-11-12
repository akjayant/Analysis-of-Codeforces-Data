#pragma GCC optimize ("03")
#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define F first
#define S second 
using namespace std;
long long n, m, k, q, ans1[100005], ans2[100005], o, u, d, f[50];
string a, b;
int main(){ios_base::sync_with_stdio(false);
    cin>>q; 
    while(q--){k=0;
    	cin>>n>>a>>b;
    	for (int i=0; i<n; i++){
    		f[a[i]-'a']++;
    		f[b[i]-'a']++;
		}
		for (int i=0; i<26; i++){
			if(f[i]%2){
				cout<<"No"<<endl; d=1; i=26;
			}
		}
		if(!d){
			for (int i=0; i<n; i++){
				if(a[i]!=b[i] && k>0 ){k++; if(u!=(a[i]-'a')) k=20;}
				if(a[i]!=b[i] && k==0)k++, u=a[i]-'a';
			}
			if(k>2)cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
		o=0;
		for (int i=0; i<=40; i++)f[i]=0;
		d=0;
	}
    
    
    
    
    return 0;
}