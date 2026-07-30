class H2O {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int hydrogenCount;
    int oxygenCount;

public:
    H2O() {
        hydrogenCount = 0;
        oxygenCount = 0;
    }

    void hydrogen(std::function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return hydrogenCount < 2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        hydrogenCount++;
        if (hydrogenCount == 2 && oxygenCount == 1) {
            hydrogenCount = 0;
            oxygenCount = 0;
            cv.notify_all();
        } else {
            cv.notify_all();
        }
    }

    void oxygen(std::function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return oxygenCount < 1; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        oxygenCount++;
        if (hydrogenCount == 2 && oxygenCount == 1) {
            hydrogenCount = 0;
            oxygenCount = 0;
            cv.notify_all();
        } else {
            cv.notify_all();
        }
    }
};