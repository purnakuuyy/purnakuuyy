CREATE DATABASE pintu_otomatis;

USE pintu_otomatis;

CREATE TABLE pintu_log (
  id INT AUTO_INCREMENT PRIMARY KEY,
  status VARCHAR(10) NOT NULL,
  timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
);

