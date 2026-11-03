#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll p_a, k_a, p_b, k_b, n;
  cin >> p_a >> k_a >> p_b >> k_b >> n;

  ll best_a = -1, best_b = -1, best_cost = 3e5;
  // Notera att vi adderar med två, detta då vi vill testa fallet då vi använder
  // endast a_bilar
  rep(a_cars, 0, 2 + n / k_a) {
    rep(b_cars, 0, 2 + n / k_b) {
      ll count = a_cars * k_a + b_cars * k_b;
      if (count >= n) {
        ll cost = a_cars * p_a + b_cars * p_b;
        if (cost < best_cost) {
          best_a = a_cars;
          best_b = b_cars;
          best_cost = cost;
        }
      }
    }
  }

  cout << best_a << " " << best_b << " " << best_cost << endl;
}
