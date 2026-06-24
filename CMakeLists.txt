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
        seminars/codeforces/second/five/main.cpp
        contests/second/A/main.cpp
        seminars/code/bfs/main.cpp
        seminars/codeforces/trird/A/main.cpp
        seminars/codeforces/trird/G/main.cpp
        seminars/codeforces/trird/B/main.cpp
        seminars/codeforces/trird/C/main.cpp
        "seminars/codeforces/trird/D/main .cpp"
        seminars/codeforces/trird/E/main.cpp
        seminars/codeforces/trird/F/main.cpp
        contests/second/B/main.cpp
        contests/second/C/main.cpp
        contests/second/D/main.cpp
        contests/second/E/main.cpp
        contests/second/F/main.cpp
        contests/second/G/main.cpp
        contests/second/H/main.cpp
        contests/second/I/main.cpp
        contests/second/J/main.cpp
        contests/third/A/main.cpp
        contests/third/B/main.cpp
        seminars/codeforces/fourth/A/main.cpp
        seminars/codeforces/fourth/B/main.cpp
        seminars/codeforces/fourth/C/main.cpp
        seminars/codeforces/fourth/D/main.cpp
        contests/third/C/main.cpp
        contests/third/D/main.cpp
        "seminars/code/мосты и точки сочленения - Тарьян/мосты.cpp"
        "seminars/code/мосты и точки сочленения - Тарьян/точки сочленения.cpp"
        contests/fourth/A/main.cpp
        contests/fourth/B/main.cpp
        contests/fourth/C/main.cpp
        contests/fourth/D/main.cpp
        contests/fourth/E/main.cpp
        contests/fourth/F/main.cpp
        contests/fourth/G/main.cpp
        contests/fifth/I/main.cpp
        contests/fifth/H/main2.cpp
        CW/first/A/main.cpp
        CW/first/B/main.cpp
        CW/C/main.cpp
        CW/E/main.cpp
        CW/F/main.cpp
        CW/D/main.cpp
        "divisions/Codeforces Round 1098 (Div. 2)/A/main.cpp"
        "divisions/Codeforces Round 1098 (Div. 2)/B/main.cpp"
        "divisions/Codeforces Round 1098 (Div. 2)/С/main.cpp"
        seminars/codeforces/fifth/A/main.cpp
        seminars/codeforces/fifth/B/main.cpp
        seminars/codeforces/fifth/C/main.cpp
        seminars/codeforces/fifth/D/main.cpp
        seminars/codeforces/fifth/E/main.cpp
        seminars/codeforces/fifth/F/main.cpp
        seminars/codeforces/fifth/G/main.cpp
        seminars/codeforces/fifth/G/main2.cpp
        seminars/sixth/A/main.cpp
        seminars/sixth/B/main.cpp
        seminars/sixth/C/main.cpp
        seminars/sixth/D/main.cpp
        seminars/sixth/E/main.cpp
        seminars/sixth/F/main.cpp
        seminars/sixth/G/main.cpp
        "lectures/kurenkov/RSQ & RMQ/A/main.cpp"
        "lectures/kurenkov/RSQ & RMQ/B/main.cpp"
        "lectures/kurenkov/RSQ & RMQ/G.cpp"
        "lectures/kurenkov/RSQ & RMQ/D/main.cpp"
        "lectures/kurenkov/RSQ & RMQ/L/main.cpp"
        "lectures/kurenkov/RSQ & RMQ/J/main.cpp"
        seminars/codeforces/fourth/G/main.cpp
        seminars/codeforces/fourth/G/main.cpp
        "lectures/kurenkov/RSQ & RMQ/Segment Tree.cpp"
        contests/seven/A/main.cpp
        contests/seven/B/main.cpp
        "seminars/codeforces/типа хэшыыыыыы/A/main.cpp"
        "seminars/codeforces/типа хэшыыыыыы/C/main.cpp"
        "seminars/codeforces/типа хэшыыыыыы/G/main.cpp"
        "seminars/codeforces/типа хэшыыыыыы/B/main.cpp"
        contests/seven/E/maijn.cpp
        contests/seven/F/main.cpp
        contests/seven/D/main.cpp
        contests/seven/D/main2.cpp
        contests/seven/draft.cpp
        "divisions/ECR 191/A/main.cpp"
        "divisions/ECR 191/B/main.cpp"
        "divisions/ECR 191/C/main.cpp"
        "divisions/ECR 191/draft.cpp"
        seminars/codeforces/couples/A/main.cpp
        seminars/codeforces/couples/B/main.cpp
        seminars/codeforces/couples/F/main.cpp
        seminars/codeforces/couples/H/main.cpp
        seminars/codeforces/couples/C/main.cpp
        seminars/codeforces/couples/E/main.cpp
        seminars/codeforces/couples/L/main.cpp
        seminars/codeforces/couples/G/main.cpp
        "contests/9 - hash/A/main.cpp"
        "contests/9 - hash/C/main.cpp"
        "contests/10 - strings/B/main.cpp"
        "contests/10 - strings/C/main.cpp"
        "contests/10 - strings/D/main.cpp"
        "contests/10 - strings/E/main.cpp"
        "contests/10 - strings/F/main.cpp"
        "contests/10 - strings/G/main.cpp"
        "contests/10 - strings/H/main.cpp"
        seminars/codeforces/couples/M/main.cpp
)
include_directories(lectures)
include_directories(seminars)
include_directories(useful)
include_directories(contests)