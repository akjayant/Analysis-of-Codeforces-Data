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
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)	cin>>arr[i];
		sort(arr.rbegin(),arr.rend());
		int maxn=0;
		for(int i=0;i<n;i++){
			if(arr[i]>=i+1)
				maxn=i+1;
		}
		cout<<maxn<<endl;
	}
	return 0;
}


