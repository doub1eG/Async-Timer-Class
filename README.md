# Async-Timer-Class
Asynchronous single-shot timer on STL

### Use of other units of times
Сheck possible model definitions -> [Convenience duration typedefs](https://en.cppreference.com/w/cpp/header/chrono)

### Example

`using namespace std::chrono_literals;`

`int main()`
`{`

    auto foo = []() {std::cout << "---------------- Hello World ----------------\n"; };
    Timer t1{1,f};
    Timer t2{2,f};
    Timer t3{3,f};
    Timer t4{4,f};
    
    std::this_thread::sleep_for(2000ms);
    return 0;
`};`


