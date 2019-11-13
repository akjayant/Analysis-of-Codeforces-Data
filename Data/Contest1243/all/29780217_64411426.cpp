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
		ll alpha[26]={0};
		ll schar[26]={0};
		ll tchar[26]={0};
		ll i,j;
		vector<ll> a;
		vector<ll> b;
		ll m=0;
		for(i=0;i<n;i++){
			alpha[s[i]-'a']++;
			alpha[t[i]-'a']++;
			schar[s[i]-'a']++;
			tchar[t[i]-'a']++;
		}
		bool flag=true;
		for(i=0;i<26;i++){
			flag=(flag && (alpha[i]%2==0));
		}
		if(flag==false){
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
		for(i=n-1;i>=0;i--){
			if(s[i]==t[i]){
				//do nothing;
			}
			else{
				bool flag=false;
				for(j=0;j<i;j++){
					if(t[j]==s[i]){
						flag=true;
						break;
					}
				}
				if(flag){
					m+=2;
					char temp=t[i];
					t[i]=t[j];
					t[j]=temp;					
					a.push_back(i+1);
					b.push_back(i+1);
					a.push_back(i+1);
					b.push_back(j+1);
				}
				else{
					for(j=0;j<i;j++){
						if(s[j]==s[i]){
							break;
						}
					}
					m++;
					char temp=t[i];
					t[i]=s[j];
					s[j]=temp;
					a.push_back(j+1);
					b.push_back(i+1);
				}
			}
		}
		cout << m << endl;
		for(i=0;i<m;i++){
			cout << a[i] << " " << b[i] << endl;
		}
	}
}