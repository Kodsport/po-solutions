#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define per(i, high) for (int i = high - 1; i >= 0; i--)
#define perr(i, high, low) for (int i = high - 1, i >= low; i++)
#define sz(container) ((int)container.size())
#define all(x) begin(x), end(x)

void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

int main() {
  fast();

  ll p_a, k_a, p_b, k_b, n;
  cin >> p_a >> k_a >> p_b >> k_b >> n;

  ll best_a = -1, best_b = -1, best_cost = 3e5;
  // Notera att vi adderar med två, detta då vi vill testa fallet då vi använder
  // endast a_bilar
  for (ll a_cars = 0; a_cars < 2 + n / k_a; a_cars++) {
    // Vi adderar med nämnaren - 1 i täljaren för att göra avrunda uppåt. Om vi
    // fyller en halv bil behöver den fortfarande köra
    ll b_cars = (n - k_a * a_cars + k_b - 1) / k_b;
    ll cost = a_cars * p_a + b_cars * p_b;
    if (cost < best_cost) {
      best_a = a_cars;
      best_b = b_cars;
      best_cost = cost;
    }
  }

  cout << best_a << " " << best_b << " " << best_cost << endl;

  return 0;
}
