<?php
$servername = "your_server";
$username = "user";
$password = "03012007";
$dbname = "saldo";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$uid = $_GET['uid'];
$opened = $_GET['opened'];
$date = date('Y-m-d H:i:s');
$price = 14500;

// Log the tap event
$sql = "INSERT INTO tap_logs (uid, action, price, datetime) VALUES ('$uid', '$opened', $price, '$date')";
if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully";
} else {
    echo "Error updating record: " . $conn->error;
}

// Calculate total taps and total price
$result = $conn->query("SELECT COUNT(*) as total_taps, SUM(price) as total_price FROM tap_logs WHERE action = '1'");
if ($result->num_rows > 0) {
    $row = $result->fetch_assoc();
    $total_taps = $row['total_taps'];
    $total_price = $row['total_price'];
    echo "Total Taps: " . $total_taps . " | Total Price: " . $total_price;
} else {
    echo "No data found";
}

$conn->close();
?>