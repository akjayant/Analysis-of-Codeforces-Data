#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pop pop_back
#define ll long long
#define fr first
#define sc second
#define inf 180000000;
#define FASTIOS ios_base::sync_with_stdio(false);  cin.tie(NULL);cout.tie(NULL);
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
#define sz(a) int((a).size())
ll n,m,i,j,k,t,ans,count=0,last=0;
bool p[1000004];
int main(){
	FASTIOS
	cin >> n;
    m=sqrt(n);
    if(n==1){
    	cout<<1;
    	return 0;
	}
	for(i=2;i<=1000001;i++) p[i]=1;
	for(i=2;i<=1004;i++){
		if(p[i]){
			for(j=i*i;j<=1000001;j+=i)
				p[j]=0;
		} 
	}
bool h=0;
while(true){
	m=sqrt(n);
	for(i =2;i<=m;i++){
		if(p[i] && n%i==0){
			if(last!=0 && last!=i){
				cout<<1;
				return 0;
			}
			last=i;
			n/=i;
			break;
		}
	}
	if(i==m+1 && n>last && last!=0){
	    cout<<1;
	    return 0;
	}
	if(i==m+1) break;
}
	if(last==0){
		cout<<n;
		return 0;
	}
		cout<<last;
}