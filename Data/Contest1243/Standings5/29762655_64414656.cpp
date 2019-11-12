#include<bits/stdc++.h>
using namespace std;
int t;
int check[101];
int main(){
    scanf("%d",&t);
    char arr[101],brr[101];
    while(t--){
        int n;
        fill(check,check+30,0);
        scanf("%d",&n);
        scanf("%s%s",arr,brr);
        for(int i=0;i<n;i++){
            check[arr[i]-'a']++;
            check[brr[i]-'a']++;
        }
        int flag=1;
        for(int i=0;i<30;i++){
            if(check[i]%2){
                puts("No");
                flag=0;
                break;
            }
        }
        if(flag){
            puts("Yes");
            int cnt=0;
            vector <pair<int,int> > opV;
            for(int i=0;i<n;i++){
                if(arr[i]!=brr[i]){
            int fl=1;
                for(int j=i+1;j<n;j++){
                    if(arr[i]==arr[j]){
                        cnt++;
                        opV.push_back({j+1,i+1});
                        swap(arr[j],brr[i]);
                        fl=0;
                        break;
                    }
                }
                if(fl){
                for(int j=i+1;j<n;j++){
                    if(brr[i]==brr[j]){
                        cnt++;
                        opV.push_back({i+1,j+1});
                        swap(arr[i],brr[j]);
                        fl=0;
                        break;
                    }
                }
                }
                if(fl){
                        cnt++;
                        opV.push_back({i+1,i+1});
                    swap(arr[i],brr[i]);
                for(int j=i+1;j<n;j++){
                    if(arr[i]==arr[j]){
                        cnt++;
                        opV.push_back({j+1,i+1});
                        swap(arr[j],brr[i]);
                        fl=0;
                        break;
                    }
                }
                if(fl){
                for(int j=i+1;j<n;j++){
                    if(brr[i]==brr[j]){
                        cnt++;
                        opV.push_back({i+1,j+1});
                        swap(arr[i],brr[j]);
                        fl=0;
                        break;
                    }
                }
                }
                }
            }
        }
            printf("%d\n",cnt);
            for(int i=0;i<cnt;i++)printf("%d %d\n",opV[i].first,opV[i].second);
    }
    }
}

