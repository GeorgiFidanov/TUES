CREATE DATABASE IF NOT EXISTS appliances;

USE appliances;
-- drop database ivaylo_kanyov_10_appliances;

CREATE TABLE IF NOT EXISTS customers (
	id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(30) NOT NULL,
    middle_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(30) NOT NULL,
    points DOUBLE DEFAULT 0
);

CREATE TABLE IF NOT EXISTS appliances (
	id INT PRIMARY KEY AUTO_INCREMENT,
    model VARCHAR(30) NOT NULL,
    brand VARCHAR(30) NOT NULL,
    category VARCHAR(30) NOT NULL,
    height DOUBLE NOT NULL,
    lenght DOUBLE NOT NULL,
    width DOUBLE NOT NULL,
    size VARCHAR(30) NOT NULL,
    `count` INT DEFAULT 0,
    price DOUBLE NOT NULL
);

CREATE TABLE IF NOT EXISTS purchase_history (
	id INT,
	customer INT NOT NULL,
    item INT NOT NULL,
    `date` DATETIME NOT NULL,
    `count` INT NOT NULL,
    CONSTRAINT pk_purchase_history PRIMARY KEY (customer, item, `date`),
    CONSTRAINT fk_history_customers FOREIGN KEY (customer) REFERENCES customers(id),
    CONSTRAINT fk_history_appliances FOREIGN KEY (item) REFERENCES appliances(id)
);