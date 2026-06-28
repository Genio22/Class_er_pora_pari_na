-----------Lab 4--------


--1.
select distinct course_id
from section
where semester = 'Fall' and year = 2009
and course_id in (
    select course_id
    from section
    where semester = 'Spring' and year = 2010
);

--2.
select distinct course_id
from section
where semester = 'Fall' and year = 2009
and course_id not in (
    select course_id
    from section
    where semester = 'Spring' and year = 2010
);

--3.
select count(distinct t.ID)
from takes t
where (t.course_id, t.sec_id, t.semester, t.year) in (
    select course_id, sec_id, semester, year
    from teaches
    where ID = '10101'
);


--4.
select name
from instructor
where salary > some (
    select salary
    from instructor
    where dept_name = 'Biology'
);

--5.
select name
from instructor
where salary > all (
    select salary
    from instructor
    where dept_name = 'Biology'
);


--6,
select distinct s1.course_id
from section s1
where s1.semester = 'Fall'
and s1.year = 2009
and exists (
    select *
    from section s2
    where s2.course_id = s1.course_id
    and s2.semester = 'Spring'
    and s2.year = 2010
);

--7.
select distinct s1.course_id
from section s1
where s1.semester = 'Fall'
and s1.year = 2009
and not exists (
    select *
    from section s2
    where s2.course_id = s1.course_id
    and s2.semester = 'Spring'
    and s2.year = 2010
);

--8.
select s.ID, s.name
from student s
where not exists (
    (select course_id
     from course
     where dept_name = 'Biology')
    minus
    (select t.course_id
     from takes t
     where t.ID = s.ID)
);


--9.
select dept_name, avg_salary
from (
    select dept_name, avg(salary) as avg_salary
    from instructor
    group by dept_name
) dept_avg
where avg_salary > 42000;

--10.
with max_budget as (
    select max(budget) as max_b
    from department
)
select dept_name
from department, max_budget
where budget = max_b;

--11.
with dept_total as (
    select dept_name, sum(salary) as total_salary
    from instructor
    group by dept_name
),
avg_total as (
    select avg(total_salary) as avg_sal
    from dept_total
)
select dept_name
from dept_total, avg_total
where total_salary > avg_sal;


--12.
select d.dept_name,
       (select count(*)
        from instructor i
        where i.dept_name = d.dept_name) as num_instructors
from department d;

--13.
select d.dept_name, count(i.ID) as num_instructors
from department d
left outer join instructor i
on d.dept_name = i.dept_name
group by d.dept_name;

--14.
select d.dept_name, count(i.ID) as num_instructors
from instructor i
right outer join department d
on d.dept_name = i.dept_name
group by d.dept_name;


--15.
select d.dept_name, count(i.ID) as num_instructors
from department d
full outer join instructor i
on d.dept_name = i.dept_name
group by d.dept_name;


