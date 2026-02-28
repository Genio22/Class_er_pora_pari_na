---------- LAB 02----------

-- Task 1

create table account (
    account_no char(5),
    balance number constraint acc_bal_chk check (balance >= 0) not null,
    constraint acc_pk primary key (account_no)
);

create table customer (
    customer_no char(5),
    customer_name varchar2(20) not null,
    customer_city varchar2(15),
    constraint cust_pk primary key (customer_no)
);

create table depositor (
    account_no char(5),
    customer_no char(5),
    constraint dep_pk primary key (account_no, customer_no)
);

------------------------------------------------
-- Task 2

alter table customer add (date_of_birth varchar2(25));

alter table customer drop (date_of_birth);

alter table depositor rename column account_no to acc_no;
alter table depositor rename column customer_no to cust_no;

alter table depositor
    add constraint dep_acc_fk
    foreign key (acc_no)
    references account(account_no);

alter table depositor
    add constraint dep_cust_fk
    foreign key (cust_no)
    references customer(customer_no);

------------------------------------------------
-- Task 3

insert into account (account_no, balance) values ('A-101', 12000);
insert into account (account_no, balance) values ('A-102', 6000);
insert into account (account_no, balance) values ('A-103', 2500);

insert into customer values ('C-101','Alice','Dhaka');
insert into customer values ('C-102','Annie','Dhaka');
insert into customer values ('C-103','Bob','Chittagong');
insert into customer values ('C-104','Charlie','Khulna');

insert into depositor values ('A-101','C-101');
insert into depositor values ('A-103','C-102');
insert into depositor values ('A-103','C-104');
insert into depositor values ('A-102','C-103');

------------------------------------------------
-- Task 4

select c.customer_name, c.customer_city
from customer c;

select distinct customer_city
from customer;

select account_no
from account
where balance > 7000;

select customer_name, customer_no
from customer
where customer_city = 'Khulna';

select customer_name, customer_no
from customer
where customer_city <> 'Dhaka';

------------------------------------------------
-- 6

select c.customer_name, c.customer_city
from customer c
join depositor d on c.customer_no = d.cust_no
join account a on d.acc_no = a.account_no
where a.balance >= 7000;

------------------------------------------------
-- 7

select c.customer_name, c.customer_city
from customer c
join depositor d on c.customer_no = d.cust_no
join account a on d.acc_no = a.account_no
where a.balance >= 7000
  and c.customer_city != 'Khulna';

------------------------------------------------
-- 8
-- Accounts of customer id 'C-102'

select a.account_no, a.balance
from account a
where a.account_no in (
      select d.acc_no
      from depositor d
      where d.cust_no = 'C-102'
);

------------------------------------------------
-- 9
-- Accounts of customers from Dhaka and Khulna

select distinct a.account_no, a.balance
from account a
join depositor d on a.account_no = d.acc_no
join customer c on d.cust_no = c.customer_no
where c.customer_city in ('Dhaka','Khulna');

------------------------------------------------
-- 10
-- Customers who do not have any account

select c.customer_no, c.customer_name, c.customer_city
from customer c
where c.customer_no not in (
      select cust_no
      from depositor
);