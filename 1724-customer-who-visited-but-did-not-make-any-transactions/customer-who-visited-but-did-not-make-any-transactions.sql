# Write your MySQL query statement below
SELECT Vis.customer_id as customer_id, COUNT(Vis.customer_id) as count_no_trans
FROM Visits as Vis
left join Transactions as Tr
ON Vis.visit_id=Tr.visit_id 
WHERE Tr.transaction_id is NULL
gROUP BY customer_id;