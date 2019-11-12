#include <bits/stdc++.h> 
using namespace std;
#define pb push_back
#define vi vector<int>
#define vpi vector<pair<ll,ll> >
#define mp make_pair
#define F first
#define S second
#define ll long long int
#define mod 1000000007
#define wh(a) cerr<<#a<<"  is  "<<a<<endl;
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t=1;
	
	cin>>t;
	while(t--){
		int n,i,mis1=0,mis2=0;
		string s,t;
		cin>>n>>s>>t;
		int count=0;
		for(i=0;i<n;++i){
			if(s[i]!=t[i]){
				count++;
				mis2=mis1;
				mis1=i;
			}
		}
		if(count==0){
			cout<<"Yes"<<endl;
		}
		else if(count==2){
			if(s[mis1]==s[mis2] && t[mis2]==t[mis1]){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
		else{
			cout<<"No"<<endl;
		}

	}
	return 0;
}