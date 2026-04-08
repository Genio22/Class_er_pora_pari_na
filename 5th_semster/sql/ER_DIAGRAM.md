# ER Diagram Documentation for Online Food Ordering System

## Entity-Relationship Diagram

```plaintext
+---------------------+     +-----------------+     +------------------+
|      Customer       |     |    Restaurant    |     |      Order       |
|---------------------|     |-----------------|     |------------------|
| - customer_id (PK)  |     | - restaurant_id (PK) | - order_id (PK)
| - name              |     | - name            | - order_date
| - email             |     | - location        | - total_amount
| - phone             |     | - rating          | - status
|---------------------|     |-----------------|     |------------------|
         |                      |                |              |                  |
         |                      |                |              |                  |
         |                      |                |              |                  |
         +---------------------+                +--------------+         +------------------+
         |  +------------------+

                +-----------------+
             |   Order_Items    |
             |-------------------|
             | - order_item_id (PK) |
             | - order_id (FK) |
             | - food_id (FK)   |
             | - quantity        | 
             | - price           | 
             |-------------------|
          
                 +----------------+     +-------------------+
             |       Food       |     |    Payment        |
             |-------------------|     |-------------------|
             | - food_id (PK)    |     | - payment_id (PK) |
             | - name            |     | - order_id (FK)   |
             | - price           |     | - amount           |
             | - restaurant_id (FK)|    | - payment_method   |
             | - calories        |     | - payment_status    |
             |-------------------|     | - payment_date     |
```

## Relational Schema Description

1. **Customer**  
   - `customer_id`: Unique identifier for the customer (Primary Key)  
   - `name`: Name of the customer  
   - `email`: Email address of the customer  
   - `phone`: Phone number of the customer  

2. **Restaurant**  
   - `restaurant_id`: Unique identifier for the restaurant (Primary Key)  
   - `name`: Name of the restaurant  
   - `location`: Physical location of the restaurant  
   - `rating`: User rating of the restaurant  

3. **Order**  
   - `order_id`: Unique identifier for the order (Primary Key)  
   - `order_date`: Date the order was placed  
   - `total_amount`: Total cost of the order  
   - `status`: Current status of the order  

4. **Order_Items**  
   - `order_item_id`: Unique identifier for each order item (Primary Key)  
   - `order_id`: Foreign key referencing `Order`  
   - `food_id`: Foreign key referencing `Food`  
   - `quantity`: Quantity of the food item ordered  
   - `price`: Price of the food item  

5. **Food**  
   - `food_id`: Unique identifier for the food item (Primary Key)  
   - `name`: Name of the food item  
   - `price`: Price of the food item  
   - `restaurant_id`: Foreign key referencing `Restaurant`  
   - `calories`: Caloric content of the food item  

6. **Payment**  
   - `payment_id`: Unique identifier for the payment (Primary Key)  
   - `order_id`: Foreign key referencing `Order`  
   - `amount`: Amount paid  
   - `payment_method`: Method used for the payment (e.g., credit card, PayPal)  
   - `payment_status`: Status of the payment (e.g., successful, pending)  
   - `payment_date`: Date the payment was made  

### Notes  
- The arrows in the diagram indicate the relationship between entities. For example, a `Customer` can place multiple `Orders`, and each `Order` can contain multiple `Order_Items`.  
- `Food` belongs to a `Restaurant`, and each `Order` can include various `Food` items.

### Conclusion  
This ER diagram and relational schema provide a comprehensive overview of the Online Food Ordering System structure and relationships between different entities.