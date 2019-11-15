#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		string s,t;
		cin >> s >> t;
		ll i,j;
		ll count=2;
		char a,b;
		bool flag=true;
		for(i=0;i<n;i++){
			if(s[i]==t[i]){
				//do nothing
			}
			else{
				if(count==2){
					count--;
					a=s[i];
					b=t[i];
				}
				else if(count==1){
					flag=(b==t[i] && a==s[i]);
					count--;
				}
				else{
					count--;
				}
			}
		}
		if(flag && count==0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}