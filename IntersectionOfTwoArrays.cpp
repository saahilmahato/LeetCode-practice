/**
 * LeetCode Problem 349: Intersection of Two Arrays
 * 
 * Given two integer arrays nums1 and nums2, return an array of their 
 * intersection. Each element in the result must be unique and you may 
 * return the result in any order.
 * 
 * Example 1:
 *     Input: nums1 = [1,2,2,1], nums2 = [2,2]
 *     Output: [2]
 * 
 * Example 2:
 *     Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 *     Output: [9,4]
 *     Explanation: [4,9] is also accepted.
 * 
 * Constraints:
 *     - 1 <= nums1.length, nums2.length <= 1000
 *     - 0 <= nums1[i], nums2[i] <= 1000
 */

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the intersection of two arrays (unique common elements).
     * 
     * Approach (Hash Set for O(1) lookups):
     *   1. Insert all elements of nums1 into an unordered_set (handles duplicates automatically)
     *   2. Iterate through nums2:
     *      - If element exists in the set → it's a common element
     *      - Insert into a result set (ensures uniqueness)
     *   3. Convert the result set to vector and return
     * 
     * This gives us unique intersection elements in any order.
     * 
     * Time Complexity:  O(n + m) - building set O(n), checking m elements O(m)
     * Space Complexity: O(n + k) - where k is size of intersection (worst O(min(n,m)))
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen(nums1.begin(), nums1.end());
        unordered_set<int> result;
        
        for (int x : nums2) {
            if (seen.count(x)) {
                result.insert(x);
            }
        }
        
        return vector<int>(result.begin(), result.end());
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Hash Set for membership testing
 *   - Deduplication using set properties
 *   - Two-array intersection (set-based)
 * 
 * Key Learnings:
 *   1. unordered_set automatically removes duplicates from nums1
 *   2. Using a second set for result ensures uniqueness (even if nums2 has duplicates)
 *   3. We don't need to sort → any order is fine per problem statement
 *   4. Edge cases to always mention:
 *      - One or both arrays empty → []
 *      - No common elements → []
 *      - One array has 1 element, repeated many times
 *      - Arrays with all same elements (intersection = that element if present)
 *      - nums1 or nums2 size = 1
 * 
 * Interview Tips:
 *   - Start with: "The easiest way is to use a hash set to store one array..."
 *   - Explain why two sets:
 *     "First set removes duplicates from nums1 efficiently.
 *      Second set collects unique matches from nums2."
 *   - Walk through [1,2,2,1] and [2,2]:
 *       seen = {1,2}
 *       check 2 → found → result={2}
 *       check 2 → found → result still {2}
 *       return [2]
 *   - Mention time/space clearly: "O(n + m) time, O(n) space"
 *   - If interviewer asks for sorted output → mention sorting at end (O(k log k))
 *   - Ask clarifying question: "Do we need to preserve frequency or just unique elements?"
 *     (Here: unique → set is perfect)
 * 
 * Alternative Approaches (good to discuss):
 *   1. Sorting both + two pointers (O(n log n + m log m) time, O(1) extra space)
 *   2. Sorting one + binary search for each element in other (O(n log n + m log n))
 *   3. If numbers are small (0–1000), could use bool array / frequency array
 *   4. unordered_map<int, bool> instead of set (similar)
 * 
 * Common Mistakes to Avoid:
 *   - Returning vector with duplicates (forgetting result set)
 *   - Modifying input arrays unnecessarily
 *   - Using set for both (slower O(n log n) if using ordered set)
 *   - Not handling empty arrays
 *   - Returning in specific order when any order is allowed
 * 
 * Related Problems to Practice:
 *   - 349. Intersection of Two Arrays           (this one - unique elements)
 *   - 350. Intersection of Two Arrays II        (with frequency / multiplicity)
 *   - 136. Single Number                        (bitwise / set usage)
 *   - 1.   Two Sum                              (hash map)
 *   - 202. Happy Number                         (cycle detection with set)
 *   - 128. Longest Consecutive Sequence         (clever set usage)
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

void print(const vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;
    
    vector<int> n1 = {1,2,2,1};
    vector<int> n2 = {2,2};
    print(sol.intersection(n1, n2));  // [2]
    
    vector<int> n3 = {4,9,5};
    vector<int> n4 = {9,4,9,8,4};
    print(sol.intersection(n3, n4));  // [9,4] or [4,9]
    
    vector<int> n5 = {1,2};
    vector<int> n6 = {3,4};
    print(sol.intersection(n5, n6));  // []
    
    return 0;
}
*/