cmake_minimum_required(VERSION 4.0)
project(algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(algorithms main.cpp
        lectures/main.cpp
        seminars/codeforces/first/one/main.cpp
        seminars/codeforces/first/two/main.cpp
        seminars/codeforces/first/three/main.cpp
        seminars/codeforces/first/five/main.cpp
        seminars/codeforces/extra/first/main.cpp
        seminars/codeforces/extra/second/main.cpp
        seminars/codeforces/extra/three/main.cpp
        seminars/codeforces/first/six/main.cpp
        seminars/codeforces/first/draft.cpp
        seminars/codeforces/first/four/main.cpp
        seminars/codeforces/first/seven/main.cpp
        contests/first/main.cpp
        contests/first/two/main.cpp
        contests/first/three/main.cpp
        contests/first/four/main.cpp
        contests/first/five/main.cpp
        contests/first/six/main.cpp
        contests/first/seven/main.cpp
        contests/first/eight/main.cpp
        contests/first/twelve/main.cpp
        contests/first/nine/main.cpp
        contests/first/ten/main.cpp
        contests/first/eleven/main.cpp
        "seminars/code/chicken and fox/main.cpp"
        seminars/codeforces/second/one/main.cpp
        seminars/codeforces/second/six/main.cpp
        seminars/codeforces/second/two/main.cpp
        seminars/codeforces/second/three/main.cpp
        seminars/codeforces/second/four/main.cpp
        seminars/codeforces/second/five/main.cpp)
include_directories(lectures)
include_directories(seminars)
include_directories(useful)
include_directories(contests)