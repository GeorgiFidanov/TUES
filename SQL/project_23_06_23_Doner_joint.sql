-- Create tables if they don't exist
CREATE DATABASE IF NOT EXISTS Doner_joint;
USE Doner_joint;

CREATE TABLE IF NOT EXISTS UserType (
  ID INT AUTO_INCREMENT,
  Name VARCHAR(255),
  Description VARCHAR(255),
  PRIMARY KEY (ID)
);

CREATE TABLE IF NOT EXISTS Customer (
  ID INT AUTO_INCREMENT,
  UserType_ID INT,
  PaymentType INT,
  Money DOUBLE,
  PRIMARY KEY (ID),
  FOREIGN KEY (UserType_ID) REFERENCES UserType(ID)
);

CREATE TABLE IF NOT EXISTS Employee (
  ID INT AUTO_INCREMENT,
  UserType_ID INT,
  Salary DOUBLE,
  PRIMARY KEY (ID),
  FOREIGN KEY (UserType_ID) REFERENCES UserType(ID)
);

CREATE TABLE IF NOT EXISTS Storage (
  Name VARCHAR(255),
  Quantity INT,
  PRIMARY KEY (Name)
);

CREATE TABLE IF NOT EXISTS Chef (
  ID INT AUTO_INCREMENT,
  Employee_ID INT,
  Salary DOUBLE,
  PRIMARY KEY (ID),
  FOREIGN KEY (Employee_ID) REFERENCES Employee(ID)
);

-- Chef-Storage relationship table
CREATE TABLE IF NOT EXISTS ChefStorage (
  ChefID INT,
  StorageName VARCHAR(255),
  PRIMARY KEY (ChefID, StorageName),
  FOREIGN KEY (ChefID) REFERENCES Chef(ID),
  FOREIGN KEY (StorageName) REFERENCES Storage(Name)
);

CREATE TABLE IF NOT EXISTS Ingredient (
  Name VARCHAR(255),
  Quantity INT,
  PRIMARY KEY (Name)
);

CREATE TABLE IF NOT EXISTS StorageIngredient (
  StorageName VARCHAR(255),
  IngredientName VARCHAR(255),
  PRIMARY KEY (StorageName, IngredientName),
  FOREIGN KEY (StorageName) REFERENCES Storage(Name),
  FOREIGN KEY (IngredientName) REFERENCES Ingredient(Name)
);

CREATE TABLE IF NOT EXISTS DrinkItem (
  ID INT AUTO_INCREMENT,
  Name VARCHAR(255),
  Price DOUBLE,
  Count INT,
  PRIMARY KEY (ID)
);

CREATE TABLE IF NOT EXISTS FoodItem (
  ID INT AUTO_INCREMENT,
  Name VARCHAR(255),
  Price DOUBLE,
  Count INT,
  PRIMARY KEY (ID)
);

CREATE TABLE IF NOT EXISTS DonerType (
  ID INT AUTO_INCREMENT,
  Name VARCHAR(255),
  Ingredients TEXT,
  PRIMARY KEY (ID)
);

CREATE TABLE IF NOT EXISTS DonerMenu (
  ID INT AUTO_INCREMENT,
  DonerTypeID INT,
  PRIMARY KEY (ID),
  FOREIGN KEY (DonerTypeID) REFERENCES DonerType(ID)
);

CREATE TABLE IF NOT EXISTS OrderTable (
  OrderID INT AUTO_INCREMENT,
  CustomerID INT,
  ChefID INT,
  TotalPrice DOUBLE,
  FoodItemID INT,
  DrinkItemID INT,
  DonerMenuID INT,
  PRIMARY KEY (OrderID),
  FOREIGN KEY (CustomerID) REFERENCES Customer(ID),
  FOREIGN KEY (ChefID) REFERENCES Chef(ID),
  FOREIGN KEY (FoodItemID) REFERENCES FoodItem(ID),
  FOREIGN KEY (DrinkItemID) REFERENCES DrinkItem(ID),
  FOREIGN KEY (DonerMenuID) REFERENCES DonerMenu(ID)
);
