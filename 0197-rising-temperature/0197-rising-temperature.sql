with my_cte as (
    select id, recordDate, temperature, LAG(recordDate, 1) OVER (order by recordDate) as previousDate , LAG(temperature, 1) OVER (order by recordDate) as previousTemperature from Weather 
)
select id from my_cte where DATEDIFF(recordDate, previousDate)=1 AND temperature>previousTemperature;