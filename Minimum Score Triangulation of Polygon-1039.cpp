#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // dp[i][j] stores the min score for the polygon from vertex i to j.
    int dp[51][51];

    int solve(vector<int>& values, int i, int j) {
        // Base Case: A polygon must have at least 3 vertices to form a triangle.
        if (j - i < 2) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MAX;

        // Try every vertex 'k' between i and j as the third vertex of a triangle with base (i, j).
        for (int k = i + 1; k < j; k++) {
            // Total score = score of triangle (i,j,k) + scores of the two resulting sub-polygons.
            int current_score = (values[i] * values[j] * values[k])
                              + solve(values, i, k)
                              + solve(values, k, j);
            ans = min(ans, current_score);
        }

        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        // Initialize the dp table with -1 to mark states as unvisited.
        memset(dp, -1, sizeof(dp));
        // Start the recursion for the entire polygon (from vertex 0 to n-1).
        return solve(values, 0, n - 1);
    }
};

// Main function to drive the program
int main() {
    Solution sol;
    vector<int> values;
    int n, val;

    cout << "Enter the number of vertices in the polygon: ";
    cin >> n;

    // A polygon must have at least 3 vertices.
    if (n < 3) {
        cout << "Invalid input: A polygon must have at least 3 vertices." << endl;
        return 1;
    }

    cout << "Enter the values of the " << n << " vertices in clockwise order: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        values.push_back(val);
    }

    int min_score = sol.minScoreTriangulation(values);

    cout << "\nThe minimum score triangulation is: " << min_score << endl;

    return 0;
}
