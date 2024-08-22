# Write your MySQL query statement below
SELECT R.contest_id, ROUND(COUNT(DISTINCT R.user_id)/COUNT(DISTINCT U.user_id)*100,2) as percentage
FROM Register R,Users U
GROUP BY R.contest_id
ORDER BY percentage DESC, contest_id ASC;