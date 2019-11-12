#include<bits/stdc++.h>
using namespace std;
int arr[330][330];
int main(){
    int n;
    int k=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(i%2==0)for(int j=0;j<n;j++)arr[i][j]=k++;
        else for(int j=n-1;j>=0;j--)arr[i][j]=k++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%d ",arr[j][i]);
        puts("");
    }
}
