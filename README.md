# Zoo Management System - C++ OOP Example

A comprehensive Object-Oriented Programming demonstration in C++ featuring inheritance, polymorphism, abstract classes, and smart pointers.

## OOP Concepts Demonstrated

### 1. Inheritance
- Base class: `Animal`
- Derived classes: `Lion`, `Elephant`, `Bird`
- Code reuse through class hierarchy

### 2. Polymorphism
- Virtual functions: `makeSound()`, `eat()`
- Override keyword in derived classes
- Animal pointers displaying different behaviors

### 3. Abstract Classes
- `Animal` is an abstract class with pure virtual function `eat()`
- Cannot instantiate Animal directly

### 4. Encapsulation
- Private data members with public interfaces
- Getters for controlled access

### 5. Smart Pointers
- `std::unique_ptr` for automatic memory management
- No manual `delete` calls, no memory leaks

## Code Highlights

### Virtual Function (Polymorphism)
```cpp
virtual void makeSound() const override {
    std::cout << name << " roars loudly! ROAR!\n";
}
```

### Abstract Class Definition
```cpp
virtual void eat() const = 0;  // Pure virtual function
```
### Smart Pointer Usage
```cpp
std::vector<std::unique_ptr<Animal>> zoo;
zoo.push_back(std::make_unique<Lion>("Simba", 5, 30));
```

### Example Output
```cpp
Simba roars loudly! ROAR!
Dumbo trumpets! TOOT TOOT!
Tweety chirps! Chirp chirp!

Simba eats meat (carnivore).
Dumbo eats plants (herbivore).

Simba is hunting with 30cm mane!
Dumbo sprays water with its trunk!
Tweety flies with 15cm wingspan!
```

### What I Learned
- How to design class hierarchies
- When to use virtual functions vs regular functions
- The power of polymorphism in software design
- Modern C++ memory management techniques
- Difference between abstract and concrete classes

### Compilation
```cpp
g++ -std=c++17 ZooSystem.cpp -o ZooSystem
```

### Real-World Applications
- Game development (NPC behavior systems)
- Simulation software
- Enterprise systems with complex hierarchies
- Any system requiring flexible, extensible object models
