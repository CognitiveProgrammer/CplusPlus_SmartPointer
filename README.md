# C++14 Smart Pointers : The trilogy which must be used day in and day out

*Prior to arrival of smart pointers as part of boost library, C++ was notorious for memory leaks and errors related to memory handling. In fact, it was very difficult to track memory usage and ownerships in relatively big programs*

*C++11 and C++14 has taken a great leap forward with regard to memory management and have standardize the smart pointers for the same. This can potentially reduce if not altogether remove the problems associated with memory management in C++*

*There are multiple sets of smart pointers which are extremely useful, however, as a normal programmer we'll end up using at most 3 of them. These 3 smart pointers are called as a trilogy and is known as*

* shared_ptr<>
* unique_ptr<>
* weak_ptr<>

*They are pretty much sufficient to handle most of the programming needs related to dynamically allocated memory.*

*The modules below (1,2,&3) are dedicated to respective pointers. Please do not escape the sequence as module 2 refers to module 1 and module 3 refers to module 1 & 2.*

[Module - 1 : Usage of shared_ptr<>](https://github.com/9lean/CplusPlus_SmartPointer/tree/master/Module1_shared_ptr)

*This module will describe the properties of shared_ptr<> as well as how the use this smart pointer in C++ programs*

[Module - 2 : Usage of unique_ptr<>](https://github.com/9lean/CplusPlus_SmartPointer/tree/master/Module2_unique_ptr)

*This module will describe the properties of unique_ptr<> as well as how the use this smart pointer in C++ programs*

*This program will use examples of module 1 to properly demonstrate the difference between these two pointers.*

[Module - 3 : Using of weak_ptr<>](https://github.com/9lean/CplusPlus_SmartPointer/tree/master/Module3_weak_ptr)

*This module will describe the properties of weak_ptr<> as well as how the use this smart pointer in C++ programs*

*The weak_ptr<> is generally used with shared_ptr<> and this module will use both of them drastically*

[Module - 4 : The std::move semantics](https://github.com/9lean/CplusPlus_SmartPointer/tree/master/Module4_move_semantics)

*This module will describe the move semantics and how std::move can be used with shared_ptr<> and unique_ptr<>.*

*This will also touch upon when and how to use std::move()*
