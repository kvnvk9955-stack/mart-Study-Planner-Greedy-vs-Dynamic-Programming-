#include <iostream>
#include <iomanip>
using namespace std;

struct Subject {
    int id;
    int credits;   // reward
    int hours;     // time required
    float ratio;
};

// ----------- SORT (Greedy helper) -----------
void sortByRatio(Subject arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j].ratio < arr[j+1].ratio) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// ----------- GREEDY (Partial Study) -----------
float greedyStudy(Subject arr[], int n, int totalHours) {
    sortByRatio(arr, n);

    float totalCredits = 0;
    int remaining = totalHours;

    cout << "\n--- GREEDY STRATEGY (Study All Subjects Partially) ---\n";

    for(int i = 0; i < n; i++) {
        if(remaining >= arr[i].hours) {
            totalCredits += arr[i].credits;
            remaining -= arr[i].hours;

            cout << "Subject " << arr[i].id 
                 << " fully covered | Credits: " << arr[i].credits 
                 << " | Hours left: " << remaining << "\n";
        }
        else {
            float fraction = (float)remaining / arr[i].hours;
            float gained = fraction * arr[i].credits;

            totalCredits += gained;

            cout << "Subject " << arr[i].id 
                 << " partially covered (" << fixed << setprecision(2)
                 << fraction * 100 << "%)"
                 << " | Credits gained: " << gained << "\n";

            break;
        }
    }

    return totalCredits;
}

// ----------- DP (0/1 Full Study) -----------
int dpStudy(Subject arr[], int n, int totalHours) {
    int dp[n+1][totalHours+1];

    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 0; j <= totalHours; j++) dp[0][j] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= totalHours; j++) {
            if(arr[i-1].hours > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],
                               dp[i-1][j - arr[i-1].hours] + arr[i-1].credits);
        }
    }

    cout << "\n--- DP STRATEGY (Complete Selected Subjects Fully) ---\n";

    int j = totalHours;
    int totalCredits = 0;

    for(int i = n; i > 0; i--) {
        if(dp[i][j] != dp[i-1][j]) {
            cout << "Subject " << arr[i-1].id 
                 << " selected | Credits: " << arr[i-1].credits << "\n";

            totalCredits += arr[i-1].credits;
            j -= arr[i-1].hours;
        }
    }

    return totalCredits;
}

// ----------- MAIN -----------
int main() {
    int n;
    cout << "===== SMART STUDY PLANNER =====\n";
    cout << "Enter number of subjects: ";
    cin >> n;

    Subject subjects[n];

    cout << "\nEnter (Credits, Hours Required) for each subject:\n";
    for(int i = 0; i < n; i++) {
        cout << "Subject " << i+1 << ": ";
        cin >> subjects[i].credits >> subjects[i].hours;

        subjects[i].id = i + 1;
        subjects[i].ratio = (float)subjects[i].credits / subjects[i].hours;
    }

    int totalHours;
    cout << "\nEnter total available study hours: ";
    cin >> totalHours;

    float greedyCredits = greedyStudy(subjects, n, totalHours);
    int dpCredits = dpStudy(subjects, n, totalHours);

    cout << "\n===== RESULTS =====\n";
    cout << "Greedy Strategy Credits: " << greedyCredits << endl;
    cout << "DP Strategy Credits: " << dpCredits << endl;

    cout << "\n===== RECOMMENDATION =====\n";

    float difference = abs(dpCredits - greedyCredits);

    if(dpCredits > greedyCredits) {
        cout << " Best Strategy: Focus on completing selected subjects fully.\n";
        cout << "Reason: You gain " << difference 
             << " more credits by depth-focused study.\n";
    }
    else if(dpCredits < greedyCredits) {
        cout << " Best Strategy: Spread your time across all subjects.\n";
        cout << "Reason: You gain " << difference 
             << " more credits by partial coverage.\n";
    }
    else {
        cout << " Both strategies are equally effective.\n";
        cout << "Choose based on comfort (depth vs coverage).\n";
    }

    cout << "\nInsight: ";
    if(difference == 0)
        cout << "Your study plan is balanced — either approach works.\n";
    else if(difference <= 5)
        cout << "Difference is small, strategy choice wont drastically affect outcome.\n";
    else
        cout << "Difference is significant, strategy choice strongly impacts results.\n";

    return 0;
}