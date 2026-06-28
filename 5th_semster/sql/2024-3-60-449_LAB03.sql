
--1.
select distinct branch_name,
                branch_city
  from branch
where assets > 1000000;

--2.Find all account numbers and their balance which are opened in ‘Downtown’ branch or
-- which have balance in between 600 and 750. (on single table)

select account_number,
       balance
  from account
 where branch_name = 'Downtown'
   or balance between 600 and 750;

--3.Find all account numbers which are opened in a branch located in ‘Rye’ city. (multiple
-- tables)

select account_number
  from account
natural join branch
 where branch_city = 'Rye';

--4. Find all loan numbers which have amount greater than or equal to 1000 
-- and their customers are living in ‘Harrison’ city. (multiple tables)

select loan_number
  from loan
natural join borrower
natural join customer
 where amount >= 1000
   and customer_city = 'Harrison'
 order by loan_number asc; --this is optional

--5. Display the account related information based on the descending 
-- order of the balance. (order by clause)

select *
  from account
 order by balance desc;

--6. Display the customer related information in alphabetic order of
-- customer cities. (order by clause)

select *
  from customer
 order by customer_city asc;

--7. Find all customer names who have an account as well as a loan. (intersect)
select customer_name
  from depositor
intersect
select customer_name
  from borrower;

--8. Find all customer related information who have an account or a loan. (union)

select customer_name,
       customer_street,
       customer_city
  from customer
natural join depositor
union
select customer_name,
       customer_street,
       customer_city
  from customer
natural join borrower;

--9. Find all customer names and their cities who have a loan but not an account. (minus)
-- select customer_name,
--        customer_city
--   from customer
--  where customer_name in (
--    select customer_name
--      from borrower
-- )
--    and customer_name not in (
--    select customer_name
--      from depositor
-- );
select customer_name,
       customer_city
from customer
natural join borrower
minus
select customer_name,
       customer_city
from customer
natural join depositor;


--10. Find the total assets of all branches. (aggregate function)
select sum(assets) as total
  from branch;

--11. Find the average balance of accounts at each branch. (aggregate function)
select branch_name,
       avg(balance)
  from account
 group by branch_name;

--12. Find the average balance of accounts at each branch city. (aggregate function)
select branch_city,
       avg(balance)
  from account
natural join branch
group by branch_city;

--13. Find the lowest amount of loan at each branch. (aggregate function)
select branch_name,
       min(amount)
  from loan
 group by branch_name;

--14. Find the total number of loans at each branch. (aggregate function)
select branch_name,
       count(loan_number)
  from loan
 group by branch_name;

--15. Find the customer name and account number of the account which has the highest balance.
-- (aggregate function)

select customer_name,
       account_number
  from account
natural join depositor
 where balance = (
   select max(balance)
     from account
);
