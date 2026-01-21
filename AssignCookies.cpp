/**
 * LeetCode Problem 455: Assign Cookies
 * 
 * Assume you are an awesome parent and want to give your children some cookies. 
 * But, you should give each child at most one cookie.
 * 
 * Each child i has a greed factor g[i], which is the minimum size of a cookie 
 * that the child will be content with; and each cookie j has a size s[j]. 
 * If s[j] >= g[i], we can assign the cookie j to the child i, and the child i 
 * will be content. Your goal is to maximize the number of your content children 
 * and output the maximum number.
 * 
 * Example 1:
 *     Input: g = [1,2,3], s = [1,1]
 *     Output: 1
 *     Explanation: You have 3 children and 2 cookies. The greed factors of 3 
 *                  children are 1, 2, 3. You have two cookies of size 1. 
 *                  You can only make the child whose greed factor is 1 content.
 * 
 * Example 2:
 *     Input: g = [1,2], s = [1,2,3]
 *     Output: 2
 *     Explanation: You have 2 children and 3 cookies. The greed factors of 2 
 *                  children are 1, 2. You have three cookies of sizes 1, 2, 3. 
 *                  You can assign cookie 1 to child 1 and cookie 2 to child 2.
 * 
 * Constraints:
 *     - 1 <= g.length <= 3 * 10^4
 *     - 1 <= s.length <= 3 * 10^4
 *     - 1 <= g[i], s[j] <= 2^31 - 1
 */

#include <vector>
#include <algorithm>  // for std::sort
using namespace std;

class Solution {
public:
    /**
     * Maximizes the number of content children by assigning cookies greedily.
     * 
     * Approach (Greedy + Two Pointers after Sorting):
     *   1. Sort both arrays:
     *      - g: children's greed factors (ascending)
     *      - s: cookie sizes (ascending)
     *   2. Use two pointers:
     *      - i: current child
     *      - j: current cookie
     *   3. For each child (from smallest greed):
     *      - Find the smallest cookie that can satisfy them (s[j] >= g[i])
     *      - If found → assign, move to next child and next cookie
     *      - If not → skip this cookie (too small), try next cookie
     *   4. Count how many children get satisfied
     * 
     * Why it works:
     *   - Smallest possible cookie for smallest greed child → saves larger cookies
     *     for greedier children later
     *   - Greedy choice property holds
     * 
     * Time Complexity:  O(n log n + m log m) - sorting dominates
     * Space Complexity: O(1) - extra space (excluding input/output)
     */
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0;          // pointer for children
        int j = 0;          // pointer for cookies
        int satisfied = 0;
        
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // This cookie can satisfy current child
                satisfied++;
                i++;  // move to next child
                j++;  // move to next cookie
            } else {
                // Cookie too small for this child → discard it
                j++;
            }
        }
        
        return satisfied;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Greedy Algorithm
 *   - Two Pointers on Sorted Arrays
 *   - Assignment / Matching Problem
 * 
 * Key Learnings:
 *   1. Sorting both arrays is crucial — allows greedy matching
 *   2. Always try to satisfy smallest greed child first
 *   3. If cookie can't satisfy current child, it can't satisfy any later (larger) child
 *   4. Edge cases to always mention:
 *      - No cookies → 0
 *      - No children → 0
 *      - All cookies smaller than smallest child → 0
 *      - More cookies than children → limited by children count
 *      - All children can be satisfied
 * 
 * Interview Tips:
 *   - Say: "This is a classic greedy problem — we should assign smallest possible cookies 
 *     to smallest greed children to maximize assignments."
 *   - Explain why sorting works: "After sorting, we can match greedily from left to right."
 *   - Walk through [1,2,3] children and [1,1] cookies:
 *       i=0 (g=1), j=0 (s=1) → 1>=1 → satisfied=1, i=1, j=1
 *       i=1 (g=2), j=1 (s=1) → 1<2 → j=2 (end)
 *       → return 1
 *   - Time complexity: "O(n log n) due to sorting — acceptable for n ≤ 3×10^4"
 *   - Alternative: Could use multiset or priority queue → slower & more complex
 * 
 * Common Mistakes to Avoid:
 *   - Not sorting one or both arrays
 *   - Trying to assign largest cookie first (greedy fails)
 *   - Incrementing i when cookie is too small (misses later children)
 *   - Using extra space unnecessarily (e.g. map or vector copy)
 *   - Forgetting to handle empty inputs
 * 
 * Related Problems to Practice:
 *   - 455. Assign Cookies                        (this one)
 *   - 435. Non-overlapping Intervals             (greedy sorting)
 *   - 452. Minimum Number of Arrows to Burst Balloons
 *   - 763. Partition Labels
 *   - 406. Queue Reconstruction by Height        (greedy + sorting)
 *   - 621. Task Scheduler                        (greedy with priority)
 *   - 846. Hand of Straights                     (similar greedy assignment)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

int main() {
    Solution sol;
    
    vector<int> g1 = {1,2,3};
    vector<int> s1 = {1,1};
    std::cout << sol.findContentChildren(g1, s1) << std::endl;  // 1
    
    vector<int> g2 = {1,2};
    vector<int> s2 = {1,2,3};
    std::cout << sol.findContentChildren(g2, s2) << std::endl;  // 2
    
    vector<int> g3 = {10,9,8,7};
    vector<int> s3 = {5,6,7,8};
    std::cout << sol.findContentChildren(g3, s3) << std::endl;  // 2
    
    return 0;
}
*/