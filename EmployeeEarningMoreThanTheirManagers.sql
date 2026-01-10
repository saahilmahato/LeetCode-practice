/**
 * LeetCode Problem 181: Employees Earning More Than Their Managers
 * 
 * Table: Employee
 * +-------------+---------+
 * | Column Name | Type    |
 * +-------------+---------+
 * | id          | int     |
 * | name        | varchar |
 * | salary      | int     |
 * | managerId   | int     |
 * +-------------+---------+
 * id is the primary key (column with unique values) for this table.
 * Each row of this table indicates the ID of an employee, their name, salary,
 * and the ID of their manager (managerId can be null for top-level employees).
 * 
 * Write an SQL query to find the employees who earn more than their managers.
 * 
 * Return the result table in any order.
 * 
 * Example 1:
 *     Input: 
 *     Employee table:
 *     +----+-------+--------+-----------+
 *     | id | name  | salary | managerId |
 *     +----+-------+--------+-----------+
 *     | 1  | Joe   | 70000  | 3         |
 *     | 2  | Henry | 80000  | 4         |
 *     | 3  | Sam   | 60000  | Null      |
 *     | 4  | Max   | 90000  | Null      |
 *     +----+-------+--------+-----------+
 *     Output: 
 *     +----------+
 *     | Employee |
 *     +----------+
 *     | Joe      |
 *     +----------+
 *     Explanation: Joe (id=1) earns 70000 > Sam's 60000 (manager id=3).
 * 
 * Example 2:
 *     Input: 
 *     Employee table:
 *     +----+-------+--------+-----------+
 *     | id | name  | salary | managerId |
 *     +----+-------+--------+-----------+
 *     | 1  | John  | 1000   | Null      |
 *     | 2  | Dan   | 2000   | 1         |
 *     | 3  | Brad  | 2000   | 1         |
 *     | 4  | Thomas| 3000   | 2         |
 *     +----+-------+--------+-----------+
 *     Output: 
 *     +----------+
 *     | Employee |
 *     +----------+
 *     | Dan      |
 *     | Brad     |
 *     | Thomas   |
 *     +----------+
 */

-- Solution Query
SELECT 
    e.name AS Employee
FROM 
    Employee e
JOIN 
    Employee m ON e.managerId = m.id
WHERE 
    e.salary > m.salary;

-- Alternative with explicit INNER JOIN (same result)
-- SELECT 
--     e.name AS Employee
-- FROM 
--     Employee e
-- INNER JOIN 
--     Employee m ON e.managerId = m.id
-- WHERE 
--     e.salary > m.salary;

/*
 * Explanation & Study Notes:
 * 
 * Why INNER JOIN?
 *   - We only want employees who have a manager (managerId not null).
 *   - JOIN (or INNER JOIN) automatically excludes rows where no matching manager exists.
 *   - Self-join on the same table: alias e for employee, m for manager.
 * 
 * Key Points:
 *   - Condition e.managerId = m.id links employee to their manager.
 *   - Filter e.salary > m.salary finds those earning more.
 *   - Select only employee's name, aliased as "Employee".
 *   - No ORDER BY needed (any order accepted).
 * 
 * Performance:
 *   - Time: O(n) typical for join on indexed id/managerId.
 *   - Ensure indexes on id (PK) and managerId for efficiency.
 * 
 * Interview Tips:
 *   - Explain self-join: "We join the table to itself to compare employee vs manager."
 *   - Discuss why not LEFT JOIN: "LEFT would include employees without managers,
 *     but manager salary would be NULL → comparison false anyway."
 *   - Edge cases:
 *     - Employees with no manager (managerId NULL) → excluded
 *     - Equal salaries → excluded (strict >)
 *     - Top-level managers → no row
 *     - All earn less → empty result
 *   - Common mistake: Forgetting alias → ambiguous column names.
 * 
 * Related Problems to Practice:
 *   - 181. Employees Earning More Than Their Managers (this one)
 *   - 175. Combine Two Tables (LEFT JOIN)
 *   - 176. Second Highest Salary
 *   - 177. Nth Highest Salary
 *   - 178. Rank Scores
 *   - 180. Consecutive Numbers
 *   - 184. Department Highest Salary (similar self-join pattern)
 */