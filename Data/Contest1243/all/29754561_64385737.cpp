#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl '\n'
using namespace std;
template<typename T>
istream& operator>>(istream& in,pair<T,T>& p){
	in>>p.first>>p.second;
	return in;
}
template<typename T>
ostream& operator<<(ostream& out,pair<T,T> p){
	out<<p.first<<" "<<p.second;
	return out;
}

mt19937 gen(time(0));

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	ll n,ans=0,tmp;
	vector<ll> arr;
	cin>>n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			if(i*i==n){
				ans++;
				if(arr.empty()||((i%arr.front())!=0))
					arr.push_back(i);
				tmp=i;
			}
				
			else{
				ans+=2;
				if(arr.empty()||((i%arr.front())!=0))
					arr.push_back(i);
				if((n/i)%arr.front()!=0)
					arr.push_back(n/i);
			}
		}
	}
	if(ans==0)
		cout<<n<<endl;
	else if(arr.size()==1){
		cout<<arr.front()<<endl;
	}
	else{
		cout<<1<<endl;
	}
	return 0;
}


