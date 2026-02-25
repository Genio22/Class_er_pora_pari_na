-- Task 1

CREATE TABLE account(
    account_no CHAR(5) PRIMARY KEY,
    balance NUMBER NOT NULL CHECK (balance>=0)
);


CREATE TABLE customer(
    customer_no CHAR(5) PRIMARY KEY,
    customer_name VARCHAR2(20) NOT NULL,
    customer_city VARCHAR2(10)
);

CREATE TABLE depositor(
    account_no CHAR(5),
    customer_no CHAR(5),
    PRIMARY KEY (account_no, customer_no)
);

-- Task 2

ALTER TABLE customer ADD date_of_birth VARCHAR2(20);

ALTER TABLE customer DROP column date_of_birth;

ALTER TABLE depositor rename column account_no to a_no;

ALTER TABLE depositor rename column customer_no to c_no;

ALTER TABLE depositor ADD CONSTRAINT depositor_fk1 FOREIGN KEY (a_no) REFERENCES account(account_no);

ALTER TABLE depositor ADD CONSTRAINT depositor_fk2 FOREIGN KEY (c_no) REFERENCES customer(customer_no);

-- Task 3

INSERT INTO account VALUES ('A-101', 12000);
INSERT INTO account VALUES ('A-102', 6000);
INSERT INTO account VALUES ('A-103', 2500);

INSERT INTO customer VALUES ('C-101', 'Alice',   'Dhaka');
INSERT INTO customer VALUES ('C-102', 'Annie',   'Dhaka');
INSERT INTO customer VALUES ('C-103', 'Bob',     'Chittagong');
INSERT INTO customer VALUES ('C-104', 'Charlie', 'Khulna');



INSERT INTO depositor VALUES ('A-101', 'C-101');
INSERT INTO depositor VALUES ('A-103', 'C-102');
INSERT INTO depositor VALUES ('A-103', 'C-104');
INSERT INTO depositor VALUES ('A-102', 'C-103');

-- Task 4

SELECT customer_name, customer_city FROM customer;

SELECT DISTINCT customer_city  FROM customer; --unique display

SELECT account_no FROM account WHERE balance >7000;


