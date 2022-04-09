#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
*   The idea is to keep track of the left and right side cost.
*   By doing this we only have to go over the array twice.
*   Once to calculate the initial cost and once to adapt the values for
*   each step.
*   We keep track of both the cost and the amount of packages in pairs.
*   We can then add or subtract the amount of packages on one side if we
*   take a step in a direction.
*/

int main()
{

// ---- GET INPUT ----

    size_t nHouses;

    cin >> nHouses;

    vector<size_t> packages(nHouses);

    for (size_t nr = 0; nr != nHouses; ++nr)
        cin >> packages[nr];


// ---- INITIAL COST ----
    
    pair<size_t, size_t> rhs = { 0, 0 };

        // Walk backwards through list to calculate cost and packages on rhs
        // Dont add the last house as that is where the calculations start
    for (size_t house = nHouses; --house; )
    {
        rhs.second += packages[house];      // Add packages of current house
        rhs.first += rhs.second;            // Add one for all packages so far
    }


// ---- FIND MINIMAL COST ----

    pair<size_t, size_t> min = { rhs.first, 0 };    // Tracks minimum cost
                                                    // and house index

    pair<size_t, size_t> lhs = { 0, packages[0] };

        // For every house change the lhs cost and rhs cost with respect
        // to the amount of packages on either side and the amount of
        // packages needed in the next house
    for (size_t house = 1; house != nHouses; ++house)
    {
        lhs.first += lhs.second;                // Adapt lhs pair
        lhs.second += packages[house];
        
        rhs.first -= rhs.second;                // Adapt rhs pair
        rhs.second -= packages[house];

        if (lhs.first + rhs.first < min.first)  // Check if new minimum
        {
            min.first = lhs.first + rhs.first;
            min.second = house;                 // Set new minimum index
        }
    }

    cout << min.second + 1 << '\n';             // Provide the answer
}
