#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int ans[310][310];

int main()
{
    int i, j;

    scanf("%d", &N);
    int cnt=1;
    for(i=1; i<=N; i++)
    {
        if(i%2) for(j=1; j<=N; j++) ans[i][j]=cnt++;
        else for(j=N; j>=1; j--) ans[i][j]=cnt++;
    }
    for(i=1; i<=N; i++) { for(j=1; j<=N; j++) printf("%d ", ans[j][i]); printf("\n"); }
}
