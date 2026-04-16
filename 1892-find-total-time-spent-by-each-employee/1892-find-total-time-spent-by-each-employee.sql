# Write your MySQL query statement below
SELECT event_day AS day, emp_id,SUM(spent) AS total_time
FROM (SELECT *,(out_time-in_time) AS spent
FROM Employees) t
GROUP BY emp_id,event_day
