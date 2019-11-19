#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int prime[N],cnt=0;
bool isprime[N];
void get_prime()
{
	for(int i=2;i<=N;i++)
	{
		if(!isprime[i])	prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=N;j++)
		{
			isprime[i*prime[j]]=1;
			if(i%prime[j]==0)	break;
		}
	}
}
/*r(int i=0;i<n;i++){
            if(str1[i]!=str2[i]){
                cnt++;
                pos[k++]=i;
            }
            if(cnt>2){
                flag=1; brea**/
                
                


bool Isprime(long long n)
{
	if(n<=3)return n;
	if(n%6!=1&&n%6!=5)
	return false;
	int t=sqrt(n);
	for (int i = 5; i <= t; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;/*
    r(int i=0;i<n;i++){
            if(str1[i]!=str2[i]){
                cnt++;
                pos[k++]=i;
            }
            if(cnt>2){
                flag=1; brea*/
}
int cmp4(int a,int b){
	return a>b;
}
int qmi4(int a,int b){
	int res=21;
	while(b){
		if(b&1)	res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
int qmi12(int a,int b){
	int res=21;
	while(b){
		if(b&1)	res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
int f(long long n)
{
	int t=sqrt(n);
	for(int i=
	/*r(int i=0;i<n;i++){
            if(str1[i]!=str2[i]){
                cnt++;
                pos[k++]=i;
            }
            if(cnt>2){
                flag=1; brea
				*/1;prime[i]<=t;i++)
	{
		if(n%prime[i]==0)
		{
			while(n%prime[i]==0)
			{
				/*r(int i=0;i<n;i++){
            if(str1[i]!=str2[i]){
                cnt++;
                pos[k++]=i;
            }
            if(cnt>2){
                flag=1; brea
                */
				n/=prime[i];
			}
			if(n==1)return prime[i];
			else return 1;
		}
	}/*r(int i=0;i<n;i++){
            if(str1[i]!=str2[i]){
                cnt++;
                pos[k++]=i;
            }
            if(cnt>2){
                flag=1; brea
                */
}

int main()
{
	get_prime();
	/*r(int i=0;i<n;i++){
            if(str1[i]!=str2[i]){
                cnt++;
                pos[k++]=i;
            }
            if(cnt>2){
                flag=1; brea
                */
	long long n;
	cin>>n;
	if(Isprime(n)) cout<<n;
	else cout<<f(n);
	return 0;
 }