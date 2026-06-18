package arrays;

import java.util.HashMap;
import java.util.Map;

/**
 * LeetCode 1: Two Sum
 * * Problem Statement:
 * Given an array of integers 'nums' and an integer 'target', return indices of the 
 * two numbers such that they add up to 'target'.
 * * You may assume that each input would have exactly one solution, and you may not 
 * use the same element twice.
 */
public class TwoSum {

    /**
     * Approach 1: Brute Force
     * 
     * Intuition:
     * Check every possible pair of numbers in the array to see if their sum matches the target.
     * 
     * Time Complexity: O(N^2) - Two nested loops scan through the array.
     * Space Complexity: O(1) - No auxiliary memory used.
     * 
     * @param nums   Array of integers.
     * @param target Target sum to find.
     * @return       An array containing the two indices, or an empty array if no solution exists.
     */
    public int[] twoSumBruteForce(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            // j starts at i + 1 to avoid pairing an element with itself
            for (int j = i + 1; j < nums.length; j++) {
                // FIXED: Changed nums[i] + nums[i] to nums[i] + nums[j]
                if (nums[i] + nums[j] == target) {
                    return new int[] {i, j};
                }
            }
        }
        return new int[] {}; // Return empty array if no pair is found
    }

    /**
     * Approach 2: One-Pass Hash Map (Optimal)
     * 
     * Intuition:
     * As we iterate through the array, we can calculate the 'complement' needed to reach 
     * the target (complement = target - current_value). If that complement already exists 
     * in our lookup table (HashMap), we've found our pair! Otherwise, we store the current 
     * number and its index in the map and keep moving forward.
     * 
     * Time Complexity: O(N) - We traverse the list containing N elements exactly once. 
     * Lookups in a HashMap take O(1) time on average.
     * Space Complexity: O(N) - In the worst case, we might store up to N elements in the map.
     * 
     * @param nums   Array of integers.
     * @param target Target sum to find.
     * @return       An array containing the two indices, or an empty array if no solution exists.
     */
    public int[] twoSumOptimal(int[] nums, int target) {
        // Map to store: Key = Number value, Value = Index of that number
        Map<Integer, Integer> seen = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];

            // If the complement is already in the map, we found our match
            if (seen.containsKey(complement)) {
                // FIXED: Added missing 'new' keyword before int[]
                return new int[] {seen.get(complement), i};
            }

            // Otherwise, track the current number and its index for future elements to use
            seen.put(nums[i], i);
        }

        return new int[] {}; // Return empty array if no pair is found
    }
}