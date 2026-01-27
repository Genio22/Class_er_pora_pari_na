create user ahnaf identified by ahnaf;

grant resource, connect, create session, create table, create view, create any trigger,create any procedure,create sequence, create synonym, unlimited tablespace to ahnaf; 

connect ahnaf/ahnaf;

SET LINESIZE 200
SET PAGESIZE 100


--------------------------------------------Lab_01 Task-------------------------------------------


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

--------------------------------------------Lab_02 Task-------------------------------------------

--2 a)

INSERT INTO instructor_2024360449 VALUES (10101, 'Srinivasan', 'Comp. Sci.', 65000);
INSERT INTO instructor_2024360449 VALUES (12121, 'Wu', 'Finance', 90000);
INSERT INTO instructor_2024360449 VALUES (15151, 'Mozart', 'Music', 40000);
INSERT INTO instructor_2024360449 VALUES (22222, 'Einstein', 'Physics', 95000);
INSERT INTO instructor_2024360449 VALUES (32343, 'El Said', 'History', 60000);
INSERT INTO instructor_2024360449 VALUES (33456, 'Gold', 'Physics', 87000);
INSERT INTO instructor_2024360449 VALUES (45565, 'Katz', 'Comp. Sci.', 75000);
INSERT INTO instructor_2024360449 VALUES (58583, 'Califieri', 'History', 62000);
INSERT INTO instructor_2024360449 VALUES (76543, 'Singh', 'Finance', 80000);
INSERT INTO instructor_2024360449 VALUES (76766, 'Crick', 'Biology', 72000);
INSERT INTO instructor_2024360449 VALUES (83821, 'Brandt', 'Comp. Sci.', 92000);
INSERT INTO instructor_2024360449 VALUES (98345, 'Kim', 'Elec. Eng.', 80000);

--2 b)

INSERT INTO course_2024360449 VALUES ('BIO-101', 'Intro. to Biology', 'Biology', 4);
INSERT INTO course_2024360449 VALUES ('BIO-301', 'Genetics', 'Biology', 4);
INSERT INTO course_2024360449 VALUES ('BIO-399', 'Computational Biology', 'Biology', 3);
INSERT INTO course_2024360449 VALUES ('CS-101', 'Intro. to Computer Science', 'Comp. Sci.', 4);
INSERT INTO course_2024360449 VALUES ('CS-190', 'Game Design', 'Comp. Sci.', 4);
INSERT INTO course_2024360449 VALUES ('CS-315', 'Robotics', 'Comp. Sci.', 3);
INSERT INTO course_2024360449 VALUES ('CS-319', 'Image Processing', 'Comp. Sci.', 3);
INSERT INTO course_2024360449 VALUES ('CS-347', 'Database System Concepts', 'Comp. Sci.', 3);
INSERT INTO course_2024360449 VALUES ('EE-181', 'Intro. to Digital Systems', 'Elec. Eng.', 3);
INSERT INTO course_2024360449 VALUES ('FIN-201', 'Investment Banking', 'Finance', 3);
INSERT INTO course_2024360449 VALUES ('HIS-351', 'World History', 'History', 3);
INSERT INTO course_2024360449 VALUES ('MU-199', 'Music Video Production', 'Music', 3);
INSERT INTO course_2024360449 VALUES ('PHY-101', 'Physical Principles', 'Physics', 4);

--------------------------------------------Lab_03 Task-------------------------------------------


--3 i)

select name from instructor_2024360449;

--3 ii)

select course_id, title from course_2024360449;

--3 iii)

select name, dept_name from instructor_2024360449 where id = 22222;

--3 iv)

select title, credits from course_2024360449 where dept_name = 'Comp. Sci.';

--3 v)
 
select name, dept_name from instructor_2024360449 where salary > 70000;

--3 vi)

select title from course_2024360449 where credits > 3; -- not less than 4 == 'credits > 3' or 'credits >= 4'

--3 vii)

select name, dept_name from instructor_2024360449 where salary between 80000 and 100000;

--3 viii)

select title, credits from course_2024360449 where dept_name <> 'Comp. Sci' or dept_name is null; 
-- '<>', '!=' -> not equal to, '<>' do not reture the row with null so use or to add that case here.

--3 ix)

select * from instructor_2024360449;

--3 x)

select * from course_2024360449 where dept_name = 'Biology' and credits != 4;






@ C:\Users\Student\Documents\Ahnaf_Code\2024-3-60-449_LAB01.sql;










