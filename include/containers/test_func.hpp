#ifndef test_func_hpp
#define test_func_hpp

class test
{
private:
    struct Invoker
    {
        virtual void invoke() = 0;
    };

    template<typename T>
    class Func : public Invoker
    {
    private:
        T func;
        void invoke() override { func(); }
    public:
        Func(T f) : func(f)
        {
        }
    };

    Invoker* inv;

public:
    template<typename T>
    test(T func)
    {
        inv = new Func<T>(func);
    }

    void invoke()
    {
        inv->invoke();
    }
};

#endif // test_func_hpp