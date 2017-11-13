# Module - 2 : Usage of unique_ptr<>

### 2.1 unique_ptr<> : *Syntax*

*The unique_ptr<> syntax is similar to shared_ptr<> and is consists of*

1. shared_ptr  ***name of the smart pointer***
2. < > ***Angle brackets which can have built in or user defined type***
3. var ***A variable name representing the shared_ptr***

*All syntactically valid syntax rules of shared_ptr<> will be applicable to unique_ptr<>*

### 2.2 unique_ptr : *No need to clear memory explicitly*

*Like shared_ptr<>, there is no need to call delete or clean the memory in an explicit manner. The unique pointer  will take care of it once it goes out of scope*

*Here is the example of usage with class Sample*

```
class Sample {
public:
	Sample() { cout << "Sample Constuctor" << endl; }
	~Sample() { cout << "Sample Destructor" << endl; }
	void publicFn() { cout << "This is public function of class" << endl; }
};
int main() {
	unique_ptr<Sample> sp(new Sample{});
	sp->publicFn();
	return 0;
}

```
*In this example above, we can see the Destructor is getting called as a result of releasing memory*

### 2.3 Difference with shared_ptr<> : *Ownership cannot be transferred*

*shared_ptr<> maintains reference counts where more than one shared_ptr<> can refer to a single object.*

*This is prevented by unique_ptr<> and the reason behind naming it as unique. In unique_ptr<>, one and only one unique_ptr<> has the Ownership of the Object and manages its lifetime. Look at the code below for an example*

```
int main() {
	unique_ptr<int> up1(new int);
	// This is not allowed and will give compilation error
	unique_ptr<int> up2 = up1;
	return 0;

```

### 2.4 The Move Semantics : Transferring unique_ptr<> Ownership

*Its possible to transfer the ownership using std::move(). However, once std::move() is called then moved pointer will no longer hold the ownership. To understand look at the example code below*

```
int main() {
	unique_ptr<int> up1(new int);
	// After this line, up1 will no longer hold any reference to the
	// memory created. Its lifetime is owned by up2
	unique_ptr<int> up2 = move(up1);
	return 0;
}

```

### 2.5 Ownership of unique_ptr<> : Returning from a Function

*Just like shared_ptr<>, unique_ptr<> can also be returned from a Function. To understand look at the code below which is exactly similar to what we did with shared_ptr<>*

```
class Sample {
public:
	Sample() { cout << "Sample Constuctor" << endl; }
	~Sample() { cout << "Sample Destructor" << endl; }
};

unique_ptr<Sample> Func() {
	cout << "Enter Function" << endl;
	unique_ptr<Sample> up(new Sample{});
	cout << "Exit Function" << endl;
	return up;
}

int main() {
	cout << "Enter Main" << endl;
	unique_ptr<Sample> retup = Func();
	cout << "Exit Main" << endl;
	return 0;
}

```
*The above code compiles successfully and the output is*

* 1 - Enter Main
* 2 - Enter Function
* 3 - Sample Constructor
* 4 - Exit Function
* 5 - Exit Main
* 6 - Sample Destructor

*Which is similar to what we got with shared_ptr<>*

* Why? Isn't transfer of ownership is prohibited in unique_ptr<> ?

*Yes, but as per C++ specification, compilers explicit add std::move() while returning the unique_ptr<> from a function which transfers the ownership*

*The compilers modified code for the Func() will look like*

```
unique_ptr<Sample> Func() {
	unique_ptr<Sample> up(new Sample{});
	return move(up);
}

```
### 2.6 unique_ptr<> : usage of make_unique<>()

*The* ***C++14*** *specification has added the support of make_unique<>(). Its usage is similar to that of make_shared<>() and should be used instead of* **new**

```
class Sample {
public:
	Sample() { cout << "Constructor make_unique" << endl; }
	~Sample() { cout << "Destructor make_unique" << endl; }
};
int main() {
	unique_ptr<Sample> sp = make_unique<Sample>();
	return 0;
}

```
## 2.7 : Using uniqoe_ptr<> for Arrays

_Unlike shared_ptr<>, unique_ptr<> is quite tolerant to the creation of arrays. It can be done simply by writing the following code with make_unique()_ 

```
unique_ptr<A[]> sp = make_unique<A[]>(10);
```

* ***Note : All C++14 compilers supports make_unique<>()***
