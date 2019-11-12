#include<bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(0);std::cout.tie(0);
#define endl "\n" 
#define FOR(I,N,X) for(int i=I;i<N;i+=X)
#define gcd __gcd 
#define pb push_back 
typedef int itn;
typedef long long  ll;
typedef unsigned long long  ull;
using namespace std;
const ll mod=1000000007;
ll n,m;
vector<int>a[300];

int main(){
	IOS;
    cin>>n;
    int m=(n*n);
    int i=0;
    int f=1;
    for (int j=1;j<=m;j++){
        a[i].push_back(j);
        i+=f;
        if(i==(n)){
            f=-1;
            i--;
        }else if(i==(-1)){
            f=1;
            i++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}