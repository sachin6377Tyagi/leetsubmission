# Write your MySQL query statement below
SELECT S.student_id, S.student_name, Sub.subject_name , COUNT(e.subject_name) as attended_exams
FROM Students S
CROSS JOIN Subjects Sub
LEFT JOIN Examinations e
ON S.student_id=e.student_id AND 
Sub.subject_name=e.subject_name 
GROUP BY S.student_id,S.student_name,Sub.subject_name
ORDER by S.student_id,Sub.subject_name;