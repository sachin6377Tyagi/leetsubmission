# Write your MySQL query statement below
SELECT Emp.name, B.bonus
FROM Employee Emp
LEFT JOIN Bonus B
ON Emp.empId=B.empId 
WHERE B.bonus<1000
OR B.bonus IS NULL;