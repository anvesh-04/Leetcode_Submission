# Write your MySQL query statement below
(select name as results from (select u.user_id, u.name, count(u.user_id) as mr from Users u join MovieRating m on u.user_id=m.user_id group by u.user_id order by mr DESC, name ASC) t1 LIMIT 1)

UNION ALL

(select title as results from (select u1.title, avg(u2.rating) as avgg from Movies u1 join (select movie_id, rating from MovieRating where created_at LIKE '2020-02%') u2 on u1.movie_id=u2.movie_id group by u1.movie_id order by avgg DESC, u1.title ASC) t4 LIMIT 1)