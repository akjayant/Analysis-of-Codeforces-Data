/*************************************************************************
	> File Name: 2019_10_17_3.cpp
	> Author: z472421519
	> Mail: 
	> Created Time: 2019年10月17日 星期四 21时59分44秒
 ************************************************************************/

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;

int a[400][400];
int main()
{
    int n;
    scanf("%d",&n);
    //n = n;
    for(int i = 1;i <= n;i++)
    {
        if(i % 2)
            for(int j = 1;j <= n;j++)
                a[j][i] = (i - 1) * n + j;
        else
            for(int j = 1;j <= n;j++)
                a[n - j + 1][i] = (i - 1) * n + j;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j < n;j++)
            printf("%d ",a[i][j]);
        printf("%d\n",a[i][n]);
    }
    return 0;
}
