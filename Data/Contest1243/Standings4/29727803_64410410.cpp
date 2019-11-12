#include <iostream>
#include <bits/stdc++.h>
#define forn(i,n)for(int i=0;i<n;i++)
#define forna(i,a,n)for(int i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1e9+7
#define ff first
#define ss second
#define INF 1e9
#define MAX 100000
#define ya cout<<"YES"<<endl;continue;
typedef long long ll;
using namespace std;
vector <pair<int,int>> p(MAX);
set <int> s;
int count[MAX];
int main()
{
    IOS
	int q;cin>>q;
	while(q--){
		int n;cin>>n;
		string s,t;cin>>s>>t;
		vector <char> ss,tt;
		vector <int> prob;
		vector <pair<int,int>> trans;
		int c[26]={0};
		forn(i,n){
			c[s[i]-'a']++;
			c[t[i]-'a']++;
		}
		int f=0;
		forn(i,26){
			if(c[i] %2) {
				cout<<"NO"<<endl;
				f=1;break;
			}
		}
		if(f) continue;
		cout<<"YES"<<endl;
		int ff=1;char cc;int k;
		while(true){
			ff=1;
			forn(i,n){
				if(s[i]==t[i]) continue;
				cc = s[i];
				ff=0;
				k=i;
				break;
			}
			if(ff) break;
			forn(i,n){
				if(s[i]==t[i]) continue;
				if(k==i) continue;
				if(s[i] == cc){
					trans.pb(mp(i+1,k+1));
					s[i] = t[k];
					t[k] = cc;
					break;
				}
				if(t[i]==cc){
					trans.pb(mp(i+1,i+1));
					trans.pb(mp(i+1,k+1));
					t[i] = s[i];
					s[i] = t[k];
					t[k] = cc;
					break;
				}
			}


		}
		cout<<trans.size()<<endl;
        forn(i,trans.size()){
				cout<<trans[i].ff<<" "<<trans[i].ss<<endl;
			}


	}
}
