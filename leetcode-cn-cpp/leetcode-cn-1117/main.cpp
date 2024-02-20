#include <cstdio>
#include <functional>
#include <semaphore.h>
#include <thread>

using namespace std;

class H2O {
private:
    sem_t sem_o;
    sem_t sem_h;
public:
    H2O() {
        sem_init(&sem_o, 0, 1);
        sem_init(&sem_h, 0, 2);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&sem_h);
        sem_wait(&sem_h);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        sem_post(&sem_o);
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&sem_o);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&sem_h);
        sem_post(&sem_h);
    }
};

int main(int argc, char* argv[]) {
    H2O h2_o;
    for (int i=0; i<20; i++) {
        std::thread thread([&]() {
            h2_o.oxygen([]() {
                printf("O");
            });
        });
        thread.join();
    }

    for (int i=0; i<40; i++) {
        std::thread thread([&]() {
            h2_o.hydrogen([]() {
                printf("H");
            });
        });
        thread.join();
    }
    printf("\n");
}
