# Write your MySQL query statement below

SELECT t.request_at AS `Day`,ROUND(COUNT(CASE WHEN t.status LIKE 'cancelled%' THEN 1 END)/COUNT(t.client_id),2) AS  `Cancellation Rate`
FROM Trips t
JOIN Users u1 ON u1.users_id=t.client_id
JOIN Users u2 ON u2.users_id=t.driver_id
WHERE t.request_at BETWEEN DATE('2013-10-01') AND DATE('2013-10-03') AND u1.banned='No' AND u2.banned='No'
GROUP BY t.request_at

