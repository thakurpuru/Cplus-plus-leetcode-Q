# Write your MySQL query statement below
WITH temp AS (
    SELECT *,MIN(transaction_date) AS st,MAX(transaction_date) AS en
    FROM customer_transactions
    GROUP BY customer_id
    HAVING COUNT(CASE WHEN transaction_type='purchase' THEN 1 END)>=3 AND SUM(CASE WHEN transaction_type='refund' THEN 1 ELSE 0 END)/COUNT(*)<0.2 
)

SELECT customer_id
FROM temp
WHERE DATEDIFF(en,st)>=30
ORDER BY 1