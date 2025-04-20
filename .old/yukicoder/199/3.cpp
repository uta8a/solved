#include <bits/stdc++.h>
//---------------------------
using namespace std;
//---------------------------
#define REP(i, n) for (int i = 0; i < (n); i++)
#define P(x) cout << (x) << "\n"
#define fcout cout << fixed << setprecision(18)

#define MOD 1000000007 // 1e9+7
#define PI 3.1415926535
/*
3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
*/
#define ll long long int         // 10^18
#define INF 1000000001           // 1e9+1
#define LINF 1000000000000000001 // 1e18+1

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//---------------------------
int a[2000];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    
    int n;cin>>n;
    ll fi_s=0;
    ll se_s=0;
    ll th_s=0;
    ll fo_s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        fi_s+=i;
        se_s+=i*i;
        th_s+=i*a[i];
        fo_s+=a[i];
    }
    ll mo=n * se_s - fi_s * fi_s;
    double aa = (double)(n * th_s - fi_s * fo_s) / mo;
    double b = (double)(se_s * fo_s - th_s * fi_s) / mo;
    fcout<<b<<" "<<aa<<"\n";
    double cost=0;
    for(int i=0;i<n;i++){
        cost+=(a[i]-aa*i-b)*(a[i]-aa*i-b);
    }
    fcout<<cost<<endl;
    return 0;
}