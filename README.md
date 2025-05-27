# 🔍 Log Parser Tool

A simple command-line tool written in C for parsing and analyzing log files.  
It supports log level filtering, optional time-based sorting, and log statistics.

## 📦 Features

- Parse logs in the format: `[TIME] [LEVEL] MESSAGE`
- Filter logs by level; `INFO`, `WARNING`, `ERROR`
- Sort logs by time
- Display count summary for each log level

## 🖥️ Sample Log Format
    - [11:05] [INFO] System started
    - [09:15] [ERROR] Failed to open database
    - [10:45] [INFO] User login successful

## ▶️ Run
    - ./log_parser -f <filename> [options]
    - **📘 Options**
       - "-f <filename>": specify log file to be parsed (required)
    - **📘 Options**
       - "-l <level>": filter logs by level
       - "-s": sort logs by time 
    - **EXAMPLE**
        - ./log_parser -f sample.log
        - ./log_parser -f sample.log -l ERROR
        - ./log_parser -f sample.log -s
        - ./log_parser -f sample.log -l INFO -s

## 📊 Output Example
    ...
    - [11:15] [ERROR] Service timeout
    - [15:45] [ERROR] Deadlock detected
    - [13:00] [ERROR] Sync conflict

[INFO]: 56      [ERROR]: 21     [WARNING]: 23

## 🛠️ Future Improvement
    - Add support for outputting results to a file using -o <outputfile> option
    - Enable exporting logs in JSON or CSV format
    - Create a utility program that generates random sample logs for testing
    - Improve log parser to handle and extract time, level, and message from files with custom or varied formats using regex.h
