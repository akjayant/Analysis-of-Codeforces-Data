#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long cnt1=0;
	long long cnt2=0;
	if(n&1) cnt1=a[n--];
	for(int i=n;i>n/2;i--)
	{
		cnt1+=a[i];
		cnt2+=a[n-i+1];
	}
	cout<<(cnt1*cnt1+cnt2*cnt2)<<endl;
	return 0;
} 