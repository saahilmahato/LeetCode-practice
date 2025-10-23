#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }

        std::string prefix = strs[0];

        for (int i=1; i<strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) {
                    return "";
                }
            }
        }

        return prefix;
    }
};

// 🔍 NOTE:
// strs[i].find(prefix) checks whether the current string contains `prefix`.
//
// - std::string::find(substring) returns the index of the first occurrence of `substring`.
// - If the substring is not found, it returns std::string::npos (a large unsigned value).
// - Therefore, `strs[i].find(prefix) != 0` means the current string does NOT start with the prefix.
//
// In this algorithm, we only care if the prefix appears at the *start* of each word.
// Hence, we keep shortening the prefix until `find(prefix)` returns 0,
// meaning `strs[i]` begins with `prefix`.
//
// ✅ Example:
// "flow".find("flo") → 0      (prefix matches start)
// "flow".find("low") → 1      (prefix starts later, not valid for LCP)
// "flow".find("xyz") → npos   (not found at all)
//
// 🧠 In modern C++20 and above, this logic can be simplified using:
// if (!strs[i].starts_with(prefix)) { ... }
// which is more readable and avoids using find() directly.


/*
 * 🎯 Problem: Longest Common Prefix (LeetCode #14)
 * ------------------------------------------------
 * Given an array of strings, find the longest common prefix shared among them.
 * If no common prefix exists, return an empty string.
 *
 * 💡 What You Learn / Key Takeaways
 * ---------------------------------
 * 1. **Incremental Constraint Narrowing**
 *    - Start with the *entire first string* as a possible prefix, 
 *      then gradually shrink it until it fits all others.
 *    - Teaches a **constraint reduction** mindset: start broad, 
 *      tighten based on conflicts.
 *    - Mirrors the "reduce search space" idea in optimization problems.
 *
 * 2. **Prefix Checking via `find()`**
 *    - Smart use of `str.find(prefix) == 0` to test if a string starts with a prefix.
 *    - Reinforces understanding of C++ string search semantics.
 *    - Introduces efficient string matching without manually looping characters.
 *
 * 3. **Iterative Refinement Pattern**
 *    - Common strategy:
 *        → Assume an answer (prefix)
 *        → Validate against each input
 *        → Trim until it works
 *    - A form of *incremental validation*, widely useful in text and pattern problems.
 *
 * 4. **Early Exit Thinking**
 *    - If prefix becomes empty → no need to continue.
 *    - Encourages writing **fail-fast** loops to avoid wasted computation.
 *    - Transferable to many iterative pruning problems.
 *
 * 5. **String Manipulation Proficiency**
 *    - Hands-on experience with:
 *        → `substr()` for controlled truncation
 *        → `find()` for prefix checks
 *        → Handling edge cases like empty vectors
 *    - Builds familiarity with real-world C++ string operations.
 *
 * 6. **Pattern Generalization**
 *    - Equivalent logic shows up in:
 *        → DNA sequence comparison
 *        → File path or URL prefix matching
 *        → Version or namespace name resolution
 *    - Strengthens pattern recognition in string matching domains.
 *
 * 7. **Alternative Perspectives**
 *    - Horizontal scanning (current approach): compare across words.
 *    - Vertical scanning: compare character by character down the list.
 *    - Divide and conquer: recursively find prefixes in halves.
 *    - Binary search on prefix length: optimization for large datasets.
 *    - Encourages exploring *multiple solution paradigms* for one problem.
 *
 * 🧩 Broader Applications
 * -----------------------
 * - Text autocomplete systems (common prefix lookup)
 * - Trie-based algorithms (common prefix compression)
 * - Search query optimization (prefix matching)
 *
 * 🚀 Bonus Insight
 * ----------------
 * - Shows how a simple concept (shared prefix) 
 *   can be attacked with multiple algorithmic patterns (scanning, recursion, binary search).
 * - Builds intuition for **pattern shrinking**, **prefix validation**, and **string safety**.
 *
 * TL;DR: Longest Common Prefix teaches **iterative constraint reduction**, 
 * **efficient string comparison**, and **multi-approach problem solving** —
 * essential for mastering text-processing and search logic.
 */
