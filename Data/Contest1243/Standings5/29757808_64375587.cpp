#include<bits/stdc++.h> 
using namespace std;
int mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,j,n;
    int k;
    cin>>k;
    while(k>0)
    {
        cin>>n;
        vector<int> a(n);
        for(i=0;i<n;i++)
            cin>>a[i];
        int ans=1;
        for(i=1;i<=n;i++)
        {
            int count=0;
            for(j=0;j<n;j++)
            {
                if(a[j]>=i)
                    count+=1;
                if(count>=i)
                    break;
            }
            if(count>=i)
            {
                if(i>ans)
                    ans=i;
            }
        }

        cout<<ans<<endl;
        k--;
    }   
}