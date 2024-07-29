<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "pintu_otomatis";

// Buat koneksi
$conn = new mysqli($servername, $username, $password, $dbname);

// Cek koneksi
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$status = $_GET['status'];
$date = date('Y-m-d H:i:s');

$sql = "INSERT INTO pintu_log (status, timestamp) VALUES ('$status', '$date')";

if ($conn->query($sql) === TRUE) {
  echo "New record created successfully";
} else {
  echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
