-- Write your PostgreSQL query statement below

-- SELECT *
-- FROM Employee m
-- INNER JOIN Employee e ON m.managerId = e.id;

SELECT m.name as Employee
FROM Employee m
INNER JOIN Employee e ON m.managerId = e.id
WHERE m.salary > e.salary;
