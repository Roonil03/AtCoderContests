#include <bits/stdc++.h>
#pragma GCC target "avx512bw,avx512vl"
#pragma GCC optimize "tree-vectorize,unroll-loops"
#include "immintrin.h"

#include <cstdio>
struct SaferInput {
  static constexpr int bufsz = 1 << 15;
 
  SaferInput() {
    read();
  }
 
  void read() {
    auto e = std::copy(bufptr, std::end(buf) - 1, buf);
    bufptr = buf;
    int tok = fread(e, 1, std::end(buf) - 1 - e, stdin);
    e[tok] = 0;
  }

  void operator()(char* b, int n) { rd(b, n); }
 
  template <typename T>
  void operator()(T* b, int n) { for (int i = 0; i < n; ++i) rd(b[i]); }
 
  template <typename... Ts, std::enable_if_t<(!std::is_pointer_v<std::decay_t<Ts>> && ...)>* = nullptr>
  auto operator()(Ts&... xs) { (rd(xs), ...); }

  template <char start = '!', int prefetch = 32>
  void skiplt() {
    if (std::end(buf) - 1 - bufptr < prefetch) read();
    while (*bufptr < start) ++bufptr;
  }
 
  char buf[bufsz], *bufptr = std::end(buf) - 1;
 
  template <char start = '-', typename T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
  void rd(T& x) {
    if constexpr (std::is_unsigned_v<T> && start == '-') return rd<'0'>(x);
    skiplt<start>();
    bool sign = start == '-' && *bufptr == '-'? 1: 0;
    bufptr += start < '0' && *bufptr < '0';
    T res{};
    while (*bufptr >= '0') res = res * 10 + (*bufptr++ - '0');
    x = sign? -res: res;
  }
 
  template <char start = '!'>
  void rd(char& x) {
    skiplt<start>();
    x = *bufptr++;
  }
 
  void rd(char* s, int n) {
    char* e = s + n;
    do s = std::copy_n(bufptr, std::min(e - s, std::end(buf) - 1 - buf), s);
    while (s < e && (read(), 1));
  }
 
  template <char start = '!'>
  void rd(std::string& s) {
    skiplt<start>();
    do {
      auto l = bufptr;
      while (*bufptr >= start) ++bufptr;
      s.insert(s.end(), l, bufptr);
    } while (bufptr == std::end(buf) - 1 && (read(), 1));
  }
} reader;

using namespace std;

