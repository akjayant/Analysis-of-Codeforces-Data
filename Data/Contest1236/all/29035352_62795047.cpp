#include<bits/stdc++.h>

using namespace std;
#define debug(x) cout<<#x<<" is "<<x<<endl;
typedef long long ll;

const ll mod=1e9+7;
const int maxn=305;

int a[maxn][maxn],b[maxn];

int main(){
    int n;
    scanf("%d",&n);
    int odd=0;
    int w=1;
    for(int i=1;i<=n*n;i++){
        a[w][++b[w]]=i;
        if(odd%2==0){
            w++;
            if(w>n){
                w=n;
                odd++;
            }
        }
        else{
            w--;
            if(w<1){
                w=1;
                odd++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d",a[i][j]);
            char cc=(j==n)?'\n':' ';
            printf("%c",cc);
        }
    }
    return 0;
}
