# Write your MySQL query statement below
with myCTE as (select a1.player_id from Activity a1 join Activity a2 on a1.player_id=a2.player_id and DATEDIFF(a1.event_date, a2.event_date)=1 where (a2.player_id, a2.event_date) in (select player_id, min(event_date) from Activity group by player_id))
select ROUND(Count(*)/(select count(Distinct player_id) from Activity), 2) as fraction from myCTE