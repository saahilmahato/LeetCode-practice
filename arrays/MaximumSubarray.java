package arrays;

/**
 * LeetCode 53: Maximum Subarray
 * 
 * Problem Statement:
 * Given an integer array 'nums', find the contiguous subarray (containing at least one number) 
 * which has the largest sum and return its sum.
 */
class MaximumSubarray {

    /**
     * Approach 1: Brute Force
     * 
     * Intuition:
     * Check the sum of every single possible contiguous subarray. The outer loop sets the 
     * starting boundary, and the inner loop expands the ending boundary while keeping a 
     * running sum.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(N^2) - Two nested loops traverse the array to compute all subarray sums.
     * Will result in Time Limit Exceeded (TLE) on large datasets.
     * - Space Complexity: O(1) - Only a few primitive variables used for tracking sums.
     * 
     * @param nums Array of integers.
     * @return     The maximum contiguous subarray sum.
     */
    public int maxSubArrayBruteForce(int[] nums) {
        int maxSum = Integer.MIN_VALUE;

        for (int i = 0; i < nums.length; i++) {
            int currentSum = 0;
            for (int j = i; j < nums.length; j++) {
                currentSum += nums[j];
                maxSum = Math.max(maxSum, currentSum);
            }
        }
        return maxSum;
    }

    /**
     * Approach 2: Divide and Conquer
     * 
     * Intuition:
     * Split the array into two halves recursively. The maximum subarray must reside completely 
     * within one of three places:
     * 1. Entirely in the left half.
     * 2. Entirely in the right half.
     * 3. Crossing through the midpoint (includes elements from both left and right halves).
     * 
     * Complexity Analysis:
     * - Time Complexity: O(N log N) - The array is split in half at each step (log N levels), 
     * and at each level, the linear findCrossingMax takes O(N) time.
     * - Space Complexity: O(log N) - Due to the recursive call stack depth.
     * 
     * @param nums Array of integers.
     * @return     The maximum contiguous subarray sum.
     */
    public int maxSubArrayDivideAndConquer(int[] nums) {
        return findMaxSubArray(nums, 0, nums.length - 1);
    }

    /**
     * Helper method to recursively execute the Divide and Conquer strategy.
     */
    private int findMaxSubArray(int[] nums, int left, int right) {
        // Base case: Subarray contains only one element
        if (left == right) {
            return nums[left];
        }

        int mid = left + (right - left) / 2;

        // Find max subarray sum in left half, right half, and crossing the midpoint
        int leftMax = findMaxSubArray(nums, left, mid);
        int rightMax = findMaxSubArray(nums, mid + 1, right);
        int crossMax = findCrossingMax(nums, left, mid, right);

        // Return the best of the three scenarios
        return Math.max(Math.max(leftMax, rightMax), crossMax);
    }

    /**
     * Helper method to find the maximum subarray sum that crosses the midpoint.
     * It scans outward from the midpoint to both the left and right boundaries.
     */
    private int findCrossingMax(int[] nums, int left, int mid, int right) {
        // Left part of the crossing sum (going from mid down to left)
        int leftSum = Integer.MIN_VALUE;
        int sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            if (sum > leftSum) {
                leftSum = sum;
            }
        }

        // Right part of the crossing sum (going from mid+1 up to right)
        int rightSum = Integer.MIN_VALUE;
        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            if (sum > rightSum) {
                rightSum = sum;
            }
        }

        // Combine the best left and right portions crossing the midpoint
        return leftSum + rightSum;
    }

    /**
     * Approach 3: Kadane's Algorithm (Optimal)
     * 
     * Intuition:
     * Iterate through the array while maintaining a running local max sum (`currentSum`). At each 
     * index, we face a choice: Is it better to add the current element to our existing running 
     * subarray, or discard the past entirely and start a brand new subarray starting at the 
     * current element? We choose the maximum of these two paths and globally record the best total seen.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(N) - We perform a single, efficient linear scan through the array.
     * - Space Complexity: O(1) - Only constant extra memory used to track maximum values.
     * 
     * @param nums Array of integers.
     * @return     The maximum contiguous subarray sum.
     */
    public int maxSubArrayKadane(int[] nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            // Decide whether to add the current element to the existing subarray,
            // or start a brand new subarray from the current element.
            currentSum = Math.max(nums[i], currentSum + nums[i]);
            maxSum = Math.max(maxSum, currentSum);
        }

        return maxSum;
    }
}