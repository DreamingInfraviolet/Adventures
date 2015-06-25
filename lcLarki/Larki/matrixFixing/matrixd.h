#pragma once
namespace math
{ 
    template <class T>
    class _vec2
    {
    public:
        T x, y;
        _vec2<T>();
        void reset();
    };

    typedef _vec2<float> vec2;
}