/**
 * LeetCode Problem 183: Customers Who Never Order
 * 
 * Table: Customers
 * +----+-------+
 * | Id | Name  |
 * +----+-------+
 * | 1  | Joe   |
 * | 2  | Henry |
 * | 3  | Sam   |
 * | 4  | Max   |
 * +----+-------+
 * Id is the primary key column for this table.
 * Each row of this table contains the ID and name of a customer.
 * 
 * Table: Orders
 * +----+------------+
 * | Id | CustomerId |
 * +----+------------+
 * | 1  | 3          |
 * | 2  | 1          |
 * +----+------------+
 * Id is the primary key column for this table.
 * CustomerId is a foreign key referencing the Id from Customers.
 * Each row indicates that the customer with that CustomerId placed an order with that Id.
 * 
 * Write an SQL query to report all customers who never placed any order.
 * 
 * Return the result table in any order.
 * 
 * Example 1:
 *     Input: 
 *     Customers table:
 *     +----+-------+
 *     | Id | Name  |
 *     +----+-------+
 *     | 1  | Joe   |
 *     | 2  | Henry |
 *     | 3  | Sam   |
 *     | 4  | Max   |
 *     +----+-------+
 *     Orders table:
 *     +----+------------+
 *     | Id | CustomerId |
 *     +----+------------+
 *     | 1  | 3          |
 *     | 2  | 1          |
 *     +----+------------+
 *     Output: 
 *     +-------+
 *     | Name  |
 *     +-------+
 *     | Henry |
 *     | Max   |
 *     +-------+
 */

-- Solution Query
SELECT 
    c.name AS Customers
FROM 
    Customers c
LEFT JOIN 
    Orders o ON c.id = o.customerId
WHERE 
    o.id IS NULL;

-- Alternative (using any Orders column that would be NULL for unmatched customers)
-- SELECT 
--     c.name AS Customers
-- FROM 
--     Customers c
-- LEFT JOIN 
--     Orders o ON c.id = o.customerId
-- WHERE 
--     o.customerId IS NULL;

/*
 * Explanation & Study Notes:
 * 
 * Why LEFT JOIN + WHERE o.id IS NULL?
 *   - LEFT JOIN keeps all customers from Customers table.
 *   - For customers with no orders, all columns from Orders will be NULL.
 *   - Filtering WHERE o.id IS NULL selects only those with no matching orders.
 *   - This is the standard way to find "not exists" or "never ordered".
 * 
 * Key Points:
 *   - Join on c.id = o.customerId (foreign key relationship).
 *   - Select only customer name, aliased as "Customers".
 *   - No ORDER BY needed (any order accepted).
 *   - Using o.id IS NULL or o.customerId IS NULL works the same.
 * 
 * Performance:
 *   - Time: O(C + O) typical for join (C = customers, O = orders).
 *   - Index on Orders.customerId recommended for efficiency.
 * 
 * Interview Tips:
 *   - Explain: "LEFT JOIN includes all customers, then filter unmatched (NULL in Orders)."
 *   - Discuss alternatives:
 *     - NOT EXISTS subquery:
 *       SELECT name AS Customers
 *       FROM Customers c
 *       WHERE NOT EXISTS (
 *         SELECT 1 FROM Orders o WHERE o.customerId = c.id
 *       );
 *     - NOT IN (careful with NULLs):
 *       SELECT name FROM Customers
 *       WHERE id NOT IN (SELECT customerId FROM Orders WHERE customerId IS NOT NULL);
 *   - Why LEFT JOIN preferred: Clear, readable, efficient.
 *   - Edge cases:
 *     - No customers → empty
 *     - All customers ordered → empty
 *     - Customers with no orders
 *     - Orders with invalid customerId → ignored
 *   - Common mistake: INNER JOIN → returns only customers who ordered.
 * 
 * Related Problems to Practice:
 *   - 183. Customers Who Never Order (this one)
 *   - 175. Combine Two Tables (LEFT JOIN basics)
 *   - 181. Employees Earning More Than Their Managers (self-join)
 *   - 182. Duplicate Emails (GROUP BY + HAVING)
 *   - 196. Delete Duplicate Emails (DELETE with self-join)
 *   - 197. Rising Temperature (self-join on date)
 */