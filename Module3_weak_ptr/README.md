# Module - 3 : Usage of weak_ptr<>

### 3.1 unique_ptr<> : *Syntax*

*The weak_ptr<> syntax is similar to shared_ptr<> and is consists of*

1. weak_ptr  ***name of the smart pointer***
2. < > ***Angle brackets which can have built in or user defined type***
3. var ***A variable name representing the weak_ptr***

*All other syntactically valid syntax rules of shared_ptr<> will be applicable to weak_ptr<> with one exception*

* weak_ptr<> can't be instantiated

### 3.2 weak_ptr : *Why weak_ptr<> is weak?*

*Unlike shared_ptr<> & unique_ptr<>, weak_ptr<> doesn't take the ownership of the memory contained by it.*

*Here is the example of usage with class Sample*

```
class Sample {
public:
	Sample() { cout << "Cons.." << endl; }
	~Sample() { cout << "Dest.." << endl; }
};

int main() {
	shared_ptr<Sample> sp = make_shared<Sample>();
	cout << sp.use_count() << endl; // Prints 1
	weak_ptr<Sample> wp = sp;
	cout << sp.use_count() << endl; // Still Prints 1
	return 0;
}

```
*In this example above, we can see that the Object reference count in shared_pointer doesn't incremented*

### 3.3 Difference with shared_ptr<> : *Where it can be used?*

*weak_ptr<> doesn't take the Ownership, so it shall be used only in the places where one doesn't need to worry about maintaining the Ownership.*

*For example, in the code below, the weak_ptr<> will be invalid once the code comes out of the function*

```
class Sample {
public:
	Sample() { cout << "Cons.." << endl; }
	~Sample() { cout << "Dest.." << endl; }
};

weak_ptr<Sample> func() {
	shared_ptr<Sample> Sp = make_shared<Sample>();
	return Sp;
}

int main() {
	weak_ptr<Sample> Wp = func();
	cout << "End of Main" << endl;
	return 0;
}

```

*In the example above, "Wp" will be invalid in main() as it doesn't take the ownership and was destroyed by shared_ptr<> before coming out of the func() scope*