struct { using X = int; template <typename T = X> T operator()() const { T t; reader(t); return t; } operator X() const { return operator()(); } template <typename T> operator T() const { return operator()<T>(); } template <auto=0> string operator~() const { return *this; } char operator!() const { return *this; } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
void prints(const auto& c) { cout << distance(c.begin(), c.end()) << ' ' << c << '\n'; }
string operator*(int n, string s) { string t; while (n-- > 0) t += s; return t; }
namespace std {
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c.begin(), c)>, string>, decltype(out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
auto operator>>(istream& in, auto&& p) -> decltype(p.first, p.second, in) { return in >> p.first >> p.second; }
auto operator<<(ostream& out, const auto& p) -> decltype(p.first, p.second, out) { return out << p.first << ' ' << p.second; }
}
template <typename It> struct range { It first, last; constexpr range() {} constexpr range(It first, It last) : first{first}, last{last} {} constexpr range(It first, auto n) : range{first, first + n} {} constexpr range(auto&& c) : range{c.begin(), c.end()} {} constexpr It begin() const { return first; } constexpr It end() const { return last; } constexpr int size() const { return last - first; } constexpr const auto& operator[](int i) const { return first[i]; } constexpr auto& operator[](int i) { return first[i]; } auto operator~() const { return range<decltype(reverse_iterator(last))>{reverse_iterator(last), reverse_iterator(first)}; } }; range(auto&& c) -> range<decltype(c.begin())>;
template <int from, int which> auto getfield(const auto& a) -> const auto& { static_assert(1 <= which && which <= from && from <= 6); auto fix = [](auto& x) -> auto& { return x; }; if constexpr (from == 1) { if constexpr (is_scalar_v<decay_t<decltype(a)>>) { if constexpr (which == 1) return fix(a); } else { auto& [a1] = a; if constexpr (which == 1) return fix(a1); } } else if constexpr (from == 2) { auto& [a1, a2] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); } else if constexpr (from == 3) { auto& [a1, a2, a3] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); } else if constexpr (from == 4) { auto& [a1, a2, a3, a4] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); } else if constexpr (from == 5) { auto& [a1, a2, a3, a4, a5] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); if constexpr (which == 5) return fix(a5); } else if constexpr (from == 6) { auto& [a1, a2, a3, a4, a5, a6] = a; if constexpr (which == 1) return fix(a1); if constexpr (which == 2) return fix(a2); if constexpr (which == 3) return fix(a3); if constexpr (which == 4) return fix(a4); if constexpr (which == 5) return fix(a5); if constexpr (which == 6) return fix(a6); } }
template <int from, int which> struct GetField { decltype(auto) operator()(const auto& a) { return getfield<from, which>(a); } };
template <int from, int which, typename Cmp = equal_to<>> struct CompareField { bool operator()(const auto& a, const auto& b) const { return Cmp{}(getfield<from, which>(a), getfield<from, which>(b)); } };
template <int from, int which, int... whichs> struct Ordering { bool operator()(const auto& a, const auto& b) const { auto& aa = getfield<from, labs(which)>(a), & bb = getfield<from, labs(which)>(b); if (aa < bb) { return which > 0; } else if (bb < aa) { return which < 0; } else if constexpr (sizeof...(whichs)) { return Ordering<from, whichs...>{}(a, b); } return 0; } };
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return a = a < b? a: b; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return a = a < b? b: a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } int sgn(auto a) { return (0 < a) - (a < 0); } auto sqr(auto a) { return a * a; } auto change(auto&& a, const auto& b) { auto t = +a; return (a = b) - t; }
void ilset(auto& first, auto&& second, auto&&... args) { first = move(second); if constexpr (sizeof...(args)) ilset(forward<decltype(args)>(args)...); }
auto lshift(auto&& first, auto&&... args) { auto t = move(first); if constexpr (sizeof...(args)) { static_assert(is_lvalue_reference_v<decltype(first)>); first = lshift(forward<decltype(args)>(args)...); } return t; } auto rshift(auto&& first, auto&... args) { auto tup = tie(first, args...); constexpr int k = sizeof...(args); auto t = move(get<k>(tup)); [&]<size_t... i>(index_sequence<i...>) { ((get<k - i>(tup) = move(get<k - i - 1>(tup))), ...); }(make_index_sequence<k>{}); return t; }
void lrotate(auto& arg, auto&... args) { get<sizeof...(args)>(tie(arg, args...)) = lshift(arg, args...); } void rrotate(auto& arg, auto&... args) { arg = rshift(arg, args...); }
template <auto x> integral_constant<decltype(x), x> CC;
template <int X, int mn = 0> auto dispatch(int x, auto f) { if (X == x) return f(CC<X>); else if constexpr (X == mn) __builtin_unreachable(); else return dispatch<X - 1, mn>(x, f); }
template <typename T, typename Cmp = greater<>> using PQ = priority_queue<T, vector<T>, Cmp>;
auto pop(auto& c) -> decay_t<decltype(c.top())> { auto t = move((decay_t<decltype(c.top())>&)c.top()); c.pop(); return t; } auto pop(auto& c) -> decay_t<decltype(c.back())> { auto t = move(c.back()); c.pop_back(); return t; } auto pop(auto&& c) -> decay_t<decltype(c.front())> { auto t = move(c.front()); c.pop_front(); return t; } auto popfront(auto& c) -> decay_t<decltype(c.front())> { auto t = move(c.front()); c.pop_front(); return t; }

#define begend(a) (a).begin(), (a).end()
#define begendbeg(a) (a).begin(), (a).end(), (a).begin()
#define begendend(a, ...) (a).begin(), (a).end() __VA_OPT__(,) __VA_ARGS__), (a).end(



