#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1005 ;

int n ;
int arr[MAX] ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin>>t ;
	while(t--)
	{
		cin>>n ;
		for(int i = 0 ; i < n ; ++i)
			cin>>arr[i] ;
		for(int i = 1000 ; i >= 1 ; --i)
		{
			int cnt = 0 ;
			for(int j = 0 ; j < n ; ++j)
			{
				if(arr[j] >= i)
					cnt++ ;
			}
			if(cnt >= i)
			{
				cout<<i<<"\n" ;
				break ;
			}
		}
	}
	return 0 ;
}