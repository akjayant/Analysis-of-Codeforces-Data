#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define pii pair<int,int>
#define io(); freopen("in.txt","r",stdin); freopen("output.txt","w",stdout); 
#define fast(); ios_base::sync_with_stdio(false);
#define all(x) x.begin(),x.end()
bool val(string u,string s){
	vector<int>v(26,0);
	u=u+s;
	for(auto c:u) v[c-97]++;
	for(auto x:v) if(x%2==1) return false;
	return true;
}
int32_t main(){
	fast();
    #ifndef ONLINE_JUDGE
    io();
    #endif
    int t,n,i,j;
    cin>>t;
    while(t--){
    	cin>>n;
    	string u,v;
    	cin>>u>>v;
    	if(!val(u,v)) cout<<"No\n";
    	else{
    		cout<<"Yes\n";
    		vector<pii>arr;
    		for(i=0;i<n;i++){
    			if(u[i]!=v[i]){
    				bool flag=false;
    				for(j=i+1;j<n;j++){
    					if(u[j]==u[i]){
    						flag=true;
    						arr.pb({j+1,i+1});
    						swap(v[i],u[j]);
    						break;
    					}
    				}
    				if(!flag){
    					for(j=i+1;j<n;j++){
    						if(v[j]==u[i]){
    							arr.pb({n,j+1});
    							swap(u[n-1],v[j]);
    							arr.pb({n,i+1});
    							swap(u[n-1],v[i]);
    							break;
    						}
    					}
    				}
    			}
    		}
    		if(arr.size()==0){
    			cout<<1<<endl<<1<<" "<<1<<endl;
    		}
    		else{
    			cout<<arr.size()<<endl;
    			for(auto x:arr) cout<<x.first<<" "<<x.second<<endl;
    		}
    	}
    }
}