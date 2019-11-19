
#include<iostream>
 #include<bits/stdc++.h>
using namespace std;
 int a[100005];
 int b[100005];
int main()
{
    int n;
    cin>>n;
  for(int i=1;i<=n;i++)
  {
      scanf("%d",&a[i]);
  }
  sort(a+1,a+n+1);
  long long x=0;
  long long y=0;
  for(int i=1;i<=n/2;i++)
  {
      x+=a[i];
  }
  for(int i=n/2+1;i<=n;i++)
  {
      y+=a[i];
  }
  long long ans=x*x+y*y;
  cout<<ans;

	return 0;
}
