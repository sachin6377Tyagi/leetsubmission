# Write your MySQL query statement below
SELECT pr.product_name as product_name,
s.year as year, s.price as price
FROM Sales s
LEFT JOIN Product pr
ON s.product_id=pr.product_id;