#include<iostream>
using namespace std;

typedef long long ll;
ll mod=1e9+7;
ll dpn[100005][2][2]={0},dpm[100005][2][2]={0};//2  0 ��  1�� ;3  0 ��ǰһ����ͬ  1 ��ͬ 

int main()
{
	ll n,m;
	cin>>n>>m;
	dpn[1][0][0]=0;
	dpn[1][1][0]=0;
	dpn[1][0][1]=1;
	dpn[1][1][1]=1;
	dpm[1][0][0]=0;
	dpm[1][1][0]=0;
	dpm[1][0][1]=1;
	dpm[1][1][1]=1;
	for(int i=2;i<=n;i++){
		dpn[i][0][0]=(dpn[i-1][0][1])%mod;
		dpn[i][0][1]=(dpn[i-1][1][0]+dpn[i-1][1][1])%mod;
		dpn[i][1][0]=(dpn[i-1][1][1])%mod;
		dpn[i][1][1]=(dpn[i-1][0][0]+dpn[i-1][0][1])%mod;
	}
//	ll sum1=0;
//	for(int i=0;i<2;i++){
//		for(int j=0;j<2;j++){
//			sum1=(sum1+dpn[n][i][j])%mod;
//		}
//	}
	for(int i=2;i<=m;i++){
		dpm[i][0][0]=(dpm[i-1][0][1])%mod;
		dpm[i][0][1]=(dpm[i-1][1][0]+dpm[i-1][1][1])%mod;
		dpm[i][1][0]=(dpm[i-1][1][1])%mod;
		dpm[i][1][1]=(dpm[i-1][0][0]+dpm[i-1][0][1])%mod;
	}
//	ll sum2=0;
//	for(int i=0;i<2;i++){
//		for(int j=0;j<2;j++){
//			sum2=(sum2+dpm[m][i][j])%mod;
//		}
//	}
//	cout<<sum1<<" "<<sum2<<endl;
	ll sum=0;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			sum=(sum+dpn[n][i][j]+dpm[m][i][j])%mod;
		}
	}
	cout<<(sum-2+mod)%mod<<endl;
	return 0;
}
