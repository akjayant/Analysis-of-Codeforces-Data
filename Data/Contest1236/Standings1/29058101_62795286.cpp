#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100010];
int main(){
    int n;
    while(cin>>n){
        ll ans=0;
        if(n%2==0){
            int m=n*n, tmp=1;
            for(int i=0; i<n; ++i){
                for(int j=0; j<n/2; ++j){
                    printf("%d %d ",m, tmp);
                    --m;
                    ++tmp;
                }
                printf("\n");
            }
        }
        else{
            bool l=1;
            int m=n*n, tmp=1, tmp1=n/2*n+1;
            for(int i=0; i<n; ++i){
                for(int j=0; j<n/2; ++j){
                    printf("%d %d ",m, tmp);
                    --m;
                    ++tmp;
                }
                printf("%d ", tmp1);
                ++tmp1;
                printf("\n");
            }
        }

    }
  return 0;
}


