#include <iostream>
#include <utility>
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
    auto operator *() const -> T *;
   auto get() const noexcept -> T *;
    ~shared_ptr();
    auto count() const->size_t;
 
private:
    T* ptr_;
    size_t count_;
};

template <class T, class... Args>
shared_ptr<T> make_shared(Args&& ...args);

template<class T, class ...Args>
shared_ptr<T> make_shared(Args && ...args) {
	return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

//_____________________________________________________________________________________________________
template<typename T> /*noexcept*/
auto shared_ptr<T>::get() const noexcept -> T * {
	return ptr_;
}

template<typename T>
shared_ptr<T>::shared_ptr():ptr_(nullptr), count_(0){}
 
template<typename T>
shared_ptr<T>::shared_ptr(T * ptr): ptr_(ptr), count_(1){}
 
template<typename T>
shared_ptr<T>::shared_ptr(shared_ptr const & other) : count_(other.count_), ptr_(other.ptr_) { 
    count_++; 
}
 
template<typename T>
auto shared_ptr<T>::operator=(shared_ptr const & other)->shared_ptr & {
    if (this != &other) {
        if (count_) {
            if (count_ == 1) {
                count_=0;
                delete ptr_;
            }
            else count_--;
        }
 
        ptr_ = other.ptr_;
        count_ = other.count_;
        count_++;
    }
    return *this;
}

template<typename T>
 shared_ptr<T>::shared_ptr(shared_ptr && other): ptr_(other.ptr_),count_(other.count_)
    {
        other.ptr_ = nullptr;
    }
    
    template<typename T>
    auto shared_ptr<T>::operator =(shared_ptr && other) -> shared_ptr &
    {
        if (this != &other) {
        if (count_) {
            if (count_ == 1) {
                count_=0;
                delete ptr_;
            }
            else count_--;
        }
 
        ptr_ = other.ptr_;
        count_ = other.count_;
       other.ptr_=nullptr;
    }
    return *this;
    }

 
template<typename T>
shared_ptr<T>::~shared_ptr(){
    if (count_) {
        if (count_ == 1) {
            count_=0;
            delete ptr_;
        }
        else count_--;
    }
}
 
template<typename T>
auto shared_ptr<T>::count() const->size_t{
    return (count_) ? count_ : 0;
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
