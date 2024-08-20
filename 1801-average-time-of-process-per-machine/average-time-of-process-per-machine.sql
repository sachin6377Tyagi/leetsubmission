# Write your MySQL query statement below
SELECT A.machine_id,ROUND(AVG(A.timestamp-B.timestamp),3) as processing_time
FROM Activity A
JOIN Activity B
ON A.machine_id=B.machine_id AND
A.process_id=B.process_id AND
A.timestamp > B.timestamp
GROUP BY machine_id;