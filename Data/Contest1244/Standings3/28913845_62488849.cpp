#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n , c1[100005] , c2[100005], c3[100005] , par[100005];
vector<int>adj[100005];
vector<int>urutan , warna;
bool vis[100005];
int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c1[i];
		warna.push_back(i);
	}
	for(int i=1;i<=n;i++){
		cin>>c2[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c3[i];
	}
	int node1 , node2;
	int start;
	for(int i=1;i<n;i++){
		cin>>node1>>node2;
		par[node1]++;
		par[node2]++;
		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
	}
	//Check
	for(int i=1;i<=n;i++){
		if(par[i]>2){
			cout<<"-1"<<endl;
			return 0;
		}
		if(par[i]==1)start = i; 
	}
	urutan.push_back(start);
	node1 = start;
	vis[node1] = true;
	for(int i=2;i<=n;i++){
		for(int j=0;j<adj[node1].size();j++){
			if(vis[adj[node1][j]]) continue;
			urutan.push_back(adj[node1][j]);
			vis[adj[node1][j]] = true;
			node1 = adj[node1][j];
		}
	}
	
	int colour[5] = {1,2,3};
	ll ans = 0 , temp=0;
	for(int i=0;i<urutan.size();i++){
		if(colour[i%3]==1) temp = temp + c1[urutan[i]];
		else if(colour[i%3]==2) temp = temp + c2[urutan[i]];
		else if(colour[i%3]==3) temp = temp + c3[urutan[i]];
		warna[urutan[i]-1] = colour[i%3];
	}
	ans = temp;
	
	colour[0] = 1 ; colour[1] = 3; colour[2] = 2;
	temp = 0;
	for(int i=0;i<urutan.size();i++){
		if(colour[i%3]==1) temp = temp + c1[urutan[i]];
		else if(colour[i%3]==2) temp = temp + c2[urutan[i]];
		else if(colour[i%3]==3) temp = temp + c3[urutan[i]];
	}
	if(temp < ans){
		ans = temp;
		for(int i=0;i<urutan.size();i++){
			warna[urutan[i]-1] = colour[i%3];
		}
	}
	
	
	colour[0] = 2 ; colour[1] = 1; colour[2] = 3;
	temp = 0;
	for(int i=0;i<urutan.size();i++){
		if(colour[i%3]==1) temp = temp + c1[urutan[i]];
		else if(colour[i%3]==2) temp = temp + c2[urutan[i]];
		else if(colour[i%3]==3) temp = temp + c3[urutan[i]];
	}
	if(temp < ans){
		ans = temp;
		for(int i=0;i<urutan.size();i++){
			warna[urutan[i]-1] = colour[i%3];
		}
	}
	
	colour[0] = 2 ; colour[1] = 3; colour[2] = 1;
	temp = 0;
	for(int i=0;i<urutan.size();i++){
		if(colour[i%3]==1) temp = temp + c1[urutan[i]];
		else if(colour[i%3]==2) temp = temp + c2[urutan[i]];
		else if(colour[i%3]==3) temp = temp + c3[urutan[i]];
	}
	if(temp < ans){
		ans = temp;
		for(int i=0;i<urutan.size();i++){
			warna[urutan[i]-1] = colour[i%3];
		}
	}
	
	colour[0] = 3 ; colour[1] = 1; colour[2] = 2;
	temp = 0;
	for(int i=0;i<urutan.size();i++){
		if(colour[i%3]==1) temp = temp + c1[urutan[i]];
		else if(colour[i%3]==2) temp = temp + c2[urutan[i]];
		else if(colour[i%3]==3) temp = temp + c3[urutan[i]];
	}
	if(temp < ans){
		ans = temp;
		for(int i=0;i<urutan.size();i++){
			warna[urutan[i]-1] = colour[i%3];
		}
	}
	
	colour[0] = 3 ; colour[1] = 2; colour[2] = 1;
	temp = 0;
	for(int i=0;i<urutan.size();i++){
		if(colour[i%3]==1) temp = temp + c1[urutan[i]];
		else if(colour[i%3]==2) temp = temp + c2[urutan[i]];
		else if(colour[i%3]==3) temp = temp + c3[urutan[i]];
	}
	if(temp < ans){
		ans = temp;
		for(int i=0;i<urutan.size();i++){
			warna[urutan[i]-1] = colour[i%3];
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<warna.size();i++){
		if(i!=0)cout<<" ";
		cout<<warna[i];
	}
	cout<<endl;
}
