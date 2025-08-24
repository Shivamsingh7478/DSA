# Write your MySQL query statement below
SELECT customer_id, count(*) as count_no_trans 
FROM Visits as  v left join Transactions as t
 on v.visit_id = t.visit_id
where t.transaction_id is NULL
Group by v.customer_id