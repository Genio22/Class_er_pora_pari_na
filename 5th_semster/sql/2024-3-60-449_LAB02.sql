----------  Lab 02 -------------

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




----------  Lab 03 -------------

drop table depositor cascade constraints;
drop table borrower cascade constraints;
drop table account cascade constraints;
drop table loan cascade constraints;
drop table customer cascade constraints;
drop table branch cascade constraints;

create table account (
   account_number varchar(15) not null,
   branch_name    varchar(15) not null,
   balance        number not null,
   constraint account_pk primary key ( account_number )
);

create table branch (
   branch_name varchar(15) not null,
   branch_city varchar(15) not null,
   assets      number not null,
   primary key ( branch_name )
);

create table customer (
   customer_name   varchar(15) not null,
   customer_street varchar(12) not null,
   customer_city   varchar(15) not null,
   primary key ( customer_name )
);

create table loan (
   loan_number varchar(15) not null,
   branch_name varchar(15) not null,
   amount      number not null,
   primary key ( loan_number )
);

create table depositor (
   customer_name  varchar(15) not null,
   account_number varchar(15) not null,
   primary key ( customer_name,
                 account_number ),
   foreign key ( account_number )
      references account ( account_number ),
   foreign key ( customer_name )
      references customer ( customer_name )
);

create table borrower (
   customer_name varchar(15) not null,
   loan_number   varchar(15) not null,
   primary key ( customer_name,
                 loan_number ),
   foreign key ( customer_name )
      references customer ( customer_name ),
   foreign key ( loan_number )
      references loan ( loan_number )
);

/* populate relations */

insert into customer values ( 'Jones',
                              'Main',
                              'Harrison' );
insert into customer values ( 'Smith',
                              'Main',
                              'Rye' );
insert into customer values ( 'Hayes',
                              'Main',
                              'Harrison' );
insert into customer values ( 'Curry',
                              'North',
                              'Rye' );
insert into customer values ( 'Lindsay',
                              'Park',
                              'Pittsfield' );
insert into customer values ( 'Turner',
                              'Putnam',
                              'Stamford' );
insert into customer values ( 'Williams',
                              'Nassau',
                              'Princeton' );
insert into customer values ( 'Adams',
                              'Spring',
                              'Pittsfield' );
insert into customer values ( 'Johnson',
                              'Alma',
                              'Palo Alto' );
insert into customer values ( 'Glenn',
                              'Sand Hill',
                              'Woodside' );
insert into customer values ( 'Brooks',
                              'Senator',
                              'Brooklyn' );
insert into customer values ( 'Green',
                              'Walnut',
                              'Stamford' );
insert into customer values ( 'Jackson',
                              'University',
                              'Salt Lake' );
insert into customer values ( 'Majeris',
                              'First',
                              'Rye' );
insert into customer values ( 'McBride',
                              'Safety',
                              'Rye' );

insert into branch values ( 'Downtown',
                            'Brooklyn',
                            900000 );
insert into branch values ( 'Redwood',
                            'Palo Alto',
                            2100000 );
insert into branch values ( 'Perryridge',
                            'Horseneck',
                            1700000 );
insert into branch values ( 'Mianus',
                            'Horseneck',
                            400200 );
insert into branch values ( 'Round Hill',
                            'Horseneck',
                            8000000 );
insert into branch values ( 'Pownal',
                            'Bennington',
                            400000 );
insert into branch values ( 'North Town',
                            'Rye',
                            3700000 );
insert into branch values ( 'Brighton',
                            'Brooklyn',
                            7000000 );
insert into branch values ( 'Central',
                            'Rye',
                            400280 );

insert into account values ( 'A-101',
                             'Downtown',
                             500 );
insert into account values ( 'A-215',
                             'Mianus',
                             700 );
insert into account values ( 'A-102',
                             'Perryridge',
                             400 );
insert into account values ( 'A-305',
                             'Round Hill',
                             350 );
