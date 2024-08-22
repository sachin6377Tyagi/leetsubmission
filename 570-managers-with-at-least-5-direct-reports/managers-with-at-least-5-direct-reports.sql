# Write your MySQL query statement below
SELECT A.name as name
FROM Employee A
Join Employee B
ON A.id=B.managerId
GROUP BY B.managerId
HAVING COUNT(B.managerId)>=5;;