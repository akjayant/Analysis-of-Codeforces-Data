#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair
#define pri 1000000007
#define all(x) x.begin(),x.end()
using namespace std;

void masterstroke(){
	ll n,m,k;
	cin>>n>>m>>k;
	
	ll count=n*m-k-1;
	ll left=0,right=n+1,top=m+1,bottom=0;
	
	vector <ll> row[n+1];
	vector <ll> col[m+1];


	
	for(ll i=0;i<k;i++){
		ll x,y;cin>>x>>y;
		row[x].PB(y);
		col[y].PB(x); 
	//	cout<<x<<y<<endl;
		
	}
	for(ll i=0;i<=n;i++){row[i].PB(0);row[i].PB(m+1);sort(all(row[i]));}
		for(ll i=0;i<=m;i++){col[i].PB(0);col[i].PB(n+1);sort(all(col[i]));}
	//	for(auto x:col[2])cout<<x<<endl;
	ll dir=1;
	ll curx=1,cury=1;
	map <pair<ll,ll>,ll> ch;
	
	while(count>0){
		//cout<<count<<endl;
		if(dir==1){
			auto f=upper_bound(all(row[curx]),cury);
			ll z=*f;
			ll e=min(z,top);
			count-=(e-1-cury);
			cury=e-1;
			left=curx;
		}
		
		if(dir==2){
		    auto f=upper_bound(all(col[cury]),curx);
			ll z=*f;
			ll e=min(z,right);
			count-=(e-1-curx);
			curx=e-1;
			top=cury;
		}
		
		if(dir==3){
			
			auto f=upper_bound(all(row[curx]),cury);
			f--;
			ll z=*f;
			ll e=max(z,bottom);
			count-=(cury-(e+1));
			cury=e+1;
			right=curx;
			
		}
		if(dir==4){
		//  cout<<curx<<"sss"<<endl;
			auto f=upper_bound(all(col[cury]),curx);
		//	cout<<"d"<<*f<<endl;
			f--;
			ll z=*f;
		//	cout<<z<<left<<"sss"<<endl;
			ll e=max(z,left);
			count-=(curx-(e+1));
		//	cout<<e<<endl;
			curx=e+1;
			bottom=cury;
		}
		
		if(ch[MP(curx,cury)]==1)break;
		ch[MP(curx,cury)]=1;
		dir=(dir)%4+1;
	//	cout<<curx<<" "<<cury<<endl;
	//	cout<<dir<<"gg"<<endl;
	}
//	cout<<count<<endl;
	if(count==0)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	
	
	}

int main() {
	//cout<<pri+3;
	ll t=1;
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	//cin>>t;
	for(ll i=0;i<t;i++)masterstroke();

	// your code goes here
	return 0;
}