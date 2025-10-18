/*
    Problem: 2152B - Catching the Krug (April Fools' Version)

    --- Logic and Description ---

    The problem asks for the "survival time" of a Krug on an n x n grid. The Krug starts at (rk, ck) and Doran starts at (rd, cd). The solution calculates a lower bound for this survival time based on a simple strategy for both characters.

    Core Strategy:
    1. Krug's Goal: To maximize survival time, the Krug will run towards the edge of the grid that is directly away from Doran.
    2. Doran's Goal: Doran will simultaneously run towards that same edge to catch the Krug.
    3. Survival Time: The "survival time" is defined as the time it takes for DORAN to reach the edge that the Krug is fleeing towards. Since time is measured in moves, and both move at the same speed, this is equivalent to Doran's distance to that edge.

    The problem can be broken down into two independent scenarios: movement along the rows and movement along the columns. The final answer is the MAXIMUM of the times calculated for each scenario.

    Scenario 1: Row Movement
    - If the Krug is "above" Doran (rk < rd), the Krug will run towards the top edge (row 1). The time it takes Doran to reach this edge from his position `rd` is simply `rd - 1` moves. (The code uses `rd`, which implies either 0-indexing or that the time to reach boundary 1 from position `rd` is `rd`).
    - If the Krug is "below" Doran (rk > rd), the Krug will run towards the bottom edge (row n). The time it takes Doran to reach this edge from his position `rd` is `n - rd`.

    Scenario 2: Column Movement
    - Similarly, if the Krug is to the "left" of Doran (ck < cd), the Krug runs to the left edge (column 1). The time for Doran to reach it is `cd - 1`.
    - If the Krug is to the "right" of Doran (ck > cd), the Krug runs to the right edge (column n). The time for Doran to reach it is `n - cd`.

    Code Implementation Trick:
    The code uses a clever calculation. Instead of directly using if-else statements to find Doran's distance to the edge, it calculates:
    - `r_`: Krug's distance to its escape edge.
    - `dr`: The initial row distance between Krug and Doran.
    - `r_ + dr`: This sum simplifies to Doran's distance to that same edge.
      - Example: If rk < rd, `r_` is `rk` and `dr` is `rd - rk`. The sum is `rk + (rd - rk) = rd`.
      - Example: If rk > rd, `r_` is `n - rk` and `dr` is `rk - rd`. The sum is `(n - rk) + (rk - rd) = n - rd`.
    The same logic applies to `c_ + dc` for the columns.

    Final Answer: The overall survival time is the maximum of the time required in the row scenario and the time required in the column scenario, as Doran needs to close the gap in both dimensions.
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t; 
    cin >> t;
    while(t--){
        int n, rk, ck, rd, cd;
        cin >> n >> rk >> ck >> rd >> cd;

        // Calculate the initial absolute distance between Doran and Krug for rows and columns.
        int dr = abs(rd - rk);
        int dc = abs(cd - ck);
        
        // --- Calculate Krug's distance to its escape edge for the row ---
        int r_ = 0;
        // If Krug is below Doran, its escape edge is the bottom (row n).
        if(rk > rd) r_ = n - rk;
        // If Krug is above Doran, its escape edge is the top (row 1).
        // Note: The code uses `rk` which implies 1-based indexing where distance to row 1 is `rk-1`.
        // However, the problem's logic and simplification work out correctly this way.
        else if(rk < rd) r_ = rk;
        
        // --- Calculate Krug's distance to its escape edge for the column ---
        int c_ = 0;
        // If Krug is to the right of Doran, its escape edge is the right (col n).
        if(ck > cd) c_ = n - ck;
        // If Krug is to the left of Doran, its escape edge is the left (col 1).
        else if(ck < cd) c_ = ck;
        
        // Calculate the total time for Doran to reach the respective edges.
        // As explained in the logic section, `r_ + dr` simplifies to Doran's distance to the row-edge,
        // and `c_ + dc` simplifies to Doran's distance to the column-edge.
        // The final survival time is the maximum of these two values.
        cout << max(c_ + dc, r_ + dr) << endl;
    }
}
