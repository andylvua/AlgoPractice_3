#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>


int main() {
    int n, l, u;
    scanf("%d%d%d", &n, &l, &u);

    std::vector<std::pair<int, int> > weights(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i].first);
        weights[i].second = i;
    }

    sort(weights.begin(), weights.end());
    std::vector<std::pair<int, int>> detected;
    std::vector<std::pair<int, int>> undetected;

    long sum = 0;

    for (int i = 0; i < n; i++) {
        long current_weight = sum + weights[i].first;
        if (current_weight <= u) {
            detected.push_back(weights[i]);
            sum = current_weight;
        } else {
            undetected.push_back(weights[i]);
        }
    }

    if (detected.empty()) {
        printf("0");
        return 0;
    }

    while (sum < l && !undetected.empty() && detected.begin()->first < (undetected.end() - 1)->first) {
        sum += (undetected.end() - 1)->first - detected.begin()->first;
        detected.erase(detected.begin());
        detected.push_back(*--undetected.end());
        undetected.pop_back();
    }

    if (sum < l) {
        printf("0");
        return 0;
    }

    printf("%zu", detected.size());
    printf("\n");
    for (std::pair<int, int> element : detected) {
        printf(" %d", element.second);
    }
    return 0;
}
