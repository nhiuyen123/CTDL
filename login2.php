<?php
// Thiết lập thông tin kết nối đến database

$servername = "db-server-lab7.cubeob65dm6q.ap-southeast-1.rds.amazonaws.com";

$username = "admin";
$password = "nhi12345";
$dbname = "MyDB";
// Tạo kết nối đến database
$conn = new mysqli($servername, $username, $password, $dbname);
// Kiểm tra kết nối


if ($conn->connect_error) {
die("Kết nối không thành công: " . $conn->connect_error);
}
// Kiểm tra nếu form đã submit
if ($_SERVER["REQUEST_METHOD"] == "POST") {
// Lấy giá trị từ form
$username = $_POST["username"];
$password = $_POST["password"];
// Truy vấn lấy dữ liệu từ database
$sql = "SELECT * FROM User WHERE username='$username' AND
password='$password'";
$result = $conn->query($sql);
// Kiểm tra số lượng bản ghi trả về
if ($result->num_rows > 0) {
// Nếu có, đăng nhập thành công
echo "Bạn đã đăng nhập thành công";
// Thực hiện các hành động cần thiết, ví dụ như đưa người dùng vào trang chào mừng
} else {
// Nếu không, đăng nhập không thành công
echo "Bạn đã đăng nhập không thành công"; }
}
?>

<!DOCTYPE html>
<html>

<head>
<meta charset="UTF-8">
<title>Đăng nhập</title>
</head>
<body>
<h2>Đăng nhập</h2>
