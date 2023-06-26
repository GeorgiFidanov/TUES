-- Create the database if it doesn't exist
CREATE DATABASE IF NOT EXISTS test;

-- Use the test database
USE test;

-- Users table
CREATE TABLE IF NOT EXISTS Users (
    UserID INT PRIMARY KEY,
    Name VARCHAR(50),
    Email VARCHAR(50),
    Password VARCHAR(50)
);

-- Categories table
CREATE TABLE IF NOT EXISTS Categories (
    CategoryID INT PRIMARY KEY,
    CategoryName VARCHAR(50)
);

-- Events table
CREATE TABLE IF NOT EXISTS Events (
    EventID INT PRIMARY KEY,
    EventName VARCHAR(100),
    EventDateTime DATETIME,
    CategoryID INT,
    FOREIGN KEY (CategoryID) REFERENCES Categories(CategoryID)
);

-- FavoriteEvents table
CREATE TABLE IF NOT EXISTS FavoriteEvents (
    UserID INT,
    EventID INT,
    FOREIGN KEY (UserID) REFERENCES Users(UserID),
    FOREIGN KEY (EventID) REFERENCES Events(EventID)
);

-- Tickets table
CREATE TABLE IF NOT EXISTS Tickets (
    TicketID INT PRIMARY KEY,
    UserID INT,
    EventID INT,
    Price DECIMAL(10, 2),
    PaymentStatus VARCHAR(20),
    FOREIGN KEY (UserID) REFERENCES Users(UserID),
    FOREIGN KEY (EventID) REFERENCES Events(EventID)
);

-- AttachedFiles table
CREATE TABLE IF NOT EXISTS AttachedFiles (
    FileID INT PRIMARY KEY,
    EventID INT,
    FileName VARCHAR(100),
    FilePath VARCHAR(200),
    FOREIGN KEY (EventID) REFERENCES Events(EventID)
);

-- Comments table
CREATE TABLE IF NOT EXISTS Comments (
    CommentID INT PRIMARY KEY,
    UserID INT,
    EventID INT,
    CommentText VARCHAR(500),
    Rating INT,
    FOREIGN KEY (UserID) REFERENCES Users(UserID),
    FOREIGN KEY (EventID) REFERENCES Events(EventID)
);
