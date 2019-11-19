#include<bits/stdc++.h>
#include<iostream>
#define mylonglongint long long
using namespace std;
void adfljeoif(){
	printf("alfiejfoefjweofjwf\n");
}
void afiejfolefkjiefe()
{
	printf("foeifjeoijfoewjfiewfj\n");
}
void fvaewifjoejm()
{
	printf("oiefmfoiefjew\n");
}
void pojefijefief()
{
	printf("jfoeijfoefj\n");
}
mylonglongint gcd(mylonglongint a,mylonglongint b){
	while(a>0 && b>0){
		if(a>b)
			a%=b;
		else
			b%=a;
	}
	return (a+b);
}
int main()
{
	mylonglongint n;
	cin >> n;
	mylonglongint g=0;
	mylonglongint i,j;
	bool flag=true;
	for(i=2;i<=(sqrt(n));i++){
		if(n%i==0){
			g=gcd(g,i);
			g=gcd(g,n/i);
			flag=false;
		}
	}
	if(flag)
		g=n;
	cout << g << endl;

}