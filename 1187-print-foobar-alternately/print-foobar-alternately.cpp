class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool fooTurn;

public:
    FooBar(int n) {
        this->n = n;
        fooTurn = true; // start with foo
    }

    void foo(std::function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return fooTurn; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            fooTurn = false; // next turn is bar
            cv.notify_all();
        }
    }

    void bar(std::function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return !fooTurn; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            fooTurn = true; // next turn is foo
            cv.notify_all();
        }
    }
};