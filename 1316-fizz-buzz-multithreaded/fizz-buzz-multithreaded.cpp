class FizzBuzz {
private:
    int n;
    int current;
    std::mutex mtx;
    std::condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        current = 1;
    }

    void fizz(std::function<void()> printFizz) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return (current > n) || (current % 3 == 0 && current % 5 != 0); });
            if (current > n) return;
            printFizz();
            current++;
            cv.notify_all();
        }
    }

    void buzz(std::function<void()> printBuzz) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return (current > n) || (current % 5 == 0 && current % 3 != 0); });
            if (current > n) return;
            printBuzz();
            current++;
            cv.notify_all();
        }
    }

    void fizzbuzz(std::function<void()> printFizzBuzz) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return (current > n) || (current % 15 == 0); });
            if (current > n) return;
            printFizzBuzz();
            current++;
            cv.notify_all();
        }
    }

    void number(std::function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return (current > n) || (current % 3 != 0 && current % 5 != 0); });
            if (current > n) return;
            printNumber(current);
            current++;
            cv.notify_all();
        }
    }
};