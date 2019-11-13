#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ld long double
#define endl "\n"
#define ld long double
#define ff first
#define ss second
#define pi pair<float,int> 
#define PI 3.141592653589793238462643383279502884L
#define mp make_pair
#define pb push_back
#define forall(i,n) for(int i=0;i<n;i++)
ll mod = 998244353;
ll mod1 = 1e9 + 7;
const int N= 1e5+5;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	
	cin>>n;
	int a[n][n];
	int c=1;
	for(int j=0;j<n;j++){
		if(j%2==0){
		for(int i=0;i<n;i++){
			a[i][j]=c,	c++;
		}
		}else{
			for(int i=n-1;i>=0;i--)
			a[i][j]=c,c++;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}