insert into account values ( 'A-201',
                             'Perryridge',
                             900 );
insert into account values ( 'A-222',
                             'Redwood',
                             700 );
insert into account values ( 'A-217',
                             'Brighton',
                             750 );
insert into account values ( 'A-333',
                             'Central',
                             850 );
insert into account values ( 'A-444',
                             'North Town',
                             625 );

insert into depositor values ( 'Johnson',
                               'A-101' );
insert into depositor values ( 'Smith',
                               'A-215' );
insert into depositor values ( 'Hayes',
                               'A-102' );
insert into depositor values ( 'Hayes',
                               'A-101' );
insert into depositor values ( 'Turner',
                               'A-305' );
insert into depositor values ( 'Johnson',
                               'A-201' );
insert into depositor values ( 'Jones',
                               'A-217' );
insert into depositor values ( 'Lindsay',
                               'A-222' );
insert into depositor values ( 'Majeris',
                               'A-333' );
insert into depositor values ( 'Smith',
                               'A-444' );

insert into loan values ( 'L-17',
                          'Downtown',
                          1000 );
insert into loan values ( 'L-23',
                          'Redwood',
                          2000 );
insert into loan values ( 'L-15',
                          'Perryridge',
                          1500 );
insert into loan values ( 'L-14',
                          'Downtown',
                          1500 );
insert into loan values ( 'L-93',
                          'Mianus',
                          500 );
insert into loan values ( 'L-11',
                          'Round Hill',
                          900 );
insert into loan values ( 'L-16',
                          'Perryridge',
                          1300 );
insert into loan values ( 'L-20',
                          'North Town',
                          7500 );
insert into loan values ( 'L-21',
                          'Central',
                          570 );

insert into borrower values ( 'Jones',
                              'L-17' );
insert into borrower values ( 'Smith',
                              'L-23' );
insert into borrower values ( 'Hayes',
                              'L-15' );
insert into borrower values ( 'Jackson',
                              'L-14' );
insert into borrower values ( 'Curry',
                              'L-93' );
insert into borrower values ( 'Smith',
                              'L-11' );
insert into borrower values ( 'Williams',
                              'L-17' );
insert into borrower values ( 'Adams',
                              'L-16' );
insert into borrower values ( 'McBride',
                              'L-20' );
insert into borrower values ( 'Smith',
                              'L-21' );

commit;


-- 1) Find all branch names and cities with assets more than 1000000. (on single table)
-- 2) Find all account numbers and their balance which are opened in ‘Downtown’ branch or
-- which have balance in between 600 and 750. (on single table)
-- 3) Find all account numbers which are opened in a branch located in ‘Rye’ city. (multiple
-- tables)
-- 4) Find all loan numbers which have amount greater than or equal to 1000 and their customers
-- are living in ‘Harrison’ city. (multiple tables)
-- 5) Display the account related information based on the descending order of the balance. (order
-- by clause)
-- 6) Display the customer related information in alphabetic order of customer cities. (order by
-- clause)
-- 7) Find all customer names who have an account as well as a loan. (intersect)
-- 8) Find all customer related information who have an account or a loan. (union)
-- 9) Find all customer names and their cities who have a loan but not an account. (minus)
-- 10) Find the total assets of all branches. (aggregate function)
-- 11) Find the average balance of accounts at each branch. (aggregate function)
-- 12) Find the average balance of accounts at each branch city. (aggregate function)
-- 13) Find the lowest amount of loan at each branch. (aggregate function)
-- 14) Find the total number of loans at each branch. (aggregate function)
-- 15) Find the customer name and account number of the account which has the highest balance.
-- (aggregate function)



--------------Lab 04-------------




--sql 'RELAQUANTISTEN_SCHEMA_F3KXG/QZN15VQUC!4SD27UC3D1RzQAS6Y8FI@//db.freesql.com:1521/23ai_34ui2'