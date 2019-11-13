#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t,n,i;
	string cad1,cad2;
	cin>>t;
	while(t--){
		cin>>n>>cad1>>cad2;
		vector<int> pos;
		for(i=0; i<n; i++){
			if(cad1[i] != cad2[i])
			pos.push_back(i);
		}
		if(pos.size() == 0)
		cout<<"YES"<<endl;
		else if(pos.size() == 2){
			if(cad1[pos[0]] == cad1[pos[1]] && cad2[pos[0]] == cad2[pos[1]])
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}
		else
		cout<<"NO"<<endl;
	}
}