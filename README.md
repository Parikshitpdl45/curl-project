<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Curl Project Visualization</title>
</head>
<body>
    <h2>record.txt data</h2>
  
# Curl Project (C/C++, PHP, JavaScript)

This project demonstrates a multi-platform application using:

- C/C++ with libcurl (backend data source)
- PHP on server to receive data
- JavaScript/HTML to visualize data in browser

## Project Structure

- c-client/main.cpp  
  C/C++ program that generates two random numbers and sends them
  to the server using HTTP POST via libcurl.

- server/receiver.php  
  PHP script that receives POST data and appends it to record.txt.

- frontend/index.html  
  Web page that fetches record.txt and displays the stored data.

## How It Works

1. The C program (`main.cpp`) runs on a PC
2. It sends data (v1, v2) to the server using libcurl
3. `receiver.php` stores the data in `record.txt`
4. `index.html` fetches `record.txt` and shows the result

## Server

- Server: shell.puv.fi
- PHP file location: ~/public_html/receiver.php

## Notes

- HTTP is used instead of HTTPS due to certificate limitations
- record.txt is created automatically by receiver.php