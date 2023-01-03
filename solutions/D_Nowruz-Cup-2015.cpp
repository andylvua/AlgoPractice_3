#include <iostream>
#include <vector>
#include <algorithm>

int find_max_place(std::vector<int> participants, int amanchik, int n) {
    int max_place = n / 2;

    int weakest_participant = 0;
    int strongest_participant = n - 3;
    int team = amanchik + participants[strongest_participant + 1];

    while (strongest_participant > weakest_participant) {
        if (participants[weakest_participant] + participants[strongest_participant] <= team) {
            max_place -= 1;
            weakest_participant += 1;
            strongest_participant -= 1;
            break;
        }
        strongest_participant -= 2;
    }

    return max_place;
}

int find_min_place(std::vector<int> participants, int amanchik, int n) {
    int min_place = 1;

    int weakest_participant = 1;
    int strongest_participant = n - 2;
    int team = amanchik + participants[weakest_participant - 1];

    while (weakest_participant < strongest_participant) {
        if (participants[weakest_participant] + participants[strongest_participant] > team) {
            min_place += 1;
            weakest_participant += 1;
            strongest_participant -= 1;
            break;
        }
        weakest_participant += 2;
    }

    return min_place;
}

int main() {
    int n;
    std::cin >> n;
    n = 2 * n;

    std::vector<int> participants;
    int amanchik;

    std::cin >> amanchik;

    for (int i = 0; i < n - 1; i++) {
        int participant;
        std::cin >> participant;
        participants.push_back(participant);
    }

    std::sort(participants.begin(), participants.end());

    std::cout << find_max_place(participants, amanchik, n) << " " << find_min_place(participants, amanchik, n) << std::endl;

    return 0;
}
