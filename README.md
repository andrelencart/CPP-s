# CPP's

## About
The goal of these modules is to introduce you to Object‑Oriented Programming. This will be the starting point of your C++ journey. Many languages are recommended for learning OOP, but we chose C++ s[...] 

We acknowledge that modern C++ differs significantly in many aspects. If you want to become a proficient C++ developer, it will be up to you to explore further beyond the 42 Common Core!

This repository collects small, focused C++ examples (**CPP_00 .. CPP_09**) meant for learning by doing: compile, run, and modify each example to practice core OOP and C++ fundamentals.

## Modules
- [CPP_00](#cpp_00)
- [CPP_01](#cpp_01)
- [CPP_02](#cpp_02)
- [CPP_03](#cpp_03)
- [CPP_04](#cpp_04)
- [CPP_05](#cpp_05)
- [CPP_06](#cpp_06)
- [CPP_07](#cpp_07)
- [CPP_08](#cpp_08)
- [CPP_09](#cpp_09)

## Concepts by module

### CPP_00
C++ basics and first steps into OOP:
- Basic build workflow (Makefile, compile flags, warnings).
- Standard I/O (`std::cout`, `std::cin`, `std::cerr`) and simple formatting.
- Command‑line arguments and basic string handling.
- First classes: constructors, methods, encapsulation.
- Static members (data shared across instances).

### CPP_01
Memory, references, and slightly bigger class interactions:
- Stack vs heap, `new` / `delete`, and object lifetime.
- Pointers vs references (when to use which).
- Constructor initialization lists and composition.
- File I/O (`std::ifstream` / `std::ofstream`) + simple text replacement.
- Simple “dispatch” patterns (input string → method called).

### CPP_02
Value types and operator overloading:
- Operator overloading (arithmetic, comparison, stream output).
- Orthodox Canonical Form / rule of three (copy/assign/destruct).
- Building a small numeric/value type (fixed-point style design).
- Conversions and precision basics.

### CPP_03
Inheritance fundamentals:
- Base vs derived classes (reuse and extension).
- Constructor/destructor order in class hierarchies.
- Overriding vs hiding methods.
- Access specifiers (`public` / `protected` / `private`) in inheritance.
- Common pitfalls (like slicing).

### CPP_04
Polymorphism and interfaces:
- Virtual functions and dynamic dispatch.
- Abstract classes and pure virtual methods.
- Virtual destructors (safe deletion through base pointers).
- Using base pointers/references to work with derived objects.

### CPP_05
Exceptions and error handling:
- `try` / `catch` / `throw` basics.
- Using / creating exception types (often based on `std::exception`).
- Catching correctly (by reference; specific before generic).
- Keeping class invariants: exception-safety basics.

### CPP_06
Casts, conversions, and RTTI:
- Scalar conversions (`char`, `int`, `float`, `double`) + edge cases.
- Pointer serialization (`uintptr_t`) and deserialization.
- RTTI (`dynamic_cast`, `typeid`) and runtime type identification.

### CPP_07
Templates and generic programming:
- Function templates (write code that works for many types).
- Class templates (generic data structures / types).
- Template limitations and common patterns in C++98.

### CPP_08
STL containers and algorithms:
- Core containers (e.g. `std::vector`, `std::list`, `std::deque`).
- Iterators and iterator validity.
- Using `<algorithm>` helpers (searching, counting, transforming).

### CPP_09
Putting STL and parsing together:
- Parsing + validation (robust input handling).
- Associative containers (e.g. `std::map`, `std::set`) when order/lookup matters.
- Complexity/performance basics (avoid unnecessary copies, pick the right structure).

## Folder Structure
```
CPP-s/
  README.md
  CPP_00/
    ex00/
      Src/
        *.cpp
      Makefile
      *.hpp
    ex01/
    ...
  CPP_01/
    ex00/
    ...
  CPP_02/
```

## Build & run (example)
Each exercise provides its own Makefile. To build and run an exercise:

1. Change to the module folder (**CPP_00 .. CPP_09**):
```bash
cd CPP_02
```

2. Change to the specific exercise inside that module (example folder name used below):
```bash
cd ex00
```

3. Run make to build the exercise:
```bash
make
```

4. Run the produced executable (name depends on the exercise Makefile):
```bash
./ex00      # or whatever executable the Makefile generates
```

Cleaning:
```bash
make clean
# or
make fclean
```
