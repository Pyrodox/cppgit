#include <iostream>
#include <memory>
#include <algorithm>
using std::cout; using std::allocator; using std::max; using std::uninitialized_fill;
using std::uninitialized_copy; using std::advance;

template <class T> class alloc
{
    public:
        T* allocate(size_t);
        void deallocate(T*, size_t);
        void construct(T*, const T&);
        void destroy(T*);
};

template <class T> class Lst
{
    public:    
        typedef T* iterator;    
        typedef const T* const_iterator;    
        typedef size_t size_type;    
        typedef T value_type;
   
        Lst() { create(); }    
        explicit Lst(size_type n, const T& t = T()) { create(n, t); }

        Lst(const Lst& v) { create(v.begin(), v.end()); }
        Lst& operator=(const Lst&);     
        ~Lst() { uncreate(); }  

        void push_back(const T& t) {
            if (avail == limit) {
                grow();
            }
            unchecked_append(t);
        }
        
        iterator erase(iterator p) { return erase_aux(p, p + 1); }
        iterator erase(iterator p, iterator p2) { return erase_aux(p, p2); }

        void clear() { uncreate(); }

        size_type size() const { return avail - data; }

        iterator begin() { return data; }    
        const_iterator begin() const { return data; }
    
        iterator end() { return avail; }    
        const_iterator end() const { return avail; }

    private:    
        iterator data;    
        iterator avail;   
        iterator limit;
    
        allocator<T> alloc;
     
        void create();    
        void create(size_type, const T&);    
        void create(const_iterator, const_iterator);
      
        void uncreate();

        void grow();    
        void unchecked_append(const T&);

        T* erase_aux(iterator, iterator);
};

template <class T> void Lst<T>::create()
{    
    data = avail = limit = 0;
}

template <class T> void Lst<T>::create(size_type n, const T& val)
{    
    data = alloc.allocate(n);
    limit = avail = data;
    advance(limit, n);
    advance(avail, n);
    uninitialized_fill(data, limit, val);
}

template <class T> void Lst<T>::create(const_iterator i, const_iterator j)
{    
    data = alloc.allocate(j - i);    
    limit = avail = uninitialized_copy(i, j, data);
}

template <class T> void Lst<T>::uncreate()
{    
    if (data) {
        iterator it = avail;        
        while (it != data) {            
            alloc.destroy(--it);        
        }

        alloc.deallocate(data, limit - data);    
    }        
    
    data = limit = avail = 0;
}

template <class T> Lst<T>& Lst<T>::operator=(const Lst& rhs)
{    
    if (&rhs != this) {        
        uncreate();        
        create(rhs.begin(), rhs.end());    
    }    

    return *this;
}

template <class T> void Lst<T>::grow()
{     
    size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
   
    iterator new_data = alloc.allocate(new_size);    
    iterator new_avail = uninitialized_copy(data, avail, new_data);
      
    uncreate();

    data = new_data;    
    avail = new_avail;
    advance(new_data, new_size);
    limit = new_data;
}

template <class T> void Lst<T>::unchecked_append(const T& val)
{    
    alloc.construct(avail++, val);
}

template <class T> T* Lst<T>::erase_aux(iterator p1, iterator p2)
{
    size_type newsize = size() - 1;

    iterator new_data = alloc.allocate(newsize);
    iterator newend = uninitialized_copy(p2, end(), new_data);

    create(data, p1);
            
    for (; new_data != newend; ++new_data) {
        push_back(*new_data);
    }

    return p2;
}

int main()
{
    Lst<int> a(5);
    *a.begin() = 1;
    auto b = 2;
    for (auto i = a.begin(); i != a.end(); ++i) {
        *i = b;
        cout << *i << "\n";
        b++;
    }
    cout << "\n";
    a.erase(a.begin() + 1);
    for (int i = 0; i < a.size(); ++i) {
        cout << *(a.begin() + i) << "\n";
    }
    //cout << a.begin() + 3;

    return 0;
}