using V = __attribute((vector_size(64))) uint32_t;

struct PleaseReuse {
  const V vmod, vmod2, vinv;
  const __mmask16 aaaa, cccc, f0f0, ff00;
  PleaseReuse();

  V sum(V a, V b) const { a += b; V c = a - vmod2; mini(a, c); return a; }
  V dif(V a, V b) const { a -= b; V c = a + vmod2; mini(a, c); return a; }
};

const PleaseReuse reuse;

struct Montgomery_v16u32 {
  using T = uint32_t;
  using TT = uint64_t;
  constexpr static int bits = sizeof(T) * 8;
  constexpr static int lg = __builtin_ctz(bits);
  using V __attribute((vector_size(64))) = T;
  using VV __attribute((vector_size(64))) = TT;
  using Lane __attribute((vector_size(64))) = __uint128_t;

  T mod, mod2, inv, p1, m1, r2;
  V vmod, vmod2, vinv, vp1, vm1, vr2;

  constexpr Montgomery_v16u32(T n): mod(n), mod2(n + n), inv(1), p1(-n % n), m1(n - p1), r2(p1), vmod{}, vmod2{}, vinv{}, vp1{}, vm1{}, vr2{} {
    for (int i = 0; i < lg; ++i) {
      inv *= 2 - n * inv;
    }
    for (int i = 0; i < 4; ++i) {
      r2 *= 2;
      if (r2 >= mod) {
        r2 -= mod;
      }
    }
    for (int i = 0; i < lg - 2; ++i) {
      r2 = prod(r2, r2);
    }
    vmod = V{} + mod;
    vmod2 = V{} + mod2;
    vinv = V{} + inv;
    vp1 = V{} + p1;
    vm1 = V{} + m1;
    vr2 = V{} + r2;
  }

  constexpr T in(T x) const {
    return prod(x, r2);
  }

  constexpr T out(T x) const {
    return reduce(x);
  }

  constexpr T reduce(TT x) const {
    T lo = x, hi = x >> bits;
    T q = lo * inv;
    T a = hi - (q * TT{mod} >> bits) + mod;
    return a;
  }

  constexpr T prod(T a, T b) const {
    return reduce(a * TT{b});
  }

  constexpr T sum(T a, T b) const {
    return a += b, a = a > ~T{} / 2? a - mod2: a;
  }

  constexpr T dif(T a, T b) const {
    return a -= b, a = a > ~T{} / 2? a + mod2: a;
  }

  constexpr T fix(T a) const {
    return a >= mod? a - mod: a;
  }

  V in(V x) const {
    return prod(x, vr2);
  }

  V out(V x) const {
    return fix(prod(x, V{} + 1));
  }

  __m512i reduce(VV x) const {
    return (__m512i)((V)x - (V)_mm512_mul_epu32(_mm512_mul_epu32((__m512i)x, (__m512i)reuse.vinv), (__m512i)reuse.vmod));
  }

  __m512i reduce(__m512i& into, VV x) const {
    return _mm512_mask_sub_epi32(into, 0xaaaa, (__m512i)x, _mm512_mul_epu32(_mm512_mul_epu32((__m512i)x, (__m512i)reuse.vinv), (__m512i)reuse.vmod));
  }

  V prod(V a, V b) const {
    auto even = _mm512_bsrli_epi128(reduce((VV)_mm512_mul_epu32((__m512i)a, (__m512i)b)), 4);
    // auto odd = reduce((VV)_mm512_mul_epu32(_mm512_bsrli_epi128((__m512i)a, 4), _mm512_bsrli_epi128((__m512i)b, 4)));
    // return (V)_mm512_mask_blend_epi32(0xaaaa, even, odd) + reuse.vmod;
    V res = (V)reduce(even, (VV)_mm512_mul_epu32(_mm512_bsrli_epi128((__m512i)a, 4), _mm512_bsrli_epi128((__m512i)b, 4)));
    return res + reuse.vmod;
  }

  V sum(V a, V b) const {
    return a += b, a = a > a - reuse.vmod2? a - reuse.vmod2: a;
  }

