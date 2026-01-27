create user ahnaf identified by ahnaf;


grant resource, connect, create session, create table, create view, create any trigger,create any procedure,create sequence, create synonym, unlimited tablespace to ahnaf; 

connect ahnaf/ahnaf;

--1 a)

create table instructor_2024360449(
    id number,
    name varchar2(50),
    dept_name varchar2(50),
    salary number
);

--1 b)

create table course_2024360449(
    course_id varchar2(50),
    title varchar2(50),
    dept_name varchar2(50),
    credits number
);


--2 a)

INSERT INTO instructor_2024360449 VALUES (10101, 'Srinivasan', 'Comp. Sci.', 65000),
INSERT INTO instructor_2024360449 VALUES (12121, 'Wu', 'Finance', 90000),
INSERT INTO instructor_2024360449 VALUES (15151, 'Mozart', 'Music', 40000),
INSERT INTO instructor_2024360449 VALUES (22222, 'Einstein', 'Physics', 95000),
INSERT INTO instructor_2024360449 VALUES (32343, 'El Said', 'History', 60000),
INSERT INTO instructor_2024360449 VALUES (33456, 'Gold', 'Physics', 87000),
INSERT INTO instructor_2024360449 VALUES (45565, 'Katz', 'Comp. Sci.', 75000),
INSERT INTO instructor_2024360449 VALUES (58583, 'Califieri', 'History', 62000),
INSERT INTO instructor_2024360449 VALUES (76543, 'Singh', 'Finance', 80000),
INSERT INTO instructor_2024360449 VALUES (76766, 'Crick', 'Biology', 72000),
INSERT INTO instructor_2024360449 VALUES (83821, 'Brandt', 'Comp. Sci.', 92000),
INSERT INTO instructor_2024360449 VALUES (98345, 'Kim', 'Elec. Eng.', 80000);



INSERT INTO course_2024360449 VALUES











select * from instructor_2024360449;



@ C:\Users\Student.DBLAB12\Documents\Ahnaf_CODE\1.sql;