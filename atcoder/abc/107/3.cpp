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
ll x[200000];
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  int n,k;cin>>n>>k;
  bool flag=true;
  int index=n,left_k,right_k;
  REP(i,n){
    cin>>x[i];
    if(x[i]>=0 && flag){
      index=i;
      flag=false;
    }
  }
  if(index==n){
    P(-x[n-k]);
    return 0;
  }
  if(index==0){
    P(x[k-1]);
    return 0;
  }
  left_k = index - k;
  right_k = index + k - 1;
  if(left_k<0)left_k=0;
  if(right_k>=n)right_k=n-1;
  ll mn=LINF;
  for(int i=left_k;i<=index;i++){//start地点
    if(i+k-1>n-1)continue;
    int sg=1,sgg=1;
    if(x[i]<0)sg=-1;
    if(x[i+k-1]<0)sgg=-1;
    mn=min(mn,min(x[i+k-1] - x[i] + sg*x[i], x[i+k-1] - x[i] + sgg*x[i+k-1]));
    // P(x[i+k-1] - x[i] + sg*x[i]);
    // P(x[i+k-1] - x[i] + sgg*x[i+k-1]);
  }
  P(mn);
  return 0;
}
