#include <bits/stdc++.h>
//---------------------------
using namespace std;
//---------------------------
#define REP(i,n) for(int i = 0; i < (n); i++)
#define P(x) cout << (x) << "\n"
#define fcout cout << fixed << setprecision(18)

#define MOD 1000000007 // 1e9+7
#define PI 3.1415926535
/*
3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
*/
#define ll long long int // 10^18
#define INF 1000000001 // 1e9+1
#define LINF 1000000000000000001 // 1e18+1

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
//---------------------------
int N,M,i,j,k;
string S,T;

ll gcd(ll a, ll b)
{
  for (;;)
  {
    if (a == 0) return b;
    b %= a;
    if (b == 0) return a;
    a %= b;
  }
}
ll lcm(ll a, ll b)
{
    ll temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  cin>>N>>M>>S>>T;
  ll ans = lcm(N,M);
  bool flag = gcd(N,M)>1 ? 1 : 0;
  ll g = gcd(N,M);
  ll l = lcm(N,M);
  ll ss = lcm(l/N, l/M);
  ll ln = l/N;
  ll lm = l/M;
  if(S[0]!=T[0]){
    ans=-1;//ここはOK
  }
  if(flag) {
      for(i = 0;i<l;i+=ss){
        if(S[i/ln]!=T[i/lm]){
          ans=-1;
        }
      }
  }
  // if(ans==-1){
  //   ans=lcm(M,N);
  // }else{
  //   ans=-1;
  // }
  P(ans);
  return 0;
}
