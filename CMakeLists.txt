cmake_minimum_required(VERSION 3.26)
project(flower_exchange)

set(CMAKE_CXX_STANDARD 14)

add_executable(flower_exchange
        main.cpp
        CSVHandler.cpp
        ExchangeApp.cpp
        ExecutionReport.cpp
        Order.cpp
        OrderBook.cpp
        Validator.cpp)
