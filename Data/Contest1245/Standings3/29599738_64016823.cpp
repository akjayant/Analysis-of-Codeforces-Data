#include "algorithm"
#include "iostream"
#include "string"

#define mod 1000000007

int64_t Pow(int64_t x,int64_t y)
{
    int64_t t=1;
    while(y != 0)
    {
    if(y % 2 == 1)
      t=t * x % mod;
    x = x * x % mod;
    y /= 2;
    }
    return t;
}
int64_t fuck[111111];
int64_t shit[111111];
int n;
int64_t Init()
{
    int i;
    fuck[0]=1;
    shit[0]=1;
    for(i=1;i<=100000;i++)
    {
        fuck[i] = fuck[i - 1] * (int64_t)i%mod;
        shit[i] = Pow(fuck[i], mod-2);
    }
}


int64_t Calc(int len)
{
    if(len == 0 || len == 1)
    return 1;
    int i;
    int64_t ret = 0;
    for(i = 0; i <= len; i++)
    {
        int d = len - i;
        if(d < i)
          break;
        if(i==0)
          ret+=1;
        else
          ret = (ret + (fuck[d]*shit[i]%mod)*shit[d-i])%mod;
    }
    return ret;
}
int main()
{
    Init();
    std::string input;
    std::cin >> input;
    n = input.size();
    bool zero = false;
    int64_t ans = 1;
    int ulen = 0;
    int nlen = 0;
    for (int i = 0; i < n; ++i)
    {
      if (input[i] == 'm' || input[i] == 'w')
      {
          zero=true;
          break;
      }
      if (input[i] == 'u')
      {
          ulen++;
          ans *= Calc(nlen);
          ans %= mod;
          nlen = 0;
      }
      else if (input[i] == 'n')
      {
          nlen++;
          ans *= Calc(ulen);
          ans %= mod;
          ulen = 0;
      }
      else
      {
          ans *= Calc(ulen);
          ans %= mod;
          ulen = 0;
          ans *= Calc(nlen);
          ans %= mod;
          nlen = 0;
      }
    }
    ans *= Calc(ulen);
    ans %= mod;
    ulen = 0;
    ans *= Calc(nlen);
    ans %= mod;
    nlen = 0;

    if (zero) ans = 0;
    std::cout << ans << std::endl;
    return 0;
}
