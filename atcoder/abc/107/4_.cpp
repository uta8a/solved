// https://beta.atcoder.jp/contests/arc101/submissions/3077246
#include <bits/stdc++.h>
using namespace std;
struct BIT {
    long long n;
    vector<long long> dat;

    void initialize(long long n_input){
        n = n_input + 1;
        dat.resize(n+1);
        for(int i = 0; i<=n; i++) dat[i] = 0;
    }

    long long sum(long long i){
        long long s = 0;
        while(i >= 0){
            s += dat[i];
            i = (i & (i+1)) - 1;
        }
        return s;
    }

    void add(long long i, long long x){
        while(i <= n){
            dat[i] += x;
            i |= i+1;
        }
    }
};

int main(){
    int i, j, k;
    long long N;
    cin >> N;
    vector<int> A(N), AS(N);
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
        AS[i] = A[i];
    }
    sort(AS.begin(), AS.end());
    int ub = N;
    int lb = 0;
    BIT bit;

    long long border = ((N*(N+1)/2) + 1)/2;
    while(ub-lb>1){
        int mid = (ub+lb)/2;
        int midn = AS[mid];
        bit.initialize(2*N+1);
        int sum = 0;
        bit.add(sum+N, 1);
        long long result = 0;
        //cout << endl << midn << endl;
        for(i=0; i<N; i++){
            sum += A[i] >= midn ? 1 : -1;
            result += bit.sum(sum+N);
            bit.add(sum+N, 1);
            //cout << result << endl;
        }
        if(result>=border){
            lb = mid;
        }else{
            ub = mid;
        }
    }
    cout << AS[lb] << endl;
    return 0;
}
