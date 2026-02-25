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