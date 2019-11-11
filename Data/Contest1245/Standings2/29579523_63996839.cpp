#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
const double pi = acos(-1.0);

// w ,

int gcd(int a,int b){
  return b == 0?a:gcd(b,a%b);
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int a,b;
    scanf("%d %d",&a,&b);
    int g = gcd(a,b);
    cout<<(g != 1?"Infinite":"Finite")<<endl;
  }
  return 0;
}
