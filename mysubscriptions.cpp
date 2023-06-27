#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<string>> calculateSubscriptions(const map<string, vector<float>>& newspapers, float budget) {
    vector<vector<string>> combinations;
    vector<pair<string, float>> newspaperCosts;
    
    //to calculate the cost of each newspaper
    for (const auto& it : newspapers) {
        float sum = 0;
        for (float price : it.second) {
            sum += price;
        }
        newspaperCosts.push_back({it.first, sum});
    }

    int n = newspaperCosts.size();
    
    //to generate combinations
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (newspaperCosts[i].second + newspaperCosts[j].second <= budget) {
                combinations.push_back({newspaperCosts[i].first, newspaperCosts[j].first});
            }
        }
    }

    return combinations;
}

int main() {
    map<string, vector<float>> newspapers = {
        {"TOI", {3, 3, 3, 3, 3, 5, 6}},
        {"Hindu", {2.5, 2.5, 2.5, 2.5, 2.5, 4, 4}},
        {"ET", {4, 4, 4, 4, 4, 4, 10}},
        {"BM", {1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5}},
        {"HT", {2, 2, 2, 2, 2, 4, 4}}
    };

    float weeklyBudget;
    cout << "Enter Weekly Budget : ";
    cin >> weeklyBudget;

    vector<vector<string>> combinations = calculateSubscriptions(newspapers, weeklyBudget);

    if (combinations.empty()) {
        cout << "No combinations found." << endl;
    } else {
        cout << "Possible Combinations : ";
        for (size_t i = 0; i < combinations.size(); i++) {
            cout << "{\"" << combinations[i][0] << "\", \"" << combinations[i][1] << "\"}, ";
        }
        cout << endl;
    }
    return 0;
}