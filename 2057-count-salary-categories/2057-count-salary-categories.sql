# Write your MySQL query statement below
SELECT 'Low Salary' as category, count(CASE WHEN income <20000 THEN 1 END) as accounts_count
FROM accounts
UNION ALL
SELECT 'Average Salary' as category, count(CASE WHEN income BETWEEN 20000 AND 50000 THEN 1 END) as accounts_count
FROM accounts
UNION ALL
SELECT 'High Salary' as category, count(CASE WHEN income >50000 THEN 1 END) as account_count
FROM accounts
order by accounts_count desc