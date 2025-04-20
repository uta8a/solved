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
int N,i;
int64_t h[110],x[110],y[110];
int cx,cy;
int64_t memo=-1,H;
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  cin>>N;
  for(i=0;i<N;i++){
    cin>>x[i]>>y[i]>>h[i];
  }

  for(cx=0;cx<=100;cx++){
    for(cy=0;cy<=100;cy++){
      memo=-1;
      for(i=0;i<N;i++){
        if(h[i]==0)continue;
        H=abs(x[i]-cx) + abs(y[i]-cy) + h[i];// 1以上
        if(memo==-1){
          memo=H;
        }else{
          if(memo!=H){
            goto E;
          }
        }
      }
      memo=H;
      for(i=0;i<N;i++){
        if(h[i]!=0)continue;
        if(H - abs(x[i]-cx) - abs(y[i]-cy) < 0)continue;
        H=abs(x[i]-cx) + abs(y[i]-cy) + h[i];
        if(memo!=H){
          goto E;
        }
      }
      cout << cx <<" "<< cy <<" "<< H <<endl;
      return 0;
      E:;
    }
  }
  return 0;
}
