import java.util.Map;

public class TwoSum {
    public int[] twoSumBruteForce(int nums[], int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[i] == target) {
                    return new int[] {i, j};
                }
            }
        }

        return new int[] {};
    }

    public int[] twoSumOptimal(int nums[], int target) {
        Map<Integer, Integer> seen = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];

            if (seen.containsKey(complement)) {
                return int[] {i, seen.get(complement)};
            }

            seen.put(nums[i], i);
        }

        return new int[] {};
    }
}