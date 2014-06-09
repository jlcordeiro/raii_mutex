#ifndef RAIIMUTEX_H
#define RAIIMUTEX_H

#include <pthread.h>

/*! Class representing a mutex. */
class Mutex
{
private:
    Mutex(const Mutex& other);

    pthread_mutex_t _pmutex;

public:
    Mutex()
    {
        pthread_mutex_init(&_pmutex, NULL);
    }

    ~Mutex()
    {
        pthread_mutex_destroy(&_pmutex);
    }

    /**
     * \brief Lock the mutex.
     */
    void Lock()
    {
        pthread_mutex_lock(&_pmutex);
    }

    /**
     * \brief Unlock the mutex.
     */
    void Unlock()
    {
        pthread_mutex_unlock(&_pmutex);
    }
};


/*! Class with a basic implementation of a RAII mutex. */
class RAIIMutex
{
private:
    RAIIMutex();
    RAIIMutex(const RAIIMutex&);

    Mutex& _refmutex;

public:
    /**
     * \brief Constructor
     * \param m Mutex to be used to lock/unlock resources.
     */
    RAIIMutex(Mutex& m)
        : _refmutex(m)
    {
        _refmutex.Lock();
    };

    /**
     * \brief Destructor
     */
    ~RAIIMutex()
    {
        _refmutex.Unlock();
    }
};

#endif /* end of include guard: RAIIMUTEX_H */
