#include <bits/stdc++.h>
#include <map>
#define ll long long
#define MAXN 310
#define MAXE 310
#define MOD 1000000007
using namespace std;
int bin[MAXN][MAXN];
void work(int N)
{
    int cnt=N*N;
    for(int i=1;i<=N;i++)
    {
        if(i%2)for(int j=1;j<=N;j++)bin[j][i]=cnt--;
        else
            for(int j=N;j>=1;j--)bin[j][i]=cnt--;
    }
}
int main()
{
   //freopen("testdata.in.txt","r",stdin);
   int N;
   cin>>N;
   work(N);
   for(int i=1;i<=N;i++)
   {
       for(int j=1;j<=N;j++)
   {
       if(j!=1)cout<<" ";
       cout<<bin[i][j];
   }
    puts("");
   }

   return 0;
}

