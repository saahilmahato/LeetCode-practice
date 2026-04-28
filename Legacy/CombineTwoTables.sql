/**
 * LeetCode Problem 175: Combine Two Tables
 * 
 * Table: Person
 * +-------------+---------+
 * | Column Name | Type    |
 * +-------------+---------+
 * | personId    | int     |
 * | lastName    | varchar |
 * | firstName   | varchar |
 * +-------------+---------+
 * personId is the primary key (column with unique values) for this table.
 * This table contains information about persons.
 * 
 * Table: Address
 * +-------------+---------+
 * | Column Name | Type    |
 * +-------------+---------+
 * | addressId   | int     |
 * | personId    | int     |
 * | city        | varchar |
 * | state       | varchar |
 * +-------------+---------+
 * addressId is the primary key (column with unique values) for this table.
 * Each row contains address information related to a personId.
 * 
 * Write a SQL query to report the first name, last name, city, and state of each person.
 * If the address of a personId is not present in the Address table, report null instead.
 * 
 * Return the result table in any order.
 * 
 * Example 1:
 *     Input: 
 *     Person table:
 *     +---------+-----------+-----------+
 *     | personId| lastName  | firstName |
 *     +---------+-----------+-----------+
 *     | 1       | Wang      | Allen     |
 *     | 2       | Alice     | Bob       |
 *     +---------+-----------+-----------+
 *     Address table:
 *     +-----------+---------+---------------+-------+
 *     | addressId | personId| city          | state |
 *     +-----------+---------+---------------+-------+
 *     | 1         | 2       | New York City | NY    |
 *     | 2         | 3       | Leetcode      | CA    |
 *     +-----------+---------+---------------+-------+
 *     Output: 
 *     +-----------+-----------+---------------+-------+
 *     | firstName | lastName  | city          | state |
 *     +-----------+-----------+---------------+-------+
 *     | Allen     | Wang      | Null          | Null  |
 *     | Bob       | Alice     | New York City | NY    |
 *     +-----------+-----------+---------------+-------+
 */

-- Solution Query
SELECT
    Person.firstName,
    Person.lastName,
    Address.city,
    Address.state
FROM
    Person
LEFT JOIN
    Address ON Person.personId = Address.personId;

/*
 * Explanation & Study Notes:
 * 
 * Why LEFT JOIN?
 *   - We want all persons from the Person table (left table).
 *   - If a person has no address, city and state should be NULL.
 *   - LEFT JOIN preserves all rows from Person and matches Address where possible.
 *   - INNER JOIN would exclude persons without addresses → incorrect.
 * 
 * Key Points:
 *   - Join condition: Person.personId = Address.personId (foreign key relationship).
 *   - Column selection: Only required columns from both tables.
 *   - No WHERE clause needed → returns all persons.
 *   - Order doesn't matter (problem says "in any order").
 * 
 * Time Complexity:  O(P + A) where P = rows in Person, A = rows in Address (typical join cost)
 * Space Complexity: Depends on DB engine (result set size)
 * 
 * Interview Tips:
 *   - Explain join types: "LEFT JOIN keeps all from left table, NULL for unmatched right."
 *   - Discuss alternatives:
 *     - RIGHT JOIN from Address → more complicated, not needed.
 *     - UNION with NULLs → verbose and inefficient.
 *   - Edge cases:
 *     - Persons with no address → NULL city/state
 *     - Addresses with no person → excluded (not needed per requirements)
 *     - Empty tables
 *   - Common mistake: Using INNER JOIN → misses persons without addresses.
 * 
 * Related Problems to Practice:
 *   - 175. Combine Two Tables (this one)
 *   - 176. Second Highest Salary (NULL handling)
 *   - 181. Employees Earning More Than Their Managers (self-join)
 *   - 182. Duplicate Emails
 *   - 183. Customers Who Never Order (LEFT JOIN with NULL check)
 *   - 196. Delete Duplicate Emails (DELETE with self-join)
 */