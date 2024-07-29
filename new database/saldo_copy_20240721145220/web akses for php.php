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

// Fetch data from the table
$sql = "SELECT id, rfid_id, status, price, transaction_time FROM rfid_transactions";
$result = $conn->query($sql);
?>

<!DOCTYPE html>
<html>
<head>
    <title>RFID Transactions</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
</head>
<body>
    <div class="container">
        <h1 class="mt-5">RFID Transactions</h1>
        <table class="table table-striped mt-3">
            <thead>
                <tr>
                    <th>ID</th>
                    <th>RFID</th>
                    <th>Status</th>
                    <th>Price</th>
                    <th>Date</th>
                </tr>
            </thead>
            <tbody>
                <?php
                if ($result->num_rows > 0) {
                    // Output data of each row
                    while($row = $result->fetch_assoc()) {
                        echo "<tr>
                                <td>" . $row["id"]. "</td>
                                <td>" . $row["rfid_id"]. "</td>
                                <td>" . $row["status"]. "</td>
                                <td>" . $row["price"]. "</td>
                                <td>" . $row["transaction_time"]. "</td>
                              </tr>";
                    }
                } else {
                    echo "<tr><td colspan='5'>No results found</td></tr>";
                }
                $conn->close();
                ?>
            </tbody>
        </table>
    </div>
</body>
</html>
