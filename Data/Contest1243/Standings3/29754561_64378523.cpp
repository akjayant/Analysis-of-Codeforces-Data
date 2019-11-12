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
	int t,n;
	string a,b;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>a>>b;
		vector<int> wa;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i])
				wa.push_back(i);
		}
		if(wa.size()!=2){
			cout<<"No"<<endl;
		}
		else{
			
			if(a[wa[0]]==a[wa[1]]&&b[wa[0]]==b[wa[1]])
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
	return 0;
}