  V dif(V a, V b) const {
    return a -= b, a = a > a + reuse.vmod2? a + reuse.vmod2: a;
  }

  V fix(V a) const {
    return a >= reuse.vmod? a - reuse.vmod: a;
  }
};

constexpr Montgomery_v16u32 mod{998244353};

PleaseReuse::PleaseReuse() : vmod{mod.vmod}, vmod2{mod.vmod2}, vinv{mod.vinv}, aaaa{0xaaaa}, cccc{0xcccc}, f0f0{0xf0f0}, ff00{0xff00} { }

constexpr int N = 2e5 + 5, M = 20, G = 15;

int pw10[1 << M];

alignas(64) int a[1 << M], b[1 << M], c[1 << M], d[1 << 12], e[1 << 12];

__always_inline constexpr uint64_t pdep(uint64_t l, array<uint64_t, 4> strides) {
  uint64_t s = 0;
  #pragma GCC unroll 99
  for (int d = 0; d < 4; ++d) s += (l >> d & 1) * strides[d];
  return s;
}

__always_inline array<V, 16>& load4(array<V, 16>& cur, V* src, array<uint64_t, 4> strides) {
  #pragma GCC unroll 99
  for (uint64_t l = 0; l < 16; ++l) cur[l] = src[pdep(l, strides)];
  return cur;
}

__always_inline array<V, 16>& store4(array<V, 16>& cur, V* dst, array<uint64_t, 4> strides) {
  #pragma GCC unroll 99
  for (uint64_t l = 0; l < 16; ++l) dst[pdep(l, strides)] = cur[l];
  return cur;
}

__always_inline array<V, 16>& load4(array<V, 16>& cur, V* src, uint64_t stride) { return load4(cur, src, {stride, stride * 2, stride * 4, stride * 8}); }
__always_inline array<V, 16>& store4(array<V, 16>& cur, V* dst, uint64_t stride) { return store4(cur, dst, {stride, stride * 2, stride * 4, stride * 8}); }

__always_inline array<V, 16>& extbut4(array<V, 16>& cur) {
  #pragma GCC unroll 99
  for (uint64_t d = 0; d < 4; ++d)
  #pragma GCC unroll 99
  for (uint64_t l = 0; l < 16; ++l) if (~l >> d & 1) {
    V& x = cur[l], & y = cur[l ^ (1 << d)];
    ilset(x, reuse.sum(x, y), y, reuse.dif(x, y));
  }
  return cur;
}

__always_inline V& intbut4(V& x) {
  V y;
  y = (V)_mm512_shuffle_epi32((__m512i)x, (_MM_PERM_ENUM)0xb1);
  x = reuse.sum((V)_mm512_mask_sub_epi32((__m512i)x, 0xaaaa, (__m512i)reuse.vmod2, (__m512i)x), y);
  y = (V)_mm512_shuffle_epi32((__m512i)x, (_MM_PERM_ENUM)0x4e);
  x = reuse.sum((V)_mm512_mask_sub_epi32((__m512i)x, 0xcccc, (__m512i)reuse.vmod2, (__m512i)x), y);
  y = (V)_mm512_shuffle_i32x4((__m512i)x, (__m512i)x, 0xb1);
  x = reuse.sum((V)_mm512_mask_sub_epi32((__m512i)x, 0xf0f0, (__m512i)reuse.vmod2, (__m512i)x), y);
  y = (V)_mm512_shuffle_i32x4((__m512i)x, (__m512i)x, 0x4e);
  x = reuse.sum((V)_mm512_mask_sub_epi32((__m512i)x, 0xff00, (__m512i)reuse.vmod2, (__m512i)x), y);
  return x;
}

__always_inline array<V, 16>& intbut4(array<V, 16>& x) {
  #pragma GCC unroll 99
  for (uint64_t l = 0; l < 16; ++l) intbut4(x[l]);
  return x;
}

__always_inline array<V, 16>& pmul4(array<V, 16>& x, array<V, 16>& y) {
  #pragma GCC unroll 99
  for (uint64_t l = 0; l < 16; ++l) x[l] = mod.prod(x[l], mod.sum(x[l], y[l]));
  return x;
}

