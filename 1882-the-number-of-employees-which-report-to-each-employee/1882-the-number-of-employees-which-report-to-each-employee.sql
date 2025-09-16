# Write your MySQL query statement below
SELECT mgr.employee_id, mgr.name, count(emp.employee_id) as reports_count, round(avg(emp.age)) as average_age
FROM Employees as emp
Join Employees as mgr
 on emp.reports_to = mgr.employee_id
Group by employee_id
Order by employee_id 
 