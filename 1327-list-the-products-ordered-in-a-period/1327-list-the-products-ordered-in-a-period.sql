# Write your MySQL query statement below
with mycte as (select product_id, order_date, sum(unit) as unitSold from Orders where order_date like '2020-02%' group by product_id )
select p.product_name, o.unitSold as unit from Products p join mycte o on p.product_id=o.product_id where o.unitSold>=100