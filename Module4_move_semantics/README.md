# Module - 4 : Usage of std::move with Smart pointers

### 4.1 *Usage*

*As demonstrated in the example of unique_ptr<>, the move is used to transfer the ownership and can be used by both unique_ptr<> as well as by shared_ptr<>*

### 4.2 std::move : *usage with unique_ptr<>*

*In unique_ptr<>, move is used to transfer the ownership from one unique_ptr<> to another, which is otherwise not possible*

```
int main() {
	unique_ptr<int> up (new int);
	// transfer the ownership
	unique_ptr<int> up2 = move(up);
	// After this like, up doesn't holds the ownership of the
	// object create by new int
	return 0;
}

```

### 4.3 std::move : *usage with unique_ptr<>*

*shared_ptr<>, as the name suggests, multiple pointers can share the ownership with the help of reference counts*.

*However, std::move behaves in the similar way as with unique_ptr<>. It will transfer the ownership (and not increment the reference count) of the shared_ptr*

```
int main() {
	shared_ptr<int> sp (new int);
	cout<<sp.use_count()<<endl; // prints 1
	// transfer the ownership
	shared_ptr<int> sp2 = move(sp);
	// After this like, up doesn't holds the ownership of the
	// object create by new int
	cout<<sp.use_count()<<endl; // prints 0
	cout<<sp2.use_count()<<endl; // prints 1
	return 0;
}

```
