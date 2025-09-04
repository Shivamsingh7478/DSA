# Write your MySQL query statement below
SELECT project_id, round(sum(e.experience_years) / count(e.employee_id) ,2) as average_years
from Project as p
join Employee as e
 on e.employee_id = p.employee_id
group by p.project_id
