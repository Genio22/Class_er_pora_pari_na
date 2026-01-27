create table student1(
ID number PRIMARY KEY,
Name varchar2(50) not NULL,
gender char(1) not NULL,
cerdits number not NULL,
cgpa number not NULL,
dob varchar2(20) not NULL,
phone varchar2(11) not NULL
);

ALTER TABLE student1
MODIFY ID varchar2(13);

ALTER TABLE student1
drop gender;

ALTER table student1
add gender char(1);


INSERT INTO student1 VALUES ('2022-3-60-444', 'Elena Rodriguez', 'F', 120, 4.00, '30-01-2000', '01399887766');
INSERT INTO student1 VALUES ('2022-3-60-445', 'Liam Wilson', 'M', 75, 3.20, '10-06-2001', '01522334455');
INSERT INTO student1 VALUES ('2022-3-60-446', 'Omar Faruk', 'M', 105, 3.40, '18-03-2000', '01788554433');
INSERT INTO student1 VALUES ('2022-3-60-447', 'Chloe Chen', 'F', 60, 3.65, '05-09-2002', '01677889900'); 
INSERT INTO student1 VALUES ('2022-3-60-448', 'Robert Smith', 'M', 90, 3.85, '12-05-2001', '01711223344');
INSERT INTO student1 VALUES ('2022-3-60-449', 'Sophia Taylor', 'F', 30, 2.95, '25-12-2003', '01811447700'); 
INSERT INTO student1 VALUES ('2022-3-60-450', 'Sara Khan', 'F', 110, 3.92, '22-11-1999', '01855667788');
INSERT INTO student1 VALUES ('2022-3-60-451', 'David Miller', 'M', 45, 2.75, '15-08-2002', '01900112233');


SELECT * FROM STUDENT1 WHERE cgpa>=3.5;

SELECT * FROM STUDENT1 ORDER BY ID;

SELECT * FROM student1;


UPDATE STUDENT1 set cgpa = 3.49 WHERE cerdits >70;