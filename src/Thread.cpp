//
// Created by coen320 on 2022-11-11.
//
class Thread {
private:
    int rc;
    pthread_attr_t attr;
    pthread_t pthread;
public:
    Thread() {
        rc = pthread_attr_init(&attr);
        rc = pthread_create(&threadC, &attr, threadCustomized, NULL);
    };

    void *threadCustomized(void *arg) {
        int policy;
        int detach_state;
        exit();
        return NULL;
    }

    void join() {
        pthread_join(pthread, NULL);
    }

    void exit() {
        pthread_attr_destroy(&attr);
        pthread_exit(NULL);
    }
};