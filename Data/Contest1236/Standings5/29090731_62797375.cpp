#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,x,i,j;
	cin>>n;
	for(i=1; i<=n; i++){
		x = i;
		for(j=0; j<n; j++){
			if(j > 0)
			cout<<" ";
			x = j*n;
			if(j % 2 == 0)
			x += i;
			else
			x += n+1-i;
			cout<<x;
		}
		cout<<endl;
	}
}