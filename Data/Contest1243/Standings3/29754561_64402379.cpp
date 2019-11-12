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
		set<int> wa;
		vector<pair<int,int>> ans;
		map<char,int> mp;
		vector<set<int>> arr(26),brr(26);
		for(int i=0;i<n;i++){
			mp[a[i]]++;
			mp[b[i]]++;
			if(a[i]!=b[i]){
				arr[a[i]-'a'].insert(i);
				brr[b[i]-'a'].insert(i);
				wa.insert(i);
			}
		}
		bool flag=1;
		for(auto i:mp)
			if(i.second&1){
				flag=0;
				break;
			}
		if(!flag){
			cout<<"No"<<endl;
		}
		else{
			while(!wa.empty()){
				bool flag=0;
				for(int i=0;i<26;i++){
					if(arr[i].size()>1){
						flag=1;
						int x=*arr[i].begin();
						int y=*prev(arr[i].end());
					//	cout<<"arr:"<<endl<<a<<"\n"<<b<<"\n"<<x<<" "<<y<<endl;
						ans.push_back({y,x});
						wa.erase(x);
						swap(a[y],b[x]);
						if(a[y]==b[y])
							wa.erase(y);
						break;
					}
				}
				arr.clear();arr.resize(26);
				brr.clear();brr.resize(26);
				for(auto i:wa){
					arr[a[i]-'a'].insert(i);
					brr[b[i]-'a'].insert(i);
				}
				for(int i=0;i<26;i++){
					if(brr[i].size()>1){
						flag=1;
						int x=*brr[i].begin();
						int y=*prev(brr[i].end());
					//	cout<<"brr:\n"<<a<<"\n"<<b<<"\n"<<x<<" "<<y<<endl;
						ans.push_back({x,y});
						wa.erase(x);
						swap(a[x],b[y]);
						if(a[y]==b[y])
							wa.erase(y);
						break;
					}
				}
				if(!flag){
					ans.push_back({*wa.begin(),*wa.begin()});
					swap(a[*wa.begin()],b[*wa.begin()]);
				}
				arr.clear();arr.resize(26);
				brr.clear();brr.resize(26);
				for(auto i:wa){
					arr[a[i]-'a'].insert(i);
					brr[b[i]-'a'].insert(i);
				}
			}
			cout<<"Yes"<<endl;
			cout<<ans.size()<<endl;
			for(auto i:ans)
				cout<<i.first+1<<" "<<i.second+1<<endl;
		}
	}
	return 0;
}
/*
becde
bacda

*/
