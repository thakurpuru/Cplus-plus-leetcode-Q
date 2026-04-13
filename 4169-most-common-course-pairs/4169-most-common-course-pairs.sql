# Write your MySQL query statement below
WITH temp AS (
    SELECT user_id,COUNT(*) AS cnt ,AVG(course_rating)
    FROM course_completions 
    GROUP BY user_id
    HAVING COUNT(*)>=5 AND AVG(course_rating)>=4 
),
temp1 AS (    
    SELECT c.user_id,c.course_name AS first_course,LEAD(c.course_name) OVER(PARTITION BY user_id ORDER  BY completion_date) AS second_course
    FROM course_completions c
    JOIN temp t ON t.user_id=c.user_id
)
SELECT DISTINCT first_course,second_course,count(*) over(partition by first_course  ,second_course) transition_count 
FROM temp1
WHERE second_course IS NOT NULL
ORDER BY 3 DESC,1,2
