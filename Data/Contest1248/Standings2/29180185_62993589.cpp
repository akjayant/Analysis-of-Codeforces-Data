#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n;
char s[N];

void check() 
{
	int cnt1 = 0 , cnt2 = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(s[i] == '(') cnt1++;
		if(s[i] == ')') cnt2++;
	}
	if(cnt1 != cnt2)
	{
		puts("0");
		puts("1 1");
		exit(0);
	}
}

int dp[N] , top;

int calc()
{
	top = 0;
	int ans = 0 , x = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(s[i] == '(') top++;
		else top--;
		
		dp[i] = top;
		x = min(x , top);
	}
	for(int i = 1 ; i <= n ; i ++)
		if(dp[i] == x) ans ++;
	return ans;
}

int val , l = 1 , r = 1;

int main()
{
	scanf("%d" , &n);
	scanf("%s" , s + 1);
	check();
	val = calc();
	for(int i = 1 ; i <= n ; i ++)
		for(int j = i + 1 ; j <= n ; j ++)
		{
			if(s[i] == s[j]) continue;
			
			swap(s[i] , s[j]);
			int temp = calc();
			if(temp > val)
			{
				val = temp ;
				l = i , r = j;
			}
			swap(s[i] , s[j]);
		}
	printf("%d\n%d %d" , val , l , r);
}
