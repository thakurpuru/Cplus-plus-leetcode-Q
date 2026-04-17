# Write your MySQL query statement below
WITH temp AS (
    SELECT u1.user_id,u1.product_id AS p1,u2.product_id AS p2
    FROM ProductPurchases u1
    JOIN ProductPurchases u2 ON u1.user_id=u2.user_id
    WHERE u1.product_id<u2.product_id
),
temp1 AS (
    SELECT *,COUNT(DISTINCT user_id) AS cnt
    FROM temp
    GROUP BY p1,p2
    HAVING COUNT(DISTINCT user_id) >=3
)

SELECT t1.p1 AS product1_id,t1.p2 AS product2_id,a1.category AS  product1_category,a2.category AS  product2_category,t1.cnt AS customer_count
FROM temp1 t1
JOIN ProductInfo a1 ON t1.p1=a1.product_id 
JOIN ProductInfo a2 ON t1.p2=a2.product_id 
ORDER BY 5 DESC,1,2
