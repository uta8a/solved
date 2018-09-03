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
int pow2(int i){
  int res=1;
  while(i>0){
    res*=2;
    i--;
  }
  return res;
}
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  int l;cin>>l;
  int s=1;
  int c=0;
  while(s - l <= 0){
    s*=2;
    c++;
  }
  c++;
  cout<<c<<" "<<2*(c-1)<<"\n";
  for(int i=1;i<c;i++){
    cout<<i<<" "<<i+1<<" "<<0<<"\n";
  }
  // int p =c-1;
  ll sm=0;
  for(int i=1;i<c-1;i++){
    cout<<i<<" "<<i+1<<" "<<pow2(i-1)<<"\n";
    sm+=pow2(i-1);
  }
  cout<<1<<" "<<2<<" "<<l - sm<<"\n";

  return 0;
}
