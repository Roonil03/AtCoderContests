#include <iostream>
#include <atcoder/convolution>
#include <atcoder/modint>
#include <queue>
using namespace std;
using mint = atcoder::modint998244353;

int N;
int C[202020], G[202020];
int A[202020], B[202020];
mint ff[202020], fi[202020];
int M = 200000;
mint ncr(int n, int r) {
    return ff[n] * fi[r] * fi[n - r];
}
mint npr(int n, int r) {
    return ff[n] * fi[n - r];
}
int main(void) {
    ff[0] = fi[0] = 1;
    for(int i = 1;i <= M;i++) {
        ff[i] = ff[i - 1] * i;
        fi[i] = fi[i - 1] / i;
    }
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> C[i];
        C[i]--;
        A[C[i]]++;
    }
    for(int i = 0;i < N;i++){
        cin >> G[i];
        G[i]--;
        B[G[i]]++;
    }
    vector<vector<mint> > P(N);
    using pp = pair<int, int>;
    priority_queue<pp, vector<pp>, greater<pp>> que;
    for(int i = 0;i < N;i++) {
        P[i].resize(min(A[i], B[i]) + 1);
        for(int j = 0;j <= min(A[i], B[i]);j++) {
            P[i][j] = ncr(A[i], j) * npr(B[i], j);
        }
        que.push({(int)P[i].size(), i});
    }
    while(que.size() > 1) {
        int i = que.top().second; que.pop();
        int j = que.top().second; que.pop();
        P[j] = atcoder::convolution(P[i], P[j]);
        que.push({(int)P[j].size(), j});
    }
    vector<mint> &cur = P[que.top().second];
    mint ans = 0;
    for(int i = 0;i < (int)cur.size();i++) {
        ans += cur[i] * ff[N - i] * (i % 2 == 0 ? 1 : -1);
    }
    ans /= ff[N];
    cout << ans.val() << endl;
    return 0;
}

// Code by https://atcoder.jp/users/kokosei
/*
This program calculates the probability that two random permutations of $N$ 
elements (represented by their group/color counts $A$ and $B$) have no fixed 
points in common, utilizing a **divide-and-conquer approach powered by Fast 
Fourier Transform (FFT) convolution**. The algorithm first treats each 
distinct color/group as an independent sub-problem, calculating the number 
of ways to choose $j$ common fixed points for that group using combinations 
and permutations ($\binom{A_i}{j} \times P(B_i, j)$). It then organizes 
these polynomials into a priority queue based on size and iteratively merges 
them using `atcoder::convolution` to compute the total number of ways to 
have exactly $i$ common fixed points across all groups, resulting in a single 
generating function. Finally, it applies the **Principle of Inclusion-
Exclusion** to this result—summing the products of the coefficients and the 
remaining permutations $(-1)^i \times (N-i)!$—to determine the number of ways 
to have exactly zero common fixed points, which is then normalized by $N!$ to 
yield the final probability.
*/