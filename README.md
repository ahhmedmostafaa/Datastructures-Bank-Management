# Bank Management System — From UML Design to Linked List Implementation

A complete software development cycle for a bank management system: full **UML system analysis & design**, followed by **two independent C++ implementations** using singly linked lists, built to compare architectural approaches to the same problem.

## Project Structure

```
design/                      # System analysis & design (UML)
oop-version/                 # Implementation 1 — object-oriented
function-based-version/      # Implementation 2 — procedural
```

## 1. System Design (`design/`)
Full UML modeling of the system before implementation:
- Class Diagram
- Use Case Diagram
- Activity Diagrams (x2)
- Sequence Diagrams (x4)
- Data Flow Diagram (DFD)
- Full design documentation (`Bank management system.pdf`)

## 2. Implementation — Two Versions, One Data Structure

| | `oop-version/` | `function-based-version/` |
|---|---|---|
| **Design** | Object-oriented (`BankManagement` class encapsulating linked lists) | Procedural (free functions operating on a shared `Node*` list) |
| **User roles** | Single-level menu | Role-based: Employee / Manager login |
| **Operations** | Add & display branches and account holders | Add, **search**, **remove**, **update**, and display branches and account holders |

Both implementations manage two linked lists — **Branches** and **Account Holders** — using dynamic node allocation (`new`) and manual pointer traversal, without relying on the STL (`std::list`).

### Core Data Structure Operations Demonstrated
- Insertion at head (O(1))
- Linear traversal for display (O(n))
- Linear search by ID/name (O(n))
- Node removal with pointer relinking (O(n))

## Tech Stack
- C++
- Visual Studio project files (.sln / .vcxproj)
- UML modeling

## How to Run
Each version is a self-contained Visual Studio project:
```bash
# Open either .sln file in Visual Studio and run (F5), or compile directly:
g++ oop-version/"datastructure project 1.cpp" -o bank_oop
g++ function-based-version/"datastructure project.cpp" -o bank_functional
```
