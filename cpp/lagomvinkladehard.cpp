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

  ll n;
  cin >> n;

  ll ans = 0;
  repp(a, 1, n + 1) {
    // Notera att vi börjar från a, vi vill inte dubbelräkna
    repp(b, a, n + 1) {
      double c = sqrt(a * a + b * b - a * b);
      // ceil(c) == floor(c) testar om talet är ett heltal
      if (ceil(c) == floor(c) && 1 <= c && c <= n) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
