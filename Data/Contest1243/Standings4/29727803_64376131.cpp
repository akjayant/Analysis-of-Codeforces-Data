#include <iostream>
#include <bits/stdc++.h>
#define forn(i,n)for(int i=0;i<n;i++)
#define forna(i,a,n)for(int i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define maap map<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1e9+7
#define ff first
#define ss second
#define INF 1e11
#define MAX 1e6+1
typedef long long ll;
using namespace std;


int main()
{
    int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int arr[n];
		forn(i,n) cin>>arr[i];
		sort(arr,arr+n);
		//int f=0;
		forn(i,n){
			if(arr[i]>= n-i){
				cout<<n-i<<endl;break;
			}
		}

	}
}


