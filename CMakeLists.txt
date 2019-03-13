cmake_minimum_required(VERSION 3.13)
project(c___demo)

set(CMAKE_CXX_STANDARD 14)

add_executable(c___demo main.cpp queryText/QueryText.cpp queryText/QueryText.h queryText/QueryResult.h copy/CopyConstructor.cpp copy/CopyConstructor.h copy/CopyOperator.cpp copy/CopyOperator.h oo/Basket.cpp oo/Basket.h oo/Quote.cpp oo/Quote.h queryText/Query.h queryText/WordQuery.h queryText/Query.cpp queryText/NotQuery.h queryText/BinaryQuery.h queryText/AndQuery.h queryText/OrQuery.h)