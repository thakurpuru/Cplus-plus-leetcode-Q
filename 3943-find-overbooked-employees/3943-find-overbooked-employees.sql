WITH temp AS (
SELECT employee_id, SUM(duration_hours) AS total
FROM meetings
GROUP BY employee_id, WEEKOFYEAR(meeting_date), YEAR(meeting_date)
)

SELECT t.employee_id,e.employee_name,e.department,COUNT(t.employee_id) AS meeting_heavy_weeks
FROM temp t
JOIN employees e ON e.employee_id=t.employee_id
WHERE t.total>20
GROUP BY t.employee_id
HAVING COUNT(e.employee_id)>1
ORDER BY 4 DESC,2
