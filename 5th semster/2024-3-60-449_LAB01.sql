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



INSERT INTO course_2024360449 (course_id, title, dept_name, credits)
VALUES
('BIO-101', 'Intro. to Biology', 'Biology', 4),
('BIO-301', 'Genetics', 'Biology', 4),
('BIO-399', 'Computational Biology', 'Biology', 3),
('CS-101', 'Intro. to Computer Science', 'Comp. Sci.', 4),
('CS-190', 'Game Design', 'Comp. Sci.', 4),
('CS-315', 'Robotics', 'Comp. Sci.', 3),
('CS-319', 'Image Processing', 'Comp. Sci.', 3),
('CS-347', 'Database System Concepts', 'Comp. Sci.', 3),
('EE-181', 'Intro. to Digital Systems', 'Elec. Eng.', 3),
('FIN-201', 'Investment Banking', 'Finance', 3),
('HIS-351', 'World History', 'History', 3),
('MU-199', 'Music Video Production', 'Music', 3),
('PHY-101', 'Physical Principles', 'Physics', 4);



select * from instructor_2024360449;



@ C:\Users\Student.DBLAB12\Documents\Ahnaf_CODE\1.sql;