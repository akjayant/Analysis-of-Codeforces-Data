#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

const int MAXN=400000;

queue <ll> q;
ll n,k,a,b;
ll niz[MAXN+5];
ll kad[MAXN+5],boja[MAXN+5];

int main () {
	
	cin>>n>>k;
	string s;
	cin>>s;
	memset(kad,-1,sizeof(kad));
	for(int i=0; i<n; i++){
		if(s[i]=='B'){
			niz[i]=1;
		}
		else{
			niz[i]=0;
		}
	}
	for(int i=0; i<n; i++){
		a=(i-1)%n;
		if(a==-1){
			a=n-1;
		}
		b=(i+1)%n;
		if(niz[a]==niz[i] || niz[b]==niz[i]){
			kad[i]=0;
			boja[i]=niz[i];
			q.push(i);
		}
	}
	while(q.size()>0){
		ll x=q.front();
		q.pop();
		a=(x-1)%n;
		if(a==-1){
			a=n-1;
		}
		b=(x+1)%n;
		if(kad[a]==-1){
			kad[a]=kad[x]+1;
			boja[a]=boja[x];
			q.push(a);
		}
		if(kad[b]==-1){
			kad[b]=kad[x]+1;
			boja[b]=boja[x];
			q.push(b);
		}
	}
	for(int i=0; i<n; i++){
		if(kad[i]<=k && kad[i]>-1){
			if(boja[i]==1){
				cout<<"B";
			}
			else{
				cout<<"W";
			}
		}
		else{
			if(k%2==0){
				if(niz[i]==1){
					cout<<"B";
				}
				else{
					cout<<"W";
				}
			}
			else{
				if(niz[i]==1){
					cout<<"W";
				}
				else{
					cout<<"B";
				}
			}
		}
	}
	
	return 0;
}
