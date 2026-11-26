with myCTE as ((select accepter_id as id from RequestAccepted) 
UNION ALL
(select requester_id as id from RequestAccepted))

select id, Count(id) num from myCTE group by id order by num DESC LIMIT 1;