# Write your MySQL query statement below
WITH temp AS (
    SELECT *,DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS rnk
    FROM Employee
)

SELECT d.name AS Department,e.name AS Employee, e.salary AS Salary
FROM temp e
JOIN Department d ON d.id=e.departmentId
WHERE rnk=1