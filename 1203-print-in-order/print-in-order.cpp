class Foo {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int step;

public:
    Foo() {
        step = 1; // start with first
    }

    void first(std::function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        step = 2; // allow second
        cv.notify_all();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return step == 2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        step = 3; // allow third
        cv.notify_all();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return step == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};