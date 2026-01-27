create user ahnaf identified by ahnaf;


grant resource, connect, create session, create table, create view, create any trigger,create any procedure,create sequence, create synonym, unlimited tablespace to ahnaf; 

connect ahnaf/ahnaf;

create table instructor_2024360449(
    id number,
    name varchar2(50),
    dept_name varchar2(50),
    salary number
);

create table course_2024360449(
    course_id varchar2(50),
    title varchar2(50),
    dept_name varchar2(50),
    credits number
);




-- insert into person1 values (2018002, 'Bob', '01-Jan-92');
-- insert into person1 values (2018003, 'Steve', '01-Jan-93');
-- insert into person1 values (2018004, 'Elsa', '01-Jan-94');
-- insert into person1 values (2018005, 'Ahana', '01-Jan-95');
-- insert into person1 values (2018006, 'Jakson', '01-Jan-96');
-- insert into person1 values (2018007, 'Harve', '01-Jan-97');
-- insert into person1 values (2018008, 'Robart', '01-Jan-98');


select * from person1;



@ C:\Users\Student.DBLAB12\Documents\Ahnaf_CODE\1.sql;