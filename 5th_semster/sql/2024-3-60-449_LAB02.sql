-- Task 1

create table account (
   account_no char(5) primary key,
   balance    number not null check ( balance >= 0 )
);


create table customer (
   customer_no   char(5) primary key,
   customer_name varchar2(20) not null,
   customer_city varchar2(10)
);

create table depositor (
   account_no  char(5),
   customer_no char(5),
   primary key ( account_no,
                 customer_no )
);

-- Task 2

alter table customer add date_of_birth varchar2(20);

alter table customer drop column date_of_birth;

alter table depositor rename column account_no to a_no;

alter table depositor rename column customer_no to c_no;

alter table depositor
   add constraint depositor_fk1 foreign key ( a_no )
      references account ( account_no );

alter table depositor
   add constraint depositor_fk2 foreign key ( c_no )
      references customer ( customer_no );

-- Task 3

insert into account values ( 'A-101',
                             12000 );
insert into account values ( 'A-102',
                             6000 );
insert into account values ( 'A-103',
                             2500 );

insert into customer values ( 'C-101',
                              'Alice',
                              'Dhaka' );
insert into customer values ( 'C-102',
                              'Annie',
                              'Dhaka' );
insert into customer values ( 'C-103',
                              'Bob',
                              'Chittagong' );
insert into customer values ( 'C-104',
                              'Charlie',
                              'Khulna' );



insert into depositor values ( 'A-101',
                               'C-101' );
insert into depositor values ( 'A-103',
                               'C-102' );
insert into depositor values ( 'A-103',
                               'C-104' );
insert into depositor values ( 'A-102',
                               'C-103' );

-- Task 4

select customer_name,
       customer_city
  from customer;

select distinct customer_city
  from customer; --unique display

select account_no
  from account
 where balance > 7000;

select customer_name,
       customer_no
  from customer
 where customer_city = 'Khulna';

select customer_name,
       customer_no
  from customer
 where customer_city not in ( 'Dhaka' );

-- 6.
select customer_name,
       customer_city
  from customer
  join (
        depositor
     join (
      select account_no
        from account
       where balance >= 7000
   ) account
   on depositor.a_no = account.account_no
)
on depositor.c_no = customer.customer_no;


-- 7.
select customer_name,
       customer_city
  from customer
  join (
        depositor
     join (
      select account_no
        from account
       where balance >= 7000
   ) account
   on depositor.a_no = account.account_no
)
on depositor.c_no = customer.customer_no
   and customer_city <> 'Khulna';

--8. Find account number and balance 
-- for those accounts which belong to 
-- a customer with id ‘C-102’

select account_no,
       balance
  from account
  join (
   select a_no
     from depositor
    where c_no = 'C-102'
) depositor
on depositor.a_no = account.account_no;


-- 9 Find all account number and balance 
--for those accounts which belong to customers 
--of Dhaka and Khulna city.

select distinct account.account_no,
                account.balance
  from account
  join depositor
on account.account_no = depositor.a_no
  join customer
on depositor.c_no = customer.customer_no
 where customer.customer_city in ( 'Dhaka',
                                   'Khulna' );


--10 Find the customer who have no accounts. 
-- [Result of this query will be empty for this dataset. However, you must write the correct SQL]

select *
  from customer c
 where not exists (
   select *
     from depositor d
    where d.c_no = c.customer_no
);