
#include<iostream>
 #include<bits/stdc++.h>
using namespace std;
 int a[100005];
 int b[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long j1=0,j2=0;
       long long o1=0,o2=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
           {
               scanf("%d",&a[i]);
               if(a[i]%2==0)
                o1++;
               else
                j1++;
           }
        int m;
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&b[i]);
             if(b[i]%2==0)
                o2++;
               else
                j2++;
        }
        long long ans=o1*o2+j1*j2;
        cout<<ans<<endl;

    }

	return 0;
}
