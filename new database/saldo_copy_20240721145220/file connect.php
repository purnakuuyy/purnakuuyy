<?php
$servername = "localhost";
$username = "purnama";
$password = "123tuyul";
$dbname = "saldo";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $rfid = $_POST['rfid'];
    $price = 14500;
    
    $sql = "INSERT INTO rfid_transactions (rfid_id, status, price) VALUES ('$rfid', 'high', $price)";
    
    if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}

$conn->close();
?>
