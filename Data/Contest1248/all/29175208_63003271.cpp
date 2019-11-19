#include <bits/stdc++.h>
using namespace std;
const int N = 1234567;
int n,sum[N];
pair <int,int> q[N];
int f(string s)
{
	int ret = 0, tag = 0;
	for(int i = 1;i <= 2 * n - 1;i++)
		sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
//	for(int i = 1;i <= n;i++)
//		cout << s[i];
//	cout << endl;
	if(sum[n] != 0)
		return 0;
	int head = 1,tail = 0;
	for(int i = 1;i <= n;i++)
	{
		while(head <= tail && q[tail].first >= sum[i])
			tail--;
		q[++tail] = make_pair(sum[i],i);
	}
//	for(int i = 1;i <= n;i++)
//		cout << sum[i] << " ";
//	cout << endl;
//	cout << "q : " << q[head].first << " " << q[head].second << endl;
	if(q[head].first >= 0)
		ret++;
	for(int i = n + 1;i <= 2 * n - 1;i++)
	{
		while(head <= tail && i - q[head].second >= n)
			head++;
		while(head <= tail && q[tail].first >= sum[i])
			tail--;
//		if(i - n + 1 == 4)
//			cout << s[i - n] << endl;
		tag += (s[i - n] == '(' ? -1 : 1);
//		cout << "tag : " << i - n + 1 << " " << tag << endl;
		if(q[head].first + tag >= 0)
		{
//			cout << i - n + 1 << " " << head << " " << q[head].first << " " << q[head].second << " " << tag << endl;
			ret++;
		}
		q[++tail] = make_pair(sum[i],i);
	}
	return ret;
}
string s;
int ans,ansi = 1,ansj = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	s = " " + s + s;
	for(int i = 1;i <= n;i++)
		for(int j = i;j <= n;j++)
		{
			swap(s[i],s[j]),swap(s[i + n],s[j + n]);
			int x = f(s);
			if(x >= ans)
			{
				ans = x;
				ansi = i,ansj = j;
			}
			swap(s[i],s[j]),swap(s[i + n],s[j + n]);
		}
	cout << ans << endl;
	cout << ansi << " " << ansj << endl;
	return 0;
}