#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int maxn = 1e3 + 5 ;
int n ;
int a[maxn] ;
int main()
{
	int t ;
	scanf("%d" , &t) ;
	while(t --)
	{
		scanf("%d" , &n) ;
		for(int i = 1 ; i <= n ; i ++)
		  scanf("%d" , &a[i]) ;
		sort(a + 1 , a + n + 1) ;
		int ans = 0 ;
		for(int i = 1 ; i <= n ; i ++)
		  ans = max(ans , min(a[i] , n + 1 - i)) ;
		printf("%d\n" , ans) ;
	}
}