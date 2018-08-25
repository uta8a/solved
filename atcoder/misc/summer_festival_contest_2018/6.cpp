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
ll calc(int a,int b,int p){
  if(b==0){
    return 1;
  }else if(b%2==0){
    ll d=calc(a,b/2,p);
    return (d*d)%p;
  }else if(b%2==1){
    return (a*calc(a,b-1,p))%p;
  }
}
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());

  ll a,m,k;cin>>a>>m>>k;
  bool flag=true;
  ll cur=1;
  ll index=0;
  ll cnt=0;
  while(flag){
    ll now=cur;
    cur=calc(a,cur%(m-1),m);
    P(cur);
    if(now==cur)break;
    index++;
    cnt+=cur;
    cnt%=MOD;
  }
  return 0;
}
