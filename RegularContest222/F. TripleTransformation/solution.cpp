#include <bits/stdc++.h>
#include <atcoder/math>

using namespace std;

#ifdef DEBUG
  #include "debug.hpp"
#else
  #define dbg(...) 0
#endif

void apply_op(array<int, 3>& A) {
  if (A[2] > A[0] + A[1]) {
    A[2] -= A[0] + A[1];
    A[0] += A[0];
    A[1] += A[1];
  }
  else if (A[1] > A[0] + A[2]) {
    A[1] -= A[0] + A[2];
    A[0] += A[0];
    A[2] += A[2];
  }
  else if (A[0] > A[1] + A[2]) {
    A[0] -= A[1] + A[2];
    A[1] += A[1];
    A[2] += A[2];
  }
  else {
    int sum = A[0] + A[1] + A[2];
    A[0] = sum - A[0] - A[0];
    A[1] = sum - A[1] - A[1];
    A[2] = sum - A[2] - A[2];
  }
}

template <typename T>
T inverse(T a, T m) {
  T m0 = m;
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  if (u < 0) u += m0;
  return u;
}

int64_t modLog(int64_t a, int64_t b, int64_t m) {
  if (b == 1) return 0;
	int64_t n = (int64_t) sqrt(m) + 1, e = 1, f = 1, j = 1;
	unordered_map<int64_t, int64_t> A;
	while (j <= n && (e = f = e * a % m) != b % m)
		A[e * b % m] = j++;
	if (e == b % m) return j;
	if (__gcd(m, e) == __gcd(m, b)) 
    for (int i = 2; i < n + 2; ++i) if (A.count(e = e * f % m))
			return n * i - A[e];
	return -1;
}

int solve2(array<int, 3> A, array<int, 3> B) {
  vector<pair<int, int>> ab;
  int S = 0;
  for (int i = 0; i < 3; ++i) {
    if ((A[i] == 0) != (B[i] == 0)) return -1;
    if (A[i] != 0) {
      ab.emplace_back(A[i], B[i]);
      S += A[i];
    }
  }
  if (int(ab.size()) < 2) return (A == B) ? 0 : -1;
  int z = -1;
  {
    vector<long long> r, m;
    for (auto [ai, bi] : ab) {
      int g = gcd(ai, S);
      if ((bi % g) != 0) return -1;
      int inv_ai = inverse(ai / g, S / g);
      r.push_back((inv_ai * int64_t(bi / g)) % (S / g));
      m.push_back(S / g);
    }
    pair<long long, long long> crt_res = atcoder::crt(r, m);
    if (crt_res.second == 0) return -1;
    assert(crt_res.second == S);
    z = crt_res.first;
  }
  const int INF = numeric_limits<int>::max();
  int ans = INF;
  for (int zi : {z, S - z}) {
    int x = modLog(2, zi, S);
    if (x < 0) continue;
    vector<int> a, b;
    for (const pair<int, int>& p : ab) {
      a.push_back(p.first);
      b.push_back(p.second);
    }
    for (int& ai : a) ai = (ai * int64_t(zi)) % S;
    int suma = 0;
    for (int ai : a) suma += ai;
    if (suma != S) {
      suma = 0;
      for (int& ai : a) {
        ai = S - ai;
        suma += ai;
      }
      assert(suma == S);
    }
    if (a == b) {
      ans = min(ans, x);
    }
  }
  if (ans < INF) return ans;
  return -1;
}

int solve(array<int, 3> A, array<int, 3> B) {
  if (A[0] + A[1] + A[2] != B[0] + B[1] + B[2]) return -1;
  int sum = A[0] + A[1] + A[2];
  if (sum == 0) return 0;
  int ans = 0;
  while (!(sum & 1)) {
    while ((A[0] & 1) || (A[1] & 1) || (A[2] & 1)) {
      if (A == B) return ans;
      apply_op(A);
      ans++;
    }
    if (A == B) return ans;
    if ((B[0] & 1) || (B[1] & 1) || (B[2] & 1)) return -1;
    for (int i = 0; i < 3; ++i) {
      A[i] >>= 1;
      B[i] >>= 1;
    }
    sum >>= 1;
  }
  int g = gcd(gcd(A[0], A[1]), A[2]);
  if (gcd(gcd(B[0], B[1]), B[2]) != g) {
    return -1;
  }
  for (int i = 0; i < 3; ++i) {
    A[i] /= g;
    B[i] /= g;
  }
  int ans2 = solve2(A, B);
  if (ans2 < 0) return -1;
  return ans + ans2;
}

void test_case() {
  array<int, 3> A, B;
  for (int i = 0; i < 3; ++i) cin >> A[i];
  for (int i = 0; i < 3; ++i) cin >> B[i];
  cout << solve(A, B) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    test_case();
  }
}


// Code by https://atcoder.jp/users/fxhd
/*
This algorithm finds the minimum number of operations required to transform a three-element state array A into 
a target array B under invariants that keep the sum of elements constant. It begins by filtering out parity 
issues, dividing common factors by 2, and simulating the operations via apply_op until the total sum becomes 
odd or zero. It then reduces the remaining problem to modular arithmetic using the Chinese Remainder Theorem 
(via atcoder::crt), matching the transformation to a modular multiplication state where the elements of A are 
multiplied by a dynamic factor modulo the invariant sum. Finally, the Baby-step Giant-step algorithm (modLog) 
is utilized to compute the discrete logarithm base 2 of this multiplier to efficiently deduce the exact number 
of steps needed to achieve the transformation.
*/