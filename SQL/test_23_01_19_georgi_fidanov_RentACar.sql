CREATE DATABASE IF NOT EXISTS georgi_fidanov_4_RentACar_1;

USE georgi_fidanov_4_RentACar_1;
--  drop database georgi_fidanov_4_RentACar_1;
CREATE TABLE IF NOT EXISTS class (
	id INT PRIMARY KEY AUTO_INCREMENT,
    type_of_class VARCHAR(40),
    price int not null
);

CREATE TABLE IF NOT EXISTS car (
	id INT PRIMARY KEY AUTO_INCREMENT,
    model VARCHAR(30) NOT NULL,
    brand VARCHAR(30) NOT NULL,
    colour VARCHAR(30) NOT NULL,
    `date_of_creation` DATETIME NOT NULL,
    `count_of_km` INT DEFAULT 0,
    -- ("budget", "comfort", "luks", "heavy", "big_cap")
    class_id  int NOT NULL,
    FOREIGN KEY (class_id) REFERENCES class(id)
);

CREATE TABLE IF NOT EXISTS customers (
	id INT PRIMARY KEY AUTO_INCREMENT,
    number_of_sumps VARCHAR(30) NOT NULL,
    first_name VARCHAR(30) NOT NULL,
    middle_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(30) NOT NULL,
    nationality VARCHAR(30) NOT NULL,
    phone_num VARCHAR(30) NOT NULL,
    email VARCHAR(60) NOT NULL
);

CREATE TABLE IF NOT EXISTS locations (
	id INT PRIMARY KEY AUTO_INCREMENT,
    city_name VARCHAR(30) NOT NULL,
	address VARCHAR(60)  NOT NULL,
    phone_num VARCHAR(30) NOT NULL
);

CREATE TABLE IF NOT EXISTS reserved_cars(
	id INT NOT NULL,
	customer INT NOT NULL,
    car INT NOT NULL,
	`start_of_reservation` DATETIME NOT NULL,
    `end_of_reservation` DATETIME NOT NULL,
    address_got INT NOT NULL,
    address_given INT NOT NULL,
    price DOUBLE NOT NULL,
    rent DOUBLE NOT NULL,
    CONSTRAINT pk_reserved_cars PRIMARY KEY (customer, car, address_got, address_given),
    CONSTRAINT fk_history_customers FOREIGN KEY (customer) REFERENCES customers(id),
    CONSTRAINT fk_history_cars FOREIGN KEY (car) REFERENCES car(id),
    CONSTRAINT fk_history_location_got FOREIGN KEY (address_got) REFERENCES locations(id),
    CONSTRAINT fk_history_location_given FOREIGN KEY (address_given) REFERENCES locations(id)
);