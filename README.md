raii_mutex
==========

Lightweight, header only, RAII version of POSIX mutexes.

Sample code:

```
class Integer {
private:
    mutable Mutex   _mutex;
    int             _i;

public:
    Integer()
        : _mutex(),
          _i(0)
    {
    }

    void setValue(int v)
    {
        RAIIMutex lock(_mutex);
        _i = v;
    }

    int getValue() const
    {
        RAIIMutex lock(_mutex);
        return _i;
    }
};
```
