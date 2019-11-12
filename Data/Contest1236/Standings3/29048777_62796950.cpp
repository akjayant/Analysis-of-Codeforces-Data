#include<bits/stdc++.h>

using namespace std;
int b[301][301];
int main()
{
    int n,i,j,x=1;
    cin>>n;
    for(j=0;j<n;j++)
    {
        if(j%2==0){
            for(i=0;i<n;i++)
                b[i][j]=x++;
        }
        else{
            for(i=n-1;i>=0;i--)
                b[i][j]=x++;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<b[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
