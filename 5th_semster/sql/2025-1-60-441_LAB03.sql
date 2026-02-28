-------------- Modified Version ----------------

-- 1
select b.branch_name, b.branch_city
from branch b
where b.assets > 1000000;

------------------------------------------------

-- 2
select a.account_number, a.balance
from account a
where a.branch_name = 'Downtown'
   or (a.balance >= 600 and a.balance <= 750);

------------------------------------------------

-- 3
select a.account_number
from account a
join branch b
  on a.branch_name = b.branch_name
where b.branch_city = 'Rye';

------------------------------------------------

-- 4
select l.loan_number
from loan l
join borrower br
  on l.loan_number = br.loan_number
join customer c
  on br.customer_name = c.customer_name
where l.amount >= 1000
  and c.customer_city = 'Harrison'
order by l.loan_number;

------------------------------------------------

-- 5
select account_number, branch_name, balance
from account
order by balance desc;

------------------------------------------------

-- 6
select customer_name, customer_street, customer_city
from customer
order by customer_city;

------------------------------------------------

-- 7
select c.customer_name
from customer c
where c.customer_name in (select customer_name from depositor)
  and c.customer_name in (select customer_name from borrower);

------------------------------------------------

-- 8
select customer_name, customer_street, customer_city
from customer
where customer_name in (select customer_name from depositor)
   or customer_name in (select customer_name from borrower);

------------------------------------------------

-- 9
select c.customer_name, c.customer_city
from customer c
where c.customer_name in (select customer_name from borrower)
  and c.customer_name not in (select customer_name from depositor);

------------------------------------------------

-- 10
select sum(b.assets) total_assets
from branch b;

------------------------------------------------

-- 11
select branch_name, avg(balance) as avg_balance
from account
group by branch_name;

------------------------------------------------

-- 12
select b.branch_city, avg(a.balance) as avg_balance
from account a
join branch b
  on a.branch_name = b.branch_name
group by b.branch_city;

------------------------------------------------

-- 13
select branch_name, min(amount) as lowest_loan
from loan
group by branch_name;

------------------------------------------------

-- 14
select branch_name, count(*) as total_loans
from loan
group by branch_name;

------------------------------------------------

-- 15
select d.customer_name, a.account_number
from account a
join depositor d
  on a.account_number = d.account_number
where a.balance = (
      select max(balance)
      from account
);