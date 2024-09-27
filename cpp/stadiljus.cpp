#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, x, y;
  cin >> n >> x >> y;

  ll lamps[n];
  for (ll i = 0; i < n; i++)
    cin >> lamps[i];

  sort(lamps, lamps + sizeof(lamps) / sizeof(lamps[0]));

  ll acc = 0;
  ll count = 0;
  for (ll i = 0; i < n; i++) {
    acc += x * lamps[i];
    count += 1;

    if (y < (acc + count - 1) / count) {
      count -= 1;
      break;
    }
  }

  cout << count;

  return 0;
}
