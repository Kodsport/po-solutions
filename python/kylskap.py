p_a, k_a, p_b, k_b, n = map(int, input().split())

best_a, best_b, best_cost = None, None, 3e5
# Notera att vi adderar med två, detta då vi vill testa fallet då vi använder
# endast a_bilar
for a_cars in range(2 + n // k_a):
    for b_cars in range(2 + n // k_b):
        cost = a_cars * p_a + b_cars * p_b
        count = a_cars * k_a + b_cars * k_b
        if n <= count and cost < best_cost:
            best_a = a_cars
            best_b = b_cars
            best_cost = cost

print(best_a, best_b, best_cost)
