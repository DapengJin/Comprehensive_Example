cmake_minimum_required(VERSION 3.16)
project(Comprehensive_Example)

set(CMAKE_CXX_STANDARD 14)

add_executable(Comprehensive_Example main.cpp Account.cpp Account.h Date.cpp Date.h Accumulator.cpp Accumulator.h SavingsAccount.cpp SavingsAccount.h CreditAccount.cpp CreditAccount.h)