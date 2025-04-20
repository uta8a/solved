/* https://beta.atcoder.jp/contests/summerfes2018-div1/submissions/3071681 参考 */
#include <bits/stdc++.h>
using namespace std;

map<long long, int> prime_factor(long long n) {
  // whileでnからiがなくなるまで割っているので、res[i]には素数iの指数が入る
  map<long long, int> res;
  for(long long i=2;i*i<=n;i++){
    while(n%i==0){
      ++res[i];
      n/=i;
    }
  }
  if(n!=1)res[n]=1;
  return res;
}

long long totient(long long mod) {
  map<long long, int> pf = prime_factor(mod);
  long long res = 1;
  for(auto& p:pf){
    long long tmp = 1;
    for(int i=0;i<p.second - 1;i++){
      tmp*=p.first;
    }
    res*=tmp*(p.first - 1);
  }
  return res;
}

long long modpow(long long x, long long n,long long mod) {
  if(x==0)return 0;
  long long res = 1;
  while(n>0){
    if(n&1)res=res*x%mod;
    x = x*x%mod;
    n>>=1;
  }
  return res;
}

long long tetration(long long x, long long n, long long mod){
  if(mod==1)return 0;
  if(n==0)return 1;
  long long n2 = tetration(x, n-1, totient(mod));
  return modpow(x%mod, (n2 == 0 ? mod : n2), mod);
}
