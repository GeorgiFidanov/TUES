CREATE DATABASE IF NOT EXISTS MovieDB;

USE moviedb;

CREATE TABLE IF NOT EXISTS Genre (
ID int,
Name varchar(100)
);

CREATE TABLE IF NOT EXISTS Actor (
ID int,
FName varchar(255),
LName varchar(255),
BDate DateTime,
CountryID int,
Popularity decimal(4,2),
DoD DateTime
);

CREATE TABLE IF NOT EXISTS Director (
ID int,
FName varchar(255),
LName varchar(255),
BirthDate DateTime
);

CREATE TABLE IF NOT EXISTS Country (
ID int,
Name varchar(100)
);

CREATE TABLE IF NOT EXISTS Language (
ID int,
Name varchar(100)
);

CREATE TABLE IF NOT EXISTS Review (
ID int,
Text varchar(4000),
DatePosted DateTime
);

CREATE TABLE IF NOT EXISTS Reviewer (
ID int,
UName varchar(200),
FName varchar(200),
LName varchar(200),
Credibility decimal(3,2),
DateRegistered datetime
);

CREATE TABLE IF NOT EXISTS Studio (
ID int,
Name varchar(500),
CountryID int,
DateCreated DateTime
);

CREATE TABLE IF NOT EXISTS Movie (
ID int,
Name varchar(1000),
StudioID int,
LanguageID int,
Budget int,
Revenue int,
Length smallint,
Description varchar(10000),
ReleaseDate DateTime
);