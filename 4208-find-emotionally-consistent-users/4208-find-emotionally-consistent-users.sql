# Write your MySQL query statement below
WITH temp AS (
    SELECT *,COUNT(*) AS total
    FROM reactions
    GROUP BY user_id
    HAVING COUNT(*)>=5
)

SELECT user_id, reaction AS dominant_reaction,reaction_ratio
FROM (
    SELECT r.user_id,r.reaction,ROUND(COUNT(*)/t.total,2) As reaction_ratio
    FROM reactions r
    JOIN temp t ON t.user_id=r.user_id
    GROUP BY r.user_id, r.reaction

) t
WHERE reaction_ratio>=0.6
ORDER BY reaction_ratio DESC, user_id ASC
