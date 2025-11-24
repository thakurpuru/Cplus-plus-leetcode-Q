# Write your MySQL query statement below

SELECT ROUND(
    COUNT(CASE WHEN ranked.rn=1 AND ranked.order_date=ranked.customer_pref_delivery_date 
    THEN 1 END)/
    COUNT(CASE WHEN ranked.rn=1 THEN 1 END) *100
    
    ,2) AS immediate_percentage
FROM (
    SELECT *,ROW_NUMBER() OVER(PARTITION BY customer_id ORDER BY 
    order_date,delivery_id) AS rn
    FROM Delivery
) ranked;
