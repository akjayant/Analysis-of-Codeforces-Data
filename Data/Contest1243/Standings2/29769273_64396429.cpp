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
	string a,b;
	cin>>n>>a>>b;
	int i=0;
	vector<pair<int,int>> v;
	while(i<n-1 && v.size()<2*n){
		if(a[i] == b[i]){
			++i;
			continue;
		}
		bool f = false;
		for(int j=i+1;j<n && !f;j++){
			if(b[j] == b[i]){
				b[j] = a[i];
				a[i] = b[i];
				f = true;
				v.pb(mp(i+1,j+1));
				++i;
				break;
			}
		}
		for(int j=i+1;j<n && !f;j++){
			if(a[j] == a[i]){
				a[j] = b[i];
				b[i] = a[i];
				f = true;
				v.pb(mp(j+1,i+1));
				++i;
				break;
			}
		}
		for(int j=i+1;j<n && !f;j++){
			if(a[j] == b[i]){
				//bring a[j] to b[j]
				char t = a[j];
				a[j] = b[j];
				b[j] = t;
				f = true;
				v.pb(mp(j+1,j+1));
				break;
			}
		}
		for(int j=i+1;j<n && !f;j++){
			if(b[j] == a[i]){
				//swap b[j] and b[i]
				char t = b[j];
				b[j] = b[i];
				b[i] = t;
				f = true;
				v.pb(mp(j+1,j+1));
				break;
			}
		}
		if(!f){
			cout<<"No"<<endl;
			return;
		}
	}

	if(a == b){
		cout<<"Yes"<<endl;
		if(v.size() == 0){
			cout<<1<<endl<<1<<' '<<1<<endl;
		}
		else{
			cout<<v.size()<<endl;
			for(int i=0;i<v.size();i++)
				cout<<v[i].first<<' '<<v[i].second<<endl;
		}
	}
	else
		cout<<"No"<<endl;
}

int main(){
	ios;
	cin>>t;
	for(int i=1;i<=t;i++)
//		cout<<"Case #"<<i<<": ", run();
	run();
	return 0;
}

/*
 *
 * abc
 * bca
 *
 * cbc
 * baa
 *
 * cbb
 * caa
 *
 * cba
 * cba
 *
 *
 */



