#include <iostream>
template <typename T>
class uniquePtr {
public:
    // Constructor
    explicit uniquePtr(T* ptr = nullptr) : ptr_(ptr) {}

    // Destructor
    ~uniquePtr() {
        delete ptr_;
    }

    // Copy constructor and assignment operator deleted
    uniquePtr(const uniquePtr&) = delete;
    uniquePtr& operator=(const uniquePtr&) = delete;

    // Move constructor and assignment operator
    uniquePtr(uniquePtr&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    uniquePtr& operator=(uniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    // Member functions
    T* get() const noexcept {
        return ptr_;
    }

    T* release() noexcept {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }

    void reset(T* ptr = nullptr) noexcept {
        delete ptr_;
        ptr_ = ptr;
    }

    T& operator*() const noexcept {
        return *ptr_;
    }

    T* operator->() const noexcept {
        return ptr_;
    }

    explicit operator bool() const noexcept {

        return ptr_ != nullptr;
    }

private:
    T* ptr_;
};

int
main(void)
{
    int* a = new int(10);
    uniquePtr<int> p(a);
    std::cout << p.get() << std::endl; 
    // p.release();
    // uniquePtr<int> p2(a);
    uniquePtr<int> p2 = std::move(p);
    std::cout << "p: " << p.get() << std::endl;
    std::cout << "p2: " << p2.get() << std::endl; 
    return 0;
}
