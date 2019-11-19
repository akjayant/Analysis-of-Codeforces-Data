#include <bits/stdc++.h>
using namespace std;
long long n,k;
struct node
{
	long long num,val;
	bool operator<(node x)const
	{
		return num>x.num;
	}
};
int a[100005],sum[100005],maxn,minn;
priority_queue<node> q1,q2;
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int las=a[1],pos=0;
	maxn=a[n],minn=a[1];
	for (int i=2;i<=n;i++)
	{
		if (a[i]!=las)
		{
			q1.push((node){i-1,a[i]-las});
			las=a[i];
		}
	}
	las=a[n];
	for (int i=n-1;i>=1;i--)
	{
		if (a[i]!=las)
		{
			q2.push((node){n-i,las-a[i]});
			las=a[i];
		}
	}
	while(k&&!q1.empty()&&!q2.empty())
	{
		if (q1.top().num>q2.top().num)
		{
			if (min(q2.top().val,k/q2.top().num)==k/q2.top().num)
			{
				minn+=k/q2.top().num;
				if (minn>=maxn)
				{
					puts("0");
					return 0;
				}
				cout<<maxn-minn<<endl;
				return 0;
			}
			minn+=min(q2.top().val,k/q2.top().num);
			k-=q2.top().num*min(q2.top().val,k/q2.top().num);
			q2.pop();
		}
		else
		{
			if (min(q1.top().val,k/q1.top().num)==k/q1.top().num)
			{
				maxn-=k/q1.top().num;
				if (minn>=maxn)
				{
					puts("0");
					return 0;
				}
				cout<<maxn-minn<<endl;
				return 0;
			}
			maxn-=min(q1.top().val,k/q1.top().num);
			k-=q1.top().num*min(q1.top().val,k/q1.top().num);
			q1.pop();
		}
		/*cout<<q1.top().num<<' '<<q1.top().val<<endl;
		cout<<q2.top().num<<' '<<q2.top().num<<endl;
		cout<<maxn<<' '<<minn<<' '<<k<<endl;*/
	}
	cout<<maxn-minn<<endl;
	return 0;
}
