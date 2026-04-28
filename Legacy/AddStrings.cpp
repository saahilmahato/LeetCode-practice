/*
===============================================================================
415. Add Strings

Problem Description:
--------------------
Given two non-negative integers num1 and num2 represented as strings,
return their sum as a string.

You must solve the problem WITHOUT:
    - Converting the entire strings to integers
    - Using built-in big integer libraries

Constraints:
------------
- 1 <= num1.length, num2.length <= 10^4
- num1 and num2 consist only of digits.
- Both numbers do not contain leading zeros (except "0" itself).

Example:
--------
Input:  num1 = "11", num2 = "123"
Output: "134"

Goal:
-----
Simulate manual addition (like we do on paper)
from right to left.

===============================================================================
*/

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {

        // Pointers starting from the end (least significant digits)
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        // Carry for addition (just like in manual math)
        int carry = 0;

        // Result will be built in reverse order initially
        string result;

        // Continue until:
        // 1) Both strings are fully processed
        // 2) No carry remains
        while (i >= 0 || j >= 0 || carry) {

            // Extract current digits (if index valid)
            int digit1 = i >= 0 ? num1[i--] - '0' : 0;
            int digit2 = j >= 0 ? num2[j--] - '0' : 0;

            // Compute sum of digits and carry
            int sum = digit1 + digit2 + carry;

            // Update carry
            carry = sum / 10;

            // Store current digit (mod 10)
            result.push_back((sum % 10) + '0');
        }

        // Reverse result since digits were added from right to left
        reverse(result.begin(), result.end());

        return result;
    }
};


/*
===============================================================================
DSA PATTERNS USED:
------------------
1) Two-Pointer Technique (Reverse Traversal)
2) Simulation of Manual Arithmetic
3) Carry Handling Logic
4) String Manipulation

STRATEGY EXPLANATION:
---------------------
- Start from the least significant digit (end of string).
- Add corresponding digits along with carry.
- Append result digit.
- Move left.
- Reverse at the end.

Why We Build in Reverse:
------------------------
We process digits from right to left.
Appending to string is O(1).
Reversing once at the end is efficient.

Time Complexity:
----------------
O(max(n, m))

Where:
n = length of num1
m = length of num2

Space Complexity:
-----------------
O(max(n, m)) for result storage.

WHY NOT CONVERT TO INTEGER?
---------------------------
- Numbers can be up to 10^4 digits long.
- They exceed built-in integer limits.
- Problem explicitly restricts using BigInteger.

INTERVIEW TIPS:
---------------
- Say: "We simulate grade-school addition."
- Mention carry handling explicitly.
- Explain why loop condition includes carry.
- Clarify edge case like:
      num1 = "999", num2 = "1"
  Result should be "1000".

EDGE CASES:
-----------
- Different length strings
- Final carry remaining
- One string is "0"
- Very large numbers

SIMILAR QUESTIONS:
------------------
- Multiply Strings
- Add Binary
- Subtract Strings
- Plus One
- Big Integer Arithmetic
- String Based Calculator Problems

PATTERN TAKEAWAY:
-----------------
"When numbers exceed built-in limits, simulate arithmetic manually."

===============================================================================
*/