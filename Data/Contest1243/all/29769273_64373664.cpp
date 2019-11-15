#include <bits/stdc++.h>
#include <malloc.h>

using namespace std;

#define ll				long long
#define double			long double
#define pb 				push_back
#define endl 			'\n'
#define F				first
#define S				second
#define mod				(int)1000000007
#define mp              make_pair
#define lb				lower_bound
#define ub				upper_bound
#define ios 			ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf				1e9
#define mem(a,x)		for(int i=0;i<(int)(sizeof(a)/sizeof(a[0]));i++) a[i] = x;
#define trace(a)		cout<<(#a)<<" --> "<<a<<endl
#define trace2(a,b)		{trace(a);trace(b);}
#define trace3(a,b,c)	{trace(a);trace(b);trace(c);}
#define trace4(a,b,c,d) {trace(a);trace(b);trace(c);trace(d);}
#define M_PI           	3.14159265358979323846


//int pow(int n, int p){
//	int s = 1;
//	while(p>0){
//		if(p%2)
//			s*=n;
//		p/=2;
//		n*=n;
//	}
//	return s;
//}
//
//void buildsparse(int row){
//	for(int i=0;i<c;i++)
//		min_sparse[i][0] = max_sparse[i][0] = i;
//	for(int j=1;j<=log2(c);j++){
//		for(int i=0;i+pow(2,j)-1<c;i++){
//			if(a[row][min_sparse[i][j-1]]<a[row][min_sparse[i+pow(2,j-1)][j-1]])
//				min_sparse[i][j] = min_sparse[i][j-1];
//			else
//				min_sparse[i][j] = min_sparse[i+pow(2,j-1)][j-1];
//		}
//	}
//	for(int j=1;j<=log2(c);j++){
//		for(int i=0;i+pow(2,j)-1<c;i++){
//			if(a[row][max_sparse[i][j-1]]>a[row][max_sparse[i+pow(2,j-1)][j-1]])
//				max_sparse[i][j] = max_sparse[i][j-1];
//			else
//				max_sparse[i][j] = max_sparse[i+pow(2,j-1)][j-1];
//		}
//	}
//}
//
//int min_query(int row, int lo, int hi){
//	int l = hi-lo+1;
//	int k = log2(l);
//	return min(a[row][min_sparse[lo][k]], a[row][min_sparse[lo+l-pow(2,k)][k]]);
//}
//
//int max_query(int row, int lo, int hi){
//	int l = hi-lo+1;
//	int k = log2(l);
//	return max(a[row][max_sparse[lo][k]], a[row][max_sparse[lo+l-pow(2,k)][k]]);
//}

int t;


void run(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans = 1;
	for(int i=1000;i>=1;i--){
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(a[j]>=i)
				cnt++;
		}
		if(cnt >= i){
			ans = i;
			break;
		}
	}
	cout<<ans<<endl;
}

int main(){
	ios;
	cin>>t;
	for(int i=1;i<=t;i++)
//		cout<<"Case #"<<i<<": ", run();
	run();
	return 0;
}




