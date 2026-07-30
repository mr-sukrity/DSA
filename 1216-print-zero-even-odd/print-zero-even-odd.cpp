class ZeroEvenOdd {
private:
    int n;
    int current;
    std::mutex mtx;
    std::condition_variable cv;
    int turn; // 0 = zero, 1 = odd, 2 = even

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        current = 1;
        turn = 0; // start with zero
    }

    void zero(std::function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return turn == 0; });
            printNumber(0);
            if (current % 2 == 1) {
                turn = 1; // odd’s turn
            } else {
                turn = 2; // even’s turn
            }
            cv.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return turn == 2 || current > n; });
            if (current > n) return;
            printNumber(current++);
            turn = 0; // back to zero
            cv.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return turn == 1 || current > n; });
            if (current > n) return;
            printNumber(current++);
            turn = 0; // back to zero
            cv.notify_all();
        }
    }
};