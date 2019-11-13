#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    int n; string a,b; int condi,arr[2];
    while(T--){
    	cin>>n;
    	cin>>a;
    	cin>>b;
    	condi=2; int tr=1;
    	for(int i=0;i<n;i++){
    		if(a[i]!=b[i]){
    			condi--;
    			if(condi==1){
    				arr[0]=a[i]; arr[1]=b[i];
				} else if(condi == 0) {
					if(!(arr[0]==a[i] && arr[1]==b[i])) tr=0;
				}
			}
		}
		if(condi==2 || (condi==0 && tr)) cout<<"Yes\n";
		else cout<<"No\n";
	}
}