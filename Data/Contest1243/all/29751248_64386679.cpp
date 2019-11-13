#pragma GCC optimize ("03")
#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define F first
#define S second 
using namespace std;
long long n, m, k, q, ans1[100005], ans2[100005], o, d, f[50];
string a, b;
int main(){ios_base::sync_with_stdio(false);
    cin>>q; 
    while(q--){k=1;
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
				if(a[i]==b[i])continue;
				for (int j=i+1; j<n; j++){
					if(a[i]==a[j]){
						ans1[++o]=j;
						ans2[o]=i;
						swap(a[j], b[i]);
						j=n;
					}else if(a[i]==b[j]){
						ans1[++o]=j;
						ans2[o]=j;
						swap(a[j], b[j]);
				//	cout<<a<<" "<<b<<endl;
						ans1[++o]=j;
						ans2[o]=i;
						swap(a[j], b[i]);
				//	cout<<a<<" "<<b<<endl;
						j=n;
					}
				}
			}
			cout<<"Yes"<<endl;
			cout<<o<<endl;
			for (int i=1; i<=o; i++)
				cout<<ans1[i]+1<<" "<<ans2[i]+1<<endl;
		}
		o=0;
		for (int i=0; i<=40; i++)f[i]=0;
		d=0;
	}
    
    
    
    
    return 0;
}