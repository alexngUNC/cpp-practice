#include <iostream>
using namespace std;
template <typename T>
class StackSharedPtr {
private:
	// set to nullptr if ref_count reaches 0
	unsigned long* ref_count;
	T** adr;
public:
	// constructor
	StackSharedPtr(T* p = nullptr) {
		if (p != nullptr) {
			adr = new T*(p);
			ref_count = new unsigned long(1);
		}
	}

	// copy constructor
	StackSharedPtr(StackSharedPtr& p) {
		adr = p.adr;
		ref_count = p.ref_count;
		if (ref_count != nullptr) {
			(*ref_count)++;
		}
	}

	// overload dereference op
	T operator* () {
		return **adr;
	}

	// getter for ref count
	unsigned long count() {
		return *ref_count;
	}

	// getter for adr value
	T* value() {
		return *adr;
	}

	// let go of address
	void release() {
		if (ref_count != nullptr) {
			(*ref_count)--;
			if ((*ref_count) == 0) {
				cout << "no more references" << endl;
				*adr = nullptr;
			}
		}
	}
	
};

int main() {
	int a = 10;
	StackSharedPtr<int> p(&a);
	cout << "&a: " << &a << endl;
	cout << "p.value(): " << p.value() << " | p.count(): " << p.count() << endl; 

	StackSharedPtr<int> p2(p);
	cout << "p2.value(): " << p2.value() << " | p2.count(): " << p2.count() << endl; 
	cout << "p.value(): " << p.value() << " | p.count(): " << p.count() << endl;
	cout<<"\n";
	p2.release();
	cout << "p2.value(): " << p2.value() << " | p2.count(): " << p2.count() << endl; 
	cout << "p.value(): " << p.value() << " | p.count(): " << p.count() << endl;
	cout<<endl;
	p.release();
	cout << "p2.value(): " << p2.value() << " | p2.count(): " << p2.count() << endl; 
	cout << "p.value(): " << p.value() << " | p.count(): " << p.count() << endl;
	return 0;
}