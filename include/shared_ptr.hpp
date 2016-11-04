#include <iostream>
#include <utility>
template <typename T>
class shared_ptr {
public:
    shared_ptr();
    explicit shared_ptr(T* ptr);
    shared_ptr(shared_ptr const & other);
    shared_ptr(shared_ptr && other);
    auto operator= (shared_ptr const & other)->shared_ptr &;
    auto operator =(shared_ptr && other) -> shared_ptr &;
    auto swap(shared_ptr& r) noexcept -> void;
    auto operator ->() const -> T *;
    auto operator *() const -> T *;
    auto get() const noexcept -> T *;
    ~shared_ptr();
    auto count() const->size_t;
 
private:
    T* ptr_;
    size_t *count_;
};

//_____________________________________________________________________________________________________
//_____________________________________________________________________________________________________
//_____________________________________________________________________________________________________
//_____________________________________________________________________________________________________

template<typename T> 
auto shared_ptr<T>::get() const noexcept -> T * {
	return ptr_;
}

template<typename T> 
auto shared_ptr<T>::swap(shared_ptr & other) noexcept -> void {
	std::swap(ptr_, other.ptr_);
	std::swap(count_, other.count_);
}

template<typename T>
shared_ptr<T>::shared_ptr():ptr_(nullptr), count_(nullptr){}
 
template<typename T>
shared_ptr<T>::shared_ptr(T * ptr): ptr_(ptr), count_(new size_t(1)){}
 
template<typename T>
shared_ptr<T>::shared_ptr(shared_ptr const & other) : count_(other.count_), ptr_(other.ptr_) { 
    (*count_)++; 
}
 
template<typename T>
auto shared_ptr<T>::operator =(const shared_ptr & other) -> shared_ptr & {
	if (this != &other) {
		this->~shared_ptr();
		ptr_ = nullptr;
		count_ = nullptr;
		ptr_ = other.ptr_;
		count_ = other.count_;
		++(*count_);
	}
	return *this;
}

template<typename T>
 shared_ptr<T>::shared_ptr(shared_ptr && other): ptr_(other.ptr_),count_(other.count_)
    {
        other.ptr_ = nullptr;
	 other.count_=nullptr;
    }
    
    template<typename T>
    auto shared_ptr<T>::operator =(shared_ptr && other) -> shared_ptr &
    {
        swap(other);
	return *this;
    }

 
template<typename T>
shared_ptr<T>::~shared_ptr(){
    if (count_) {
        if (*count_ == 1) {
            delete count_;
            delete ptr_;
        }
        else (*count_)--;
    }
}
 
template<typename T>
auto shared_ptr<T>::count() const->size_t{
   return (count_ != nullptr ? *count_ : 0);
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
