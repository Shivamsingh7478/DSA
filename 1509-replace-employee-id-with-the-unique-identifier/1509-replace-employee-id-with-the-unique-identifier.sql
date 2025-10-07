# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT EmpUNI.unique_id, Emp.name from Employees as Emp left join EmployeeUNI as EmpUNI on Emp.id = EmpUNI.id