# CPP-s

## About
The goal of these modules is to introduce you to Object‑Oriented Programming. This will be the starting point of your C++ journey. Many languages are recommended for learning OOP, but we chose C++ since it is derived from your old friend, C. As C++ is a complex language, the exercises adhere to the C++98 standard to keep things simple.

We acknowledge that modern C++ differs significantly in many aspects. If you want to become a proficient C++ developer, it will be up to you to explore further beyond the 42 Common Core!

This repository collects small, focused C++ examples (CPP_00 .. CPP_05) meant for learning by doing: compile, run, and modify each example to practice core OOP and C++ fundamentals.

## Files
### CPP_00
Introductory C++ module establishing the foundations you need before deeper OOP:
- Environment & workflow: using a simple Makefile, separating headers (`.hpp`) from implementation (`.cpp`), compiling with C++98 flags and warnings enabled.
- Basic standard I/O: `std::cout`, `std::cin`, `std::cerr`, simple formatting and string manipulation.
- Command‑line argument handling: reading and transforming arguments to practice program entry and data flow.
- First classes: defining minimal classes with private data and public methods; understanding constructors and the need for proper encapsulation.
- Static members & basic bookkeeping: introducing the idea of data shared across all instances.
- Style & discipline: consistent naming, header include guards, minimal dependencies, and clean, deterministic output.

### CPP_01
Builds on the foundations of CPP_00 by introducing manual memory management and deeper class interaction:
- Dynamic allocation & lifetime: `new` / `delete`, creating objects on heap vs stack, managing arrays of objects.
- Pointers vs references: semantic differences (rebindability, nullability), passing and returning by reference, avoiding unnecessary copies.
- Initialization & class relationships: constructor initialization lists, member composition, objects that reference external resources (e.g. a `Weapon` held by a `Human` class).
- Basic resource safety discipline under C++98 (no smart pointers yet): clear ownership rules and avoiding leaks.
- File I/O & simple text processing: using `std::ifstream`, `std::ofstream`, and performing straightforward string find/replace operations.
- Simple behavior dispatch: mapping input strings (e.g. log/complaint levels) to member function calls (arrays of function pointers or conditional chains).
- Encapsulation & clarity: separating interface (`.hpp`) from implementation, minimizing unnecessary `#include`s, and keeping class responsibilities focused.

### CPP_02
Value Types, Canonical Form & Operator Overloading:
- Operator overloading: giving user‑defined types natural arithmetic / comparison / stream behaviors.
- Orthodox Canonical Form (OCF): proper implementation of default constructor, copy constructor, copy assignment operator, and destructor (rule of three) for resource safety.
- Fixed‑point or custom numeric class design: internal representation vs public interface.
- Encapsulation of invariants: ensuring class state remains valid after operations.
- Method chaining & fluent interfaces where appropriate.
- Precision, conversions, and explicit vs implicit constructors.

### CPP_03
Focuses on inheritance:
- Base vs derived class relationships: reusing and extending behavior.
- Access specifiers (`public`, `protected`, `private`) and their effect on inheritance.
- Constructor and destructor ordering: ensuring proper resource setup/teardown in hierarchies.
- Overriding vs hiding: understanding when a derived method supersedes a base method.
- Using base class functions from derived classes (`Base::func()` calls).
- Avoiding common pitfalls (slicing, unnecessary inheritance, fragile hierarchies).

### CPP_04
Introduces subtype polymorphism and abstract interfaces:
- Virtual functions & dynamic dispatch: invoking derived behavior via base pointers/references.
- Abstract classes & pure virtual methods: defining interfaces that cannot be instantiated.
- Virtual destructors: ensuring proper cleanup through base pointers.
- Polymorphic cloning or factory patterns (creating copies of derived objects via base interface).
- Interface segregation: keeping abstract bases focused and minimal.
- Potential multiple inheritance considerations (and why to be cautious).

### CPP_05
Introduces exceptions and controlled error handling:
- `try` / `catch` / `throw`: basic syntax and flow.
- Designing exception types (custom classes vs using `std::exception` derivatives).
- Granularity of exception handling: catching by reference, specific vs generic handlers.
- Ensuring strong/exception‑safe operations: commit or rollback patterns in modifying functions.
- Distinguishing recoverable vs unrecoverable errors and when to throw.
- Maintaining class invariants when exceptions occur (basic strong / basic guarantee concepts).

## Build & run (example)
Each exercise provides its own Makefile. To build and run an exercise:

1. Change to the module folder (CPP_00 .. CPP_05):
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
make fclean
```


