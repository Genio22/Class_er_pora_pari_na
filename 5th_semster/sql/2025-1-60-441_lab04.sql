-- 1
select course_id
from section
where semester = 'Fall'
  and year = 2009
  and course_id in (
        select distinct course_id
        from section
        where semester = 'Spring'
          and year = 2010
  );

-- 2
select course_id
from section s
where s.semester = 'Fall'
  and s.year = 2009
  and not exists (
        select 1
        from section t
        where t.course_id = s.course_id
          and t.semester = 'Spring'
          and t.year = 2010
  );

-- 3
select count(distinct takes.ID)
from takes
join teaches
  on takes.course_id = teaches.course_id
 and takes.sec_id = teaches.sec_id
 and takes.semester = teaches.semester
 and takes.year = teaches.year
where teaches.ID = '10101';

-- 4
select name
from instructor
where salary > (
    select min(salary)
    from instructor
    where dept_name = 'Biology'
);

-- 5
select name
from instructor
where salary > (
    select max(salary)
    from instructor
    where dept_name = 'Biology'
);

-- 6
select course_id
from section
where semester = 'Fall'
  and year = 2009
  and course_id in (
        select course_id
        from section
        where semester = 'Spring'
          and year = 2010
  );

-- 7
select course_id
from section s
where s.semester = 'Fall'
  and s.year = 2009
  and s.course_id not in (
        select course_id
        from section
        where semester = 'Spring'
          and year = 2010
  );

-- 8
select st.ID, st.name
from student st
where not exists (
    select c.course_id
    from course c
    where c.dept_name = 'Biology'
      and not exists (
            select *
            from takes tk
            where tk.ID = st.ID
              and tk.course_id = c.course_id
      )
);

-- 9
select dept_name, avg_sal
from (
      select dept_name, avg(salary) avg_sal
      from instructor
      group by dept_name
     ) x
where avg_sal > 42000;

-- 10
with max_val as (
     select max(budget) highest_budget
     from department
)
select dept_name
from department
where budget = (select highest_budget from max_val);

-- 11
with dept_sum as (
     select dept_name, sum(salary) total_sal
     from instructor
     group by dept_name
)
select dept_name
from dept_sum
where total_sal > (
      select avg(total_sal)
      from dept_sum
);

-- 12
select dept_name,
       (select count(ID)
        from instructor i
        where i.dept_name = d.dept_name) total_instructors
from department d;

-- 13
select d.dept_name,
       coalesce(count(i.ID),0) total_instructors
from department d
left join instructor i
  on i.dept_name = d.dept_name
group by d.dept_name;

-- 14
select d.dept_name,
       count(i.ID) total_instructors
from department d
right join instructor i
  on d.dept_name = i.dept_name
group by d.dept_name;

-- 15
select d.dept_name,
       count(i.ID) total_instructors
from department d
full join instructor i
  on d.dept_name = i.dept_name
group by d.dept_name;