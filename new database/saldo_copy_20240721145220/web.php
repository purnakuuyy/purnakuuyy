<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>RFID Events</title>
  <link href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
  <div class="container">
    <h1 class="mt-5">RFID Event Log</h1>
    <table class="table table-striped mt-3">
      <thead>
        <tr>
          <th>UID</th>
          <th>Date</th>
          <th>Time</th>
          <th>Price</th>
        </tr>
      </thead>
      <tbody>
        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "your_database";

        $conn = new mysqli($servername, $username, $password, $dbname);

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $sql = "SELECT uid, DATE(timestamp) as date, TIME(timestamp) as time, price FROM events";
        $result = $conn->query($sql);

        if ($result->num_rows > 0) {
            while($row = $result->fetch_assoc()) {
                echo "<tr><td>" . $row["uid"]. "</td><td>" . $row["date"]. "</td><td>" . $row["time"]. "</td><td>" . $row["price"]. "</td></tr>";
            }
        } else {
            echo "<tr><td colspan='4'>No results</td></tr>";
        }

        $conn->close();
        ?>
      </tbody>
    </table>
    <?php
      $conn = new mysqli($servername, $username, $password, $dbname);
      $sql = "SELECT SUM(price) as total FROM events";
      $result = $conn->query($sql);
      if ($row = $result->fetch_assoc()) {
          echo "<h3>Total Price: " . $row['total'] . "</h3>";
      }
      $conn->close();
    ?>
  </div>
</body>
</html>