__always_inline array<V, 16>& collect4(V& acc, array<V, 16>& x, V* y, uint64_t sy) {
  #pragma GCC unroll 99
  for (uint64_t l = 0; l < 16; ++l) acc = mod.sum(acc, mod.prod(x[l], y[l * sy]));
  return x;
}

__always_inline array<V, 16>& pmulupd4(array<V, 16>& x, V* z, uint64_t sz) {
  #pragma GCC unroll 99
  for (uint64_t l = 0; l < 16; ++l) {
    x[l] = mod.prod(x[l], x[l]);
    z[l * sz] = mod.sum(x[l], z[l * sz]);
  }
  return x;
}

void p10gather_(uint64_t& sdst, V& dst, int* la, int *ra) {
  for (auto& u: range{la, ra}) {
    V vu{}; vu += (uint32_t)u;
    auto l = la, r = &u;
    while (r - l & 15) sdst += pw10[*l++ ^ u];
    while (l < r) dst = mod.sum(dst, (V)_mm512_i32gather_epi32((__m512i)((V)(__m512i_u&)*l ^ vu), pw10, 4)), l += 16;
  }
}

void p10gather_(uint64_t& sdst, V& dst, int* la, int *ra, int* lb, int* rb) {
  if (ra - la > rb - lb) swap(la, lb), swap(ra, rb);
  for (auto u: range{la, ra}) {
    V vu{}; vu += (uint32_t)u;
    auto l = lb, r = rb;
    while (r - l & 15) sdst += pw10[*l++ ^ u];
    while (l < r) dst = mod.sum(dst, (V)_mm512_i32gather_epi32((__m512i)((V)(__m512i_u&)*l ^ vu), pw10, 4)), l += 16;
  }
}

int ofsa[1 << M - G | 1], ofsb[1 << M - G | 1];

void p10gather(uint64_t& sdst, V& dst, int* la, int *ra) {
  for (int i = 0, j = 0; i < 1 << M - G; ++i) {
    while (j < ra - la && la[j] >> G == i) ++j;
    ofsa[i + 1] = j;
  }
  for (int y = 0; y < 1 << M - G; ++y) p10gather_(sdst, dst, la + ofsa[y], la + ofsa[y + 1]);
  for (int x = 1; x < 1 << M - G; ++x)
  for (int y = 0; y < 1 << M - G; ++y) if (~y & x & -x) p10gather_(sdst, dst, la + ofsa[y], la + ofsa[y + 1], la + ofsa[x ^ y], la + ofsa[(x ^ y) + 1]);
}

void p10gather(uint64_t& sdst, V& dst, int* la, int *ra, int* lb, int* rb) {
  for (int i = 0, j = 0; i < 1 << M - G; ++i) {
    while (j < rb - lb && lb[j] >> G == i) ++j;
    ofsb[i + 1] = j;
  }
  for (int x = 0; x < 1 << M - G; ++x)
  for (int y = 0; y < 1 << M - G; ++y) p10gather_(sdst, dst, la + ofsa[y], la + ofsa[y + 1], lb + ofsb[x ^ y], lb + ofsb[(x ^ y) + 1]);
}

constexpr uint64_t sA = 1 << 12;
constexpr uint64_t sB = 1 << 8;
constexpr uint64_t sC = 1 << 4;
constexpr uint64_t sD = 1 << 0;
#define rep(A) for (uint64_t A = 0; A < s##A << 4; A += s##A)
#define $repa rep(A)
#define $repb rep(B)
#define $repc rep(C)
#define $repd rep(D)
#define $locv if (array<V, 16> v{}, u{}, z{}; 1)

#define rep4(M, D) \
  for (uint64_t I = 0, s = 1 << D; I < 1 << M; I += 16 << D) \
  for (uint64_t i = I; i < I + (1 << D); ++i) if (array<V, 16> v{}, u{}, z{}; 1)

