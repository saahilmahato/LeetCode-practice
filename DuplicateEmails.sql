/**
 * LeetCode Problem 182: Duplicate Emails
 * 
 * Table: Person
 * +----+---------+
 * | Id | Email   |
 * +----+---------+
 * | 1  | a@b.com |
 * | 2  | c@d.com |
 * | 3  | a@b.com |
 * +----+---------+
 * Id is the primary key column for this table.
 * Each row of this table contains an email. The emails will not contain uppercase letters.
 * 
 * Write an SQL query to report all the duplicate emails.
 * Return the result table in any order.
 * 
 * Example 1:
 *     Input: 
 *     Person table:
 *     +----+---------+
 *     | Id | Email   |
 *     +----+---------+
 *     | 1  | a@b.com |
 *     | 2  | c@d.com |
 *     | 3  | a@b.com |
 *     +----+---------+
 *     Output: 
 *     +---------+
 *     | Email   |
 *     +---------+
 *     | a@b.com |
 *     +---------+
 * 
 * Example 2:
 *     Input: 
 *     Person table:
 *     +----+---------+
 *     | Id | Email   |
 *     +----+---------+
 *     | 1  | a@b.com |
 *     | 2  | a@b.com |
 *     | 3  | a@b.com |
 *     +----+---------+
 *     Output: 
 *     +---------+
 *     | Email   |
 *     +---------+
 *     | a@b.com |
 *     +---------+
 */

-- Solution Query
SELECT 
    email AS Email
FROM 
    Person
GROUP BY 
    email
HAVING 
    COUNT(email) > 1;

-- Alternative using COUNT(*)
-- SELECT 
--     email AS Email
-- FROM 
--     Person
-- GROUP BY 
--     email
-- HAVING 
--     COUNT(*) > 1;

/*
 * Explanation & Study Notes:
 * 
 * Why GROUP BY + HAVING?
 *   - GROUP BY email groups rows with the same email.
 *   - HAVING filters groups → keeps only those with count > 1.
 *   - SELECT email returns each duplicate email once.
 *   - COUNT(email) or COUNT(*) works the same here (no NULL emails per constraints).
 * 
 * Key Points:
 *   - Emails are case-sensitive? Problem says "will not contain uppercase" → but query is case-sensitive.
 *     In practice, emails are case-insensitive, but problem treats as case-sensitive.
 *   - No ORDER BY needed (any order accepted).
 *   - Id is PK → unique, but we group by email.
 * 
 * Performance:
 *   - Time: O(n log n) typical with group by (sort-based)
 *   - Index on email would speed up grouping.
 * 
 * Interview Tips:
 *   - Explain: "Group by email, filter groups with more than one row."
 *   - Discuss alternatives:
 *     - Window function: ROW_NUMBER() OVER (PARTITION BY email ORDER BY id) > 1
 *     - Self-join: Person p1 JOIN Person p2 ON p1.email = p2.email AND p1.id != p2.id
 *   - Edge cases:
 *     - No duplicates → empty result
 *     - All duplicates
 *     - Single row
 *     - Mixed case emails (problem guarantees lowercase)
 *   - Common mistake: Using WHERE instead of HAVING → syntax error (WHERE before GROUP BY).
 * 
 * Related Problems to Practice:
 *   - 182. Duplicate Emails (this one)
 *   - 183. Customers Who Never Order (LEFT JOIN + NULL)
 *   - 196. Delete Duplicate Emails (DELETE with self-join/window)
 *   - 197. Rising Temperature (self-join with date)
 *   - 596. Classes More Than 5 Students (GROUP BY + HAVING)
 *   - 620. Not Boring Movies (filters with GROUP BY)
 */