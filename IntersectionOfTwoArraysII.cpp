/**
 * LeetCode Problem 350: Intersection of Two Arrays II
 * 
 * Given two integer arrays nums1 and nums2, return an array of their intersection. 
 * Each element in the result must appear as many times as it shows in both arrays, 
 * and you may return the result in any order.
 * 
 * Example 1:
 *     Input: nums1 = [1,2,2,1], nums2 = [2,2]
 *     Output: [2,2]
 * 
 * Example 2:
 *     Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 *     Output: [4,9]
 *     Explanation: [9,4] is also accepted.
 * 
 * Example 3:
 *     Input: nums1 = [1], nums2 = [1,1]
 *     Output: [1]
 * 
 * Constraints:
 *     - 1 <= nums1.length, nums2.length <= 1000
 *     - 0 <= nums1[i], nums2[i] <= 1000
 */

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Finds the intersection of two arrays, respecting multiplicity (frequency).
     * 
     * Approach (Hash Map for Frequency Counting):
     *   1. Count frequency of each element in nums1 using unordered_map
     *   2. Iterate through nums2:
     *      - If the number still has remaining count (> 0) in the map:
     *          - Add it to result
     *          - Decrement its count
     *   3. Result contains min frequency of each common element
     * 
     * This preserves duplicates according to how many times they appear in both arrays.
     * 
     * Time Complexity:  O(n + m) - one pass per array
     * Space Complexity: O(n) - for the frequency map (worst case all unique in nums1)
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> result;
        
        // Count occurrences in nums1
        for (int x : nums1) {
            freq[x]++;
        }
        
        // Collect intersection while respecting counts
        for (int x : nums2) {
            if (freq[x] > 0) {
                result.push_back(x);
                freq[x]--;
            }
        }
        
        return result;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Hash Map for Frequency Counting
 *   - Multiplicity / Duplicate-Preserving Intersection
 *   - "Min frequency" logic across two collections
 * 
 * Key Learnings:
 *   1. We decrement count after adding to result → ensures we don't overuse elements
 *   2. Automatically handles different frequencies → takes min(freq1, freq2)
 *   3. No need for sorting → O(n) time is better than sorting-based O(n log n)
 *   4. Edge cases to always mention:
 *      - One array has more duplicates than the other
 *      - No common elements → []
 *      - One array has length 1
 *      - Both arrays identical → return one of them
 *      - All elements same (e.g. [2,2,2], [2,2]) → [2,2]
 * 
 * Interview Tips:
 *   - Start with: "Since we need to preserve frequency, a frequency map is perfect..."
 *   - Compare with 349 (unique intersection):
 *     "In 349 we used sets for uniqueness; here we use map counts and decrement"
 *   - Walk through [1,2,2,1] and [2,2]:
 *       freq = {1:2, 2:2}
 *       first 2 → add 2, freq[2]=1
 *       second 2 → add 2, freq[2]=0
 *       → [2,2]
 *   - Mention: "Result order follows nums2 appearance order — but any order is allowed"
 *   - If interviewer wants sorted output → mention sort(result) at end
 *   - Ask: "Should the output be sorted? (No — any order is fine)"
 * 
 * Alternative Approaches (good to discuss):
 *   1. Sorting both arrays + two pointers (O(n log n + m log m) time, O(1) extra space)
 *      → Good if interviewer wants O(1) space (excluding output)
 *   2. If values are small (0–1000), use array of size 1001 for counts
 *   3. Put smaller array in map to minimize space
 * 
 * Common Mistakes to Avoid:
 *   - Not decrementing count → overcounts duplicates
 *   - Using set instead of map → loses multiplicity (like 349)
 *   - Pushing back only once per unique value
 *   - Forgetting to check freq[x] > 0
 *   - Returning nums1 or nums2 directly (wrong)
 * 
 * Related Problems to Practice:
 *   - 349. Intersection of Two Arrays            (unique elements)
 *   - 350. Intersection of Two Arrays II         (this one - with frequency)
 *   - 1.   Two Sum                               (hash map)
 *   - 454. 4Sum II                               (frequency map on two arrays)
 *   - 15.  3Sum                                  (sorting + two pointers)
 *   - 18.  4Sum                                  (similar but more complex)
 *   - 1002. Find Common Characters               (frequency intersection on strings)
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
    print(sol.intersect(n1, n2));  // [2,2]
    
    vector<int> n3 = {4,9,5};
    vector<int> n4 = {9,4,9,8,4};
    print(sol.intersect(n3, n4));  // [4,9] or [9,4]
    
    vector<int> n5 = {1};
    vector<int> n6 = {1,1};
    print(sol.intersect(n5, n6));  // [1]
    
    vector<int> n7 = {2,2,2};
    vector<int> n8 = {2};
    print(sol.intersect(n7, n8));  // [2]
    
    return 0;
}
*/