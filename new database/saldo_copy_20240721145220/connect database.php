<?php
$servername = "localhost";
$username = "purnama";
$password = "123tuyul";
$dbname = "saldo";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$uid = $_GET['uid'];
$price = $_GET['price'];

$sql = "INSERT INTO events (uid, price, timestamp) VALUES ('$uid', '$price', NOW())";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
