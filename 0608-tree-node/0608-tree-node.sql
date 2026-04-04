# Write your MySQL query statement below
SELECT id,CASE
                WHEN p_id IS NULL THEN 'Root'
                WHEN id IN (SELECT t1.id FROM Tree t1 JOIN Tree t2 ON t1.id=t2.p_id) THEN 'Inner'
                ELSE 'Leaf'
                END AS type
FROM Tree