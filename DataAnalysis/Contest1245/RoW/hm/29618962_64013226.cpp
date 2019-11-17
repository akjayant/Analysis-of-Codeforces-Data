using namespace std ;
long long z = 1000000007 ;



int main()
{
 long long arr[100001] ;
 arr[0] = 0 , arr[1] = 1 , arr[2] = 2 ;
 for(long long i = 3 ; i < 100001 ; i++)
 {
  arr[i] = (arr[i-1] + arr[i-2])%z ;
 }
 string s ;
 long long ans = 1 ;
 cin >> s ;
 int flag = 1 ;
 long long cnt = 0 ;
 char curr ;
 for(long long i = 0 ; i < s.size() ; i++)
 {
  if(s[i] == 'w' || s[i] == 'm')
   ans = 0 ;
  else
  {
   if(s[i] == 'n' || s[i] == 'u')
   {
    cnt = 1 ;
    curr = s[i] ;
    i++ ;
    while(s[i] == curr)
    {
     cnt ++ ;
     i++ ;
    }
    i-- ;
    ans *= (arr[cnt]) ;
    ans %= z ;
   }
  }

 }
 cout << ans << endl ;
 return 0;
}
