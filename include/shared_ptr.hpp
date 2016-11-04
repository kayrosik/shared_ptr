template <typename T>
class shared_ptr {
public:
    shared_ptr();
    shared_ptr(T* ptr);
    shared_ptr(shared_ptr const & other);
    shared_ptr(shared_ptr && other);
    auto operator= (shared_ptr const & other)->shared_ptr &;
    auto operator =(shared_ptr && other) -> shared_ptr &;
    auto operator ->() const -> T *;
    auto operator *() const -> T *
    ~shared_ptr();
    auto count() const->size_t;
 
private:
    T* ptr_;
    size_t count;
};
//_____________________________________________________________________________________________________
template<typename T>
shared_ptr<T>::shared_ptr():ptr_(nullptr), count(0){}
 
template<typename T>
shared_ptr<T>::shared_ptr(T * ptr): ptr_(ptr), count(1){}
 
template<typename T>
shared_ptr<T>::shared_ptr(shared_ptr const & other) : count(other.count), ptr_(other.ptr_) { 
    count++; 
}
 
template<typename T>
auto shared_ptr<T>::operator=(shared_ptr const & other)->shared_ptr & {
    if (this != &other) {
        if (count) {
            if (count == 1) {
                count==0;
                delete ptr_;
            }
            else count--;
        }
 
        ptr_ = other.ptr_;
        count = other.count;
        count++;
    }
    return *this;
}

template<typename T>
 shared_ptr<T>::shared_ptr(shared_ptr && other): ptr_(other.ptr_),count(other.count)
    {
        other.ptr_ = nullptr;
    }
    
    template<typename T>
    auto shared_ptr<T>::operator =(shared_ptr && other) -> shared_ptr &
    {
        if (this != &other) {
        if (count) {
            if (count == 1) {
                count==0;
                delete ptr_;
            }
            else count--;
        }
 
        ptr_ = other.ptr_;
        count = other.count;
       other.ptr_=nullptr;
    }
    return *this;
    }

 
template<typename T>
shared_ptr<T>::~shared_ptr(){
    if (count) {
        if (count == 1) {
            count==0;
            delete ptr;
        }
        else count--;
    }
}
 
template<typename T>
auto shared_ptr<T>:count() const->size_t{
    return (count) ? count : 0;
}
 template<typename T>
 auto shared_ptr<T>::operator ->() const -> T *
    {
        return ptr_;
    }
    

   template<typename T>
    auto shared_ptr<T>::operator *() const -> T *
    {
        return *(ptr_);
    }
