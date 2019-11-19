#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,m,A[100000],S[200000],B[100000];
pii ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0 ; i<n ; i++){
		char c;
		cin>>c;
		if(c=='('){
			A[i]=1;
		}
		else A[i]=0;
	}
	int s = 0;
	for(int i=0 ; i<n ; i++){
		s+=A[i];
	}
	if(s!=n/2){
		cout<<"0\n1 1";
		return 0;
	}
	int MA = -10;

	for(int k=0 ; k<n ; k++){	
		for(int l=k ; l<n ; l++){
			for(int i=0 ; i<n ; i++){
				B[i] = A[i];
				S[i]=0;
			}
			for(int i=0 ; i<n ; i++){
				B[n+i] = A[i];
			}
			int ca = 0;
			swap(B[l],B[k]);
			S[0]=2*B[0]-1;
			for(int i=1 ; i<2*n ; i++){
				S[i] = S[i-1]-1+2*B[i];
			}
			int mi = 1000;
			for(int i=0 ; i<n ; i++){
				mi = min(mi,S[i]);
			}
			int t = 0;
			if(mi>=0)ca++;
			for(int i=0 ; i<n-1 ; i++){
				t-=(2*B[i]-1);
				mi-=(2*B[i])-1;
				mi = min(mi,B[i+n]+t);
				if(mi>=0)ca++;
			}
			if(MA<ca){
				ans = make_pair(k,l);
				MA = ca;
			}
		}
	}
	cout<<MA<<"\n";
	cout<<ans.first+1<<" "<<ans.second+1;
}