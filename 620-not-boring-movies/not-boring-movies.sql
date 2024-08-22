# Write your MySQL query statement below
SELECT * FROM Cinema
WHERE id%2=1 AND
NOT Cinema.description='boring'
GROUP BY id
ORDER BY rating DESC 
;