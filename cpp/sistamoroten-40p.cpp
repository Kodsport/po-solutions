#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

ll n, m, k;
vector<ll> sums;

void distribution(ll i, ll sum) {
  if (i == n) {
    sums[sum] += 1;
    return;
  }

  rep(j, 1, m + 1) {
    distribution(i + 1, sum + j);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m >> k;
  sums.resize(n * m + 1);
  distribution(0, 0);
  sort(sums.rbegin(), sums.rend());

  double k_sum = 0;
  rep(i, 0, k) {
    k_sum += sums[i];
  }

  cout << k_sum / pow(m, n) << endl;
}
