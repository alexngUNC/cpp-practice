#include <iostream>
using namespace std;
template <typename T>
class SharedPtr {
private:
	T* ptr;
	unsigned long* ref_count;
	void release() {
		if (ref_count != nullptr) {
			(*ref_count)--;
			if (*ref_count == 0) {
				delete ptr;
				delete ref_count;
				ptr = nullptr;
				ref_count = nullptr;
			}
		}
	}
public:
	// constructor
	SharedPtr(T* p = nullptr) {
		if (p != nullptr) {
			ref_count = new unsigned long(1);
			ptr = p;
		}
	}

	// copy constructor
	SharedPtr (const SharedPtr& p) {
		ptr = p.ptr;
		ref_count = p.ref_count;
		if (p.ref_count != nullptr)
			(*ref_count)++;
	}

	// assignment overload
	SharedPtr& operator= (const SharedPtr& p) {
		if (this != p) {
			release();
			ptr = p.ptr;
			ref_count = p.ref_count;
			if (ref_count != nullptr)
				(*ref_count)++;
		}
		return *this;
	}

	// destructor calls relase
	~SharedPtr() {release();}

	// dereference op derefs ptr
	T& operator* () const {
		return *ptr;
	}

	// arrow op just returns ptr, no deref
	T* operator-> () const {
		return ptr;
	}

	// getter for count
	unsigned long count() {
		return (ref_count == nullptr) ? 0 : *ref_count;
	}

	// public release
	void pubRelease() {release();}

};

int main() {
	int* a = new int(10);
	SharedPtr<int> p1(a);
	cout << "*p1: " << *p1 << " | p1.count(): " << p1.count() << endl;
	SharedPtr<int> p2(p1);
	cout << "*p2: " << *p2 << " | p2.count(): " << p2.count() << endl;
	p1.pubRelease();
	cout << "*p2: " << *p2 << " | p2.count(): " << p2.count() << endl;
	return 0;
}