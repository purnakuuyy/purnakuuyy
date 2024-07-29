CREATE TABLE rfid_transactions (
    id INT AUTO_INCREMENT PRIMARY KEY,
    rfid_id VARCHAR(255) NOT NULL,
    status ENUM('low', 'high') NOT NULL,
    price DECIMAL(10, 2) DEFAULT 0,
    transaction_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Trigger to update price when status is 'high'
DELIMITER //
CREATE TRIGGER update_price_on_high
BEFORE INSERT ON rfid_transactions
FOR EACH ROW
BEGIN
    IF NEW.status = 'high' THEN
        SET NEW.price = 14500;
    END IF;
END;
//
DELIMITER ;

SELECT 
    DATE_FORMAT(transaction_time, '%W') AS hari,
    DATE_FORMAT(transaction_time, '%e %M %Y') AS tanggal,
    COUNT(*) AS total_orang,
    SUM(price) AS total_harga
FROM 
    rfid_transactions
WHERE 
    status = 'high'
GROUP BY 
    DATE(transaction_time);
