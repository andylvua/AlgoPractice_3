#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    while (true) {
        int n;
        double m;
        std::cin >> n;
        std::cin >> m;

        if (n == 0 && m == 0) {
            break;
        }

        std::vector<int> calories_array;
        std::vector<double> prices_array;

        for (int i = 0; i < n; i++) {
            int calories;
            double prices;
            std::cin >> calories;
            std::cin >> prices;
            calories_array.push_back(calories);
            prices_array.push_back(static_cast<int>(prices * 100));
        }

        int money_to_spend = static_cast<int>(m * 100);

        std::vector<int> max_calories(money_to_spend + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = static_cast<int>(prices_array[i]); j < money_to_spend + 1; j++) {
                max_calories[j] = std::max(max_calories[j], max_calories[j - static_cast<int>(prices_array[i])] + calories_array[i]);
            }
        }

        std::cout << max_calories[money_to_spend] << std::endl;
    }
}
