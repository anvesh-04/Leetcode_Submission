# Write your MySQL query statement below
with mycte as (select e1.employee_id, e1.name, e2.age from Employees e1 join Employees e2 on e1.employee_id=e2.reports_to)
select employee_id, name, count(employee_id) as reports_count, ROUND(avg(age), 0) as average_age from mycte group by employee_id order by employee_id

