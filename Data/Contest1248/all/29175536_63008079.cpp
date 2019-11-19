#include<iostream>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
LL poww(LL x, LL n)///快速幂
{
    LL res = 1;
    while(n)
    {
        if(n & 1) res =res*x%MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}
///组合数模板
LL p[100005],f[100005];///p为阶乘数组，f为阶乘的逆元
void init()///预处理
{
    p[0]=1;
    for (int i=1;i<=100001;++i)///计算阶乘
        p[i]=p[i-1]*i%MOD;
    f[0]=1;
    for (int i=1;i<=100001;++i)///计算逆元
        f[i]=poww(p[i],MOD-2);
    return ;
}
LL comb(int n,int m)///计算组合数
{
    return (f[m]*f[n-m])%MOD*p[n]%MOD;
}
LL ans,n,m;
int main(){
	init();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		if(n-i>=i)
			ans+=( comb(n-i,i) );
		else
			;
		ans%=MOD;
	}
	for(int i=1;i<=m;i++){
		if(m-i>=i)
		ans+=(comb(m-i,i));
		else
			;
		ans%=MOD;
	}
	cout<<((2ll*ans)+2ll)%MOD<<endl;
	return 0;	
}