#include <iostream>
#define MAX 310

using namespace std;

int n;
int a[MAX][MAX];

int main()
{
    cin>>n;
    for(int i=1,na=1;i<=n;i++){
      int ji,s;
      if(i%2)ji=1,s=1; else ji=n,s=-1;
      for(int j=ji;j>=1&&j<=n;j+=s,na++)
        a[j][i]=na;
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
      cout<<'\n';
    }
    return 0;
}
