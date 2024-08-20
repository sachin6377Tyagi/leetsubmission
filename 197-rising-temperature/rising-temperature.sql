# Write your MySQL query statement below
SELECT A.id FROM Weather AS A
 JOIN Weather AS B
 ON A.recordDate=DATE_ADD(B.recordDate, INTERVAL 1 DAY)
 WHERE A.temperature>B.temperature;