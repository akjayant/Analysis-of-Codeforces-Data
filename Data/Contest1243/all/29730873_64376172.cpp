#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int G=1e9+7;
const int NN=50005;
int n,m,k,x,y,cnt,val,num,tmp,Max;
//vector<Edge> ve[NN];
int dis[NN],inque[NN],b[NN];


int main(){
	ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		cin>>n;Max=0;
		for(int i=1;i<=n;i++) b[i]=0;
		for(int i=1;i<=n;i++){
			cin>>tmp;
			for(int i=1;i<=tmp;i++){
				b[i]++;
				if(b[i]>=i){
					Max=max(i,Max);
				}
			}
		}
		cout<<Max<<endl;
	}
}


