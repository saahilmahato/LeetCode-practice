/**
 * LeetCode Problem 278: First Bad Version
 * 
 * You are a product manager and currently leading a team to develop a new product.
 * Unfortunately, the latest version of your product failed the quality check.
 * Since each version is developed based on the previous version, all the versions
 * after a bad version are also bad.
 * 
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first
 * bad one, which causes all the following ones to be bad.
 * 
 * You are given an API bool isBadVersion(version) which returns whether version
 * is bad. Implement a function to find the first bad version.
 * 
 * You should minimize the number of calls to the API.
 * 
 * Example 1:
 *     Input: n = 5, isBadVersion(4) = true
 *     Output: 4
 *     Explanation:
 *     version 1 = good
 *     version 2 = good
 *     version 3 = good
 *     version 4 = bad     ← first bad version
 *     version 5 = bad
 * 
 * Example 2:
 *     Input: n = 1
 *     Output: 1
 * 
 * Constraints:
 *     - 1 <= n <= 2^31 - 1
 *     - There is at least one bad version
 *     - The first bad version is somewhere in [1, n]
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    /**
     * Finds the first bad version using binary search.
     * 
     * Approach (Binary Search):
     *   - Use two pointers: left = 1, right = n
     *   - While left < right:
     *       - mid = left + (right - left) / 2   (avoid integer overflow)
     *       - If isBadVersion(mid) is true  → first bad version is at mid or before → right = mid
     *       - Else → first bad version is after mid → left = mid + 1
     *   - When loop ends, left == right and points to the first bad version
     * 
     * Key points:
     *   - We keep the search space inclusive of possible answers
     *   - We bias towards the left when we find a bad version
     * 
     * Time Complexity:  O(log n) - classic binary search
     * Space Complexity: O(1) - only a few variables
     */
    int firstBadVersion(int n) {
        long left = 1;          // avoid int overflow on large n
        long right = n;
        
        while (left < right) {
            long mid = left + (right - left) / 2;
            
            if (isBadVersion(mid)) {
                // Bad version found → look in left half (including mid)
                right = mid;
            } else {
                // Good version → first bad must be after mid
                left = mid + 1;
            }
        }
        
        // When loop ends, left == right == first bad version
        return left;
    }
};

/*
 * Study Notes & Interview Tips:
 * 
 * DSA Pattern:
 *   - Binary Search on Answer
 *   - Finding First True in a Sorted Sequence
 *   - Minimize API calls (classic binary search property)
 * 
 * Key Learnings:
 *   1. This is **binary search on a monotonic condition**:
 *      Once a version is bad → all later versions are bad
 *   2. Use long for left/right/mid to prevent overflow when n = 2^31 - 1
 *   3. Prefer left + (right - left) / 2 over (left + right) / 2
 *   4. When we find a bad version, we still need to check if there's an earlier one → right = mid
 *   5. When loop ends (left == right), that is the first bad version
 *   6. Edge cases:
 *      - n = 1                → 1 is bad
 *      - First version is bad → return 1
 *      - Last version is bad  → return n
 *      - All versions good except last → return n
 * 
 * Interview Tips:
 *   - Clarify: "Is version 1 guaranteed to exist? Is there always at least one bad version?"
 *   - Explain monotonicity: "Good → Good → Bad → Bad → Bad"
 *   - Mention why we set right = mid (not mid-1) → we want to include mid in next search
 *   - Talk about overflow: "On 32-bit int, (left + right) can overflow when both are large"
 *   - State time complexity clearly: "O(log n) calls to isBadVersion()"
 *   - Alternative wording: "We're finding the smallest number x such that isBadVersion(x) is true"
 * 
 * Common Mistakes to Avoid:
 *   - Returning mid instead of left/right
 *   - Using right = mid - 1 when bad version found (misses the answer)
 *   - Using int instead of long for pointers (overflow risk)
 *   - Using (left + right) / 2 without overflow protection
 * 
 * Related Problems to Practice:
 *   - 278. First Bad Version               (this one)
 *   - 704. Binary Search                   (standard)
 *   - 33.   Search in Rotated Sorted Array
 *   - 153.  Find Minimum in Rotated Sorted Array
 *   - 875.  Koko Eating Bananas            (binary search on answer)
 *   - 410.  Split Array Largest Sum        (binary search on answer)
 *   - 1482. Minimum Number of Days to Make m Bouquets
 */

// Example usage (uncomment to test locally)
/*
#include <iostream>

bool isBadVersion(int version) {
    // For testing only - pretend version 4 is the first bad one
    return version >= 4;
}

int main() {
    Solution sol;
    
    std::cout << sol.firstBadVersion(5) << std::endl;   // 4
    std::cout << sol.firstBadVersion(1) << std::endl;   // 1
    std::cout << sol.firstBadVersion(10) << std::endl;  // 4 (assuming same mock)
    
    return 0;
}
*/