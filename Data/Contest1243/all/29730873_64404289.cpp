#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int G=1e9+7;
const int NN=1000005;
ll n,m,k,x,y,cnt,val,num,tmp,Max;
//vector<Edge> ve[NN];
int a[NN];
ll p[100100];
string s,s2;


int main(){
	ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
	for(ll i=2;i<=NN-4;i++)
	{
		if(!a[i]) p[++num]=i;
		for(int j=1;j<=num;j++){
			if(i*p[j]<=NN-4) a[i*p[j]]=1;
			else break;
		}
	}
	//for(int i=1;i<=num;i++) cout<<p[i]<<' ';
	//int T;cin>>T;
	while(cin>>n){
		ll flag=-1;
		for(int i=1;i<=num&&p[i]<=sqrt(n);i++){
			if(n%p[i]==0){
				while(n%p[i]==0){
					n/=p[i];
				}
				if(n!=1) flag=0;
				else flag=p[i];
				break;
			}
		}
		if(flag==-1) cout<<n<<endl;
		else if(flag==0) cout<<1<<endl;
		else cout<<flag<<endl;
	}
}


