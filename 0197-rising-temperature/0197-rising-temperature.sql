# Write your MySQL query statement below
select w.id from Weather w join Weather W2 on DATEDIFF(w.recordDate,W2.recordDate)=1 where W2.temperature<w.temperature;