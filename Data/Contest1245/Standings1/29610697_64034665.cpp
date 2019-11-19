#include<bits/stdc++.h>
using namespace std;
double ans[2][105];
int ch,jp[105],lab[11][11];
int main()
{
	for(int i=1;i<=10;i++)
	 for(int j=1;j<=10;j++)
	 if(i&1)
	   lab[i][j]=(i-1)*10+j,cin>>ch,jp[(i-1)*10+j]=lab[i-ch][j];
	 else
	   lab[i][j]=(i-1)*10+11-j,cin>>ch,jp[(i-1)*10+11-j]=lab[i-ch][j];
	ans[0][2]=(double)6;
	ans[0][3]=(1+ans[0][2]/6)*3;
	ans[0][4]=(1+ans[0][2]/6+ans[0][3]/6)*2;
	ans[0][5]=(1+ans[0][2]/6+ans[0][3]/6+ans[0][4]/6)/2*3;
	ans[0][6]=(1+ans[0][2]/6+ans[0][3]/6+ans[0][4]/6+ans[0][5]/6)/5*6;
	ans[0][7]=(1+ans[0][2]/6+ans[0][3]/6+ans[0][4]/6+ans[0][5]/6+ans[0][6]/6);
	ans[1][2]=ans[0][2];
	ans[1][3]=ans[0][3];
	ans[1][4]=ans[0][4];
	ans[1][5]=ans[0][5];
	ans[1][6]=ans[0][6];
	ans[1][7]=ans[0][7];
	for(int i=8;i<=100;i++)
	 {
	 ans[0][i]=(double)1+ans[1][i-5]/6+ans[1][i-1]/6+ans[1][i-2]/6+ans[1][i-3]/6+ans[1][i-4]/6+ans[1][i-6]/6;
     if(jp[i])ans[1][i]=min(ans[0][i],ans[0][jp[i]]);else ans[1][i]=ans[0][i];
	 }
	printf("%.10f",ans[1][100]);
	return 0;
}