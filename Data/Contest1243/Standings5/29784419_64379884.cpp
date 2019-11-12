#include<bits/stdc++.h>
#define ll long long
using namespace std;

int number[1010];

int main() {
    int k; scanf("%d",&k);
    while(k--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&number[i]);
        }
        for(int mm=1000;mm>=0;mm--){
            int num=0;
            for(int i=1;i<=n;i++){
                if(number[i]>=mm) num++;
            }
            if(num>=mm){
                printf("%d\n",mm); break;
            } 
        }
    }
    return 0;
}