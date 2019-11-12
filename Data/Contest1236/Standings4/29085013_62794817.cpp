#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mod 1000000007LL
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
int arr[310][310];
int main()
{
    int n, x=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        if(i%2)for(int j=1; j<=n; j++)arr[j][i]=++x;
        else for(int j=n; j>=1; j--)arr[j][i]=++x;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
}
