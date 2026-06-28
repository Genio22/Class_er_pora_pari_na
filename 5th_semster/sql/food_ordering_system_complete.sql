-- SQL implementation for Online Food Ordering System

-- DDL Statements

CREATE TABLE Users (
    user_id INT PRIMARY KEY AUTO_INCREMENT,
    username VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE Restaurants (
    restaurant_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
    location VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE MenuItems (
    item_id INT PRIMARY KEY AUTO_INCREMENT,
    restaurant_id INT,
    name VARCHAR(255) NOT NULL,
    price DECIMAL(10, 2) NOT NULL,
    description TEXT,
    FOREIGN KEY (restaurant_id) REFERENCES Restaurants(restaurant_id)
);

CREATE TABLE Orders (
    order_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    total_amount DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (user_id) REFERENCES Users(user_id)
);

CREATE TABLE OrderItems (
    order_item_id INT PRIMARY KEY AUTO_INCREMENT,
    order_id INT,
    menu_item_id INT,
    quantity INT NOT NULL,
    FOREIGN KEY (order_id) REFERENCES Orders(order_id),
    FOREIGN KEY (menu_item_id) REFERENCES MenuItems(item_id)
);

-- DML Statements

INSERT INTO Users (username, password, email) VALUES
('user1', 'pass1', 'user1@example.com'),
('user2', 'pass2', 'user2@example.com');

INSERT INTO Restaurants (name, location) VALUES
('Restaurant A', 'Location A'),
('Restaurant B', 'Location B');

INSERT INTO MenuItems (restaurant_id, name, price, description) VALUES
(1, 'Pasta', 8.99, 'Delicious Pasta'),
(1, 'Pizza', 12.99, 'Cheesy Pizza'),
(2, 'Burger', 10.99, 'Juicy Burger');

INSERT INTO Orders (user_id, total_amount) VALUES
(1, 21.98),
(2, 10.99);

INSERT INTO OrderItems (order_id, menu_item_id, quantity) VALUES
(1, 1, 1),
(1, 2, 1),
(2, 3, 1);

-- Queries

-- Retrieve all menu items
SELECT * FROM MenuItems;

-- Retrieve all orders for a user
SELECT * FROM Orders WHERE user_id = 1;

-- Views

CREATE VIEW ActiveOrders AS
SELECT * FROM Orders WHERE total_amount > 0;

-- Triggers

CREATE TRIGGER AfterOrderInsert
AFTER INSERT ON Orders
FOR EACH ROW
BEGIN
    UPDATE MenuItems SET price = price - 1 WHERE id IN (SELECT menu_item_id FROM OrderItems WHERE order_id = NEW.order_id);
END;

-- Stored Procedures

DELIMITER $$
CREATE PROCEDURE PlaceOrder(IN userId INT, IN totalAmount DECIMAL(10, 2))
BEGIN
    INSERT INTO Orders (user_id, total_amount) VALUES (userId, totalAmount);
END $$
DELIMITER ;

-- Additional procedures and operations can be added here.