int main() {
  for (int i = 0, f = 1; i < 1 << M; ++i) pw10[i] = f, f = mod.prod(f, mod.in(10));
  pw10[0] = 0;
  int n = $, m = $, ans0{}, ans1{};
  map<int, vector<int>> w;
  {
  vector<int> b(1 << m);
  for (int i = 0; i < n; ++i) ++b[$];
  for (int i = 0; i < 1 << m; ++i) ans0 += b[i] / 2;
  for (int i = 0; i < 1 << m; ++i) if (b[i]) w[b[i]].push_back(i), ++c[i];
  }
  vector<int> vrem, svrem;
  for (auto& [k, v]: w) {
    sort(begend(v));
    vrem.insert(vrem.end(), begend(v));
  }
  reverse(begend(vrem));
  constexpr int K = 32;
  for (int i = 1; i < K; ++i) w[i];
  for (auto& [k, v]: w) {
    vrem.resize(vrem.size() - v.size());
    if (k < K) {
      $repa $repd {
        $repb $locv store4(extbut4(load4(v, (V*)c + A + B + D, sC)), (V*)d + (B >> 4), sD);
        $repc $locv store4(extbut4(load4(v, (V*)d + (C >> 4), sC)), (V*)a + A + C + D, sB);
      }
      V vk{}; vk += (uint32_t)k;
      $repb $repc {
        $repd $locv store4(intbut4(extbut4(load4(v, (V*)a + B + C + D, sA))), (V*)d + D, sC);
        $repa $locv pmulupd4(extbut4(load4(v, (V*)d + (A >> 8), sD)), (V*)b + A + B + C, sD);
      }
      for (auto& v: v) --c[v];
    } else {
      svrem.assign(begend(vrem));
      sort(begend(svrem));
      V cans{};
      uint64_t scans{};
      p10gather(scans, cans, &v[0], &*v.end());
      p10gather(scans, cans, &v[0], &*v.end(), &svrem[0], &*svrem.end());
      for (int i = 0; i < 16; ++i) scans += cans[i];
      ans0 = (ans0 + scans % mod.mod * (k - K + 1)) % mod.mod;
    }
  }
  $repb $repc {
    $repa $locv store4(extbut4(load4(v, (V*)b + A + B + C, sD)), (V*)d + (A >> 8), sD);
    $repd $locv store4(extbut4(load4(v, (V*)d + D, sC)), (V*)b + B + C + D, sA);
  }
  V vans1{};
  $repa $repd {
    $repb $locv store4(intbut4(extbut4(load4(v, (V*)b + A + B + D, sC))), (V*)d + (B >> 4), sD);
    $repc $locv collect4(vans1, extbut4(load4(v, (V*)d + (C >> 4), sC)), (V*)pw10 + A + C + D, sB);
  }
  for (int i = 0; i < 16; ++i) ans1 = mod.sum(ans1, vans1[i]);
  for (int x = mod.in(1 << M + 1), b = mod.mod - 2; b; b /= 2, x = mod.prod(x, x)) if (b % 2) ans1 = mod.prod(ans1, x);
  print((ans1 * 1ull * mod.r2 + ans0) % mod.mod);
}

// Code by https://atcoder.jp/users/MaxPlus

/*
This algorithm counts a weighted sum over the elements of an array by leveraging SIMD parallelism (specifically 
AVX-512 vectorization) to accelerate multi-dimensional Fast Walsh-Hadamard Transforms (FWHT) or a variant of 
subset convolution. It first groups element frequencies into a map and partitions them by a frequency threshold 
to handle highly frequent elements separately using a customized, bitwise-bucketed gathering technique (p10gather) 
that employs memory-prefetching and vectorized hardware instructions (_mm512_i32gather_epi32). For elements with 
smaller frequencies, it loads chunks of data into 512-bit vector registers (__m512i), transforms the states using 
bit-permuting butterfly networks tailored for 4-bit subproblems (extbut4 and intbut4), performs element-wise 
Montgomery-multiplication routines (mod.prod), and then applies an inverse transform. Finally, it accumulates the 
calculated coefficients against precomputed power-of-10 weights (pw10) across the vector lanes to output the final 
scalar result modulo 998244353.
*/