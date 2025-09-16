# Write your MySQL query statement below
SELECT customer_id
FROM Customer as c
group by c.customer_id
having count(distinct c.product_key) = (
    select count(*) from Product
)