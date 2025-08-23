# Write your MySQL query statement below
SELECT unique_id, name from Employees as Emp left join EmployeeUNI as EmpUNI on Emp.id = EmpUNI.id
