# Module - 1 : Usage of shared_ptr<>

### 1.1 shared_ptr<> : *Syntax*

*The shared_ptr is called as*

1. shared_ptr  ***name of the smart pointer***
2. < > ***Angle brackets which can have built in or user defined type***
3. var ***A variable name representing the shared_ptr***

*Here is the syntactically valid declaration of shared_ptr*
```
// For built in types
shared_ptr<int> sp;
shared_ptr<char> sp1;
shared_ptr<float> sp2;

// For user defined types
shared_ptr<uType1> sp;
shared_ptr<uTYpe2> sp1;
shared_ptr<uTYpe3> sp2;

```
### 1.2 shared_ptr : *No need to clear memory explicitly*

*The main advantage of shared pointers is that, we should not worry about calling delete or cleaning the memory in an explicit manner. The shared pointer will take care of it once it goes out of scope*

*here is the example of using the shared pointer with built in type* **int**

*Don't forget to use a header file directive* **#include < memory >** *and using std namespace for using smart pointers*

```
shared_ptr<int> sp (new int);
*sp = 100;  // Using the shared_ptr
cout << *sp << endl;

```
*We don't need to free / delete the sp (new int), it will be done automatically when sp goes out of scope.*

*here is another example of using shared_ptr for user defined types i.e* **class / struct**

```
class Sample {
public:
	Sample() { cout << "Sample Constructor" << endl; }
	~Sample() { cout << "Sample Destructor" << endl; }
	void publicFn() { cout << "This is public function of class" << endl; }
};
int main() {
	shared_ptr<Sample> sp(new Sample{});
	sp->publicFn();
	return 0;
}

```
*In this example above, we can see the Destructor is getting called as a result of releasing memory*

### 1.3 shared_ptr : *Ownership and Reference Counts*

*The shared_ptr manages the lifetime of an object based on the Reference counts mechanism.*

*Which means that multiple shared_ptr can refer to one object. The object in question will NOT be destroyed till any one shared_ptr refers to it*

*This is akin to Java Garbage Collector which deallocated memory if and only if there is no reference to it.*

*The example below will demonstrate how this reference count works*

```
class Sample {
public:
	Sample() { cout << "Sample Constructor" << endl; }
	~Sample() { cout << "Sample Destructor" << endl; }
};

shared_ptr<Sample> Func() {
	cout << "Enter Function" << endl;
	shared_ptr<Sample> sp(new Sample{});
	cout << "Exit Function" << endl;
	return sp;
}

int main() {
	cout << "Enter Main" << endl;
	shared_ptr<Sample> retSp = Func();
	cout << "Exit Main" << endl;
	return 0;
}

```
*In this example, the shared_ptr is created inside function* **Func()** *and returned. Even though the shared_ptr sp goes out of scope, the object Sample is not deleted as a reference is taken by retSp. Hence the order of execution will look like*

* 1 - Enter Main
* 2 - Enter Function
* 3 - Sample Constructor
* 4 - Exit Function
* 5 - Exit Main
* 6 - Sample Destructor

*However, the behavior changes if we don't copy a shared_ptr even if we return it from a function. Look at the code below*

```
shared_ptr<Sample> Func() {
	cout << "Enter Function" << endl;
	shared_ptr<Sample> sp(new Sample{});
	cout << "Exit Function" << endl;
	return sp;
}

int main() {
	cout << "Enter Main" << endl;
	Func();
	cout << "Exit Main" << endl;
	return 0;
}
```
*In this example, the object Sample will be destroyed in the Func() itself as the ownership is not taken by another shared_ptr. The out will be*

* 1 - Enter Main
* 2 - Enter Function
* 3 - Sample Constructor
* 4 - Sample Destructor
* 5 - Exit Function
* 6 - Exit Main

*Here the shared_ptr<> will destroy the Sample Object as ownership was not taken by the calling **func()** *even if its returned from the function*

### 1.4 shared_ptr : *Usage of make_shared<>()*

*Till now we're using* **new** *to allocate the memory for the objects contained in shared_ptr<>. The standard library has a built in function for it and called as make_shared<>. Here is how we can use it.*

```
class Sample {
public:
	Sample() { cout << "Constructor make_shared" << endl; }
	~Sample() { cout << "Destructor make_shared" << endl; }
};
int main() {
	shared_ptr<Sample> sp = make_shared<Sample>();
	return 0;
}

```
*The make_shared<> call is not only a clean way to initializing shared_ptr<>, but also fast in memory allocation as compared to new. That's why it's recommended to use make_shared<> instead of new*

## 1.5 : Using shared_ptr<> for Arrays

_The usage of shared_ptr with arrays is slightly complicated as we need to explicitly tell the shared_ptr to call array deleter instead of normal deleted. if we miss to do that then it will result in a memory leak._

_For example a shared_ptr with arrays can be created as_

```
shared_ptr<int> sp(new int[10]);

```
_This will create 10 integers, but will deleter only 1 which will result in memory leaks despite of using shared_ptr_ 

_The code should instead be written as_ 

```
shared_ptr<int> sp(new int[10], default_delete<int[]>());

```
_The default_delete will make sure that_ `delete[]` _is called to clean up the memory occupied by the array_.

***NOTE: Array can't be created using make_shared as there is no way to provide default delete with make_shared
