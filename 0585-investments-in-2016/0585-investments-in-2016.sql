# Write your MySQL query statement below
select ROUND(sum(tiv_2016), 2) as tiv_2016 from (select pid, tiv_2015, tiv_2016, lat, lon,
COUNT(*) over (partition by lat,lon) as latlon,
COUNT(*) over (partition by tiv_2015) as rep
from Insurance) as t1 where latlon=1 and rep>1