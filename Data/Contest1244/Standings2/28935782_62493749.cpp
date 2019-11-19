/* LittleFall : Hello! */
#include <bits/stdc++.h>
using namespace std; using ll = long long; inline ll read();
const int M = 100016, MOD = 1000000007;

ll n, k, save[M], sum[M];
ll binary_upp(ll can) //使用can，能降到最小的上边界
{
	ll lef = save[1], rig = save[n], ans = rig;
	while(lef<=rig)
	{
		ll mid = (lef+rig)>>1;
		//能否降到mid
		int id = lower_bound(save+1, save+n+1, mid)-save; //第一个大于等于mid的下标
		ll need = (sum[n] - sum[id-1]) - mid*(n-id+1);
		if(can>=need)
		{
			ans = mid;
			rig = mid-1;
		}
		else
		{
			lef = mid+1;
		}
	}
	return ans;
}
ll binary_low(ll can) //能加到最大的下边界
{
	ll lef = save[1], rig = save[n], ans = lef;
	while(lef<=rig)
	{
		ll mid = (lef+rig)>>1;
		//能否降到mid
		int id = lower_bound(save+1, save+n+1, mid)-save; //第一个大于等于mid的下标
		ll need = mid*(id-1) - sum[id-1];
		if(can>=need)
		{
			ans = mid;
			lef = mid+1;
		}
		else
		{
			rig = mid-1;
		}
	}
	return ans;
}
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
    #endif

	n = read(), k = read();
	for(int i=1; i<=n; ++i)
		save[i] = read();
	sort(save+1, save+n+1);
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + save[i];

	ll ans = save[n]-save[1];

	ll cost = 0;
	for(int i=1; i<=n; ++i) //以i为下界
	{
		cost += (save[i]-save[i-1])*(i-1);
		if(cost>k) break;
		ll upp = binary_upp(k-cost);
		if(upp<=save[i])
		{
			//printf("?\n");
			ans = 0;
			break;
		}
		ans = min(ans, upp-save[i]);
	}

	cost = 0;
	for(int i=n; i>=1; --i) //以i为上界
	{
		cost += (save[i+1]-save[i])*(n-i);
		if(cost>k) break;
		ll low = binary_low(k-cost);
		//printf("i=%d can=%I64d low=%I64d\n",i,k-cost,low );
		if(low>=save[i])
		{
		//	printf("i=%d ??\n",i );
			ans = 0;
			break;
		}
		ans = min(ans, save[i]-low);
	}
	cout << ans << endl;

    return 0;
}
	

inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}