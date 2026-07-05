# Bank Management System — Linked List Implementation (C++)

A bank management system implemented as a **singly linked list** data structure, built in two different architectural styles to compare design approaches for the same problem.

## Two Versions, One Data Structure

| | `oop-version/` | `function-based-version/` |
|---|---|---|
| **Design** | Object-oriented (`BankManagement` class encapsulating linked lists) | Procedural (free functions operating on a shared `Node*` list) |
| **User roles** | Single-level menu | Role-based: Employee / Manager login |
| **Operations** | Add & display branches and account holders | Add, **search**, **remove**, **update**, and display branches and account holders |

Both implementations manage two linked lists — **Branches** and **Account Holders** — using dynamic node allocation (`new`) and manual pointer traversal, without relying on the STL (`std::list`).

## Core Data Structure Operations Demonstrated
- Insertion at head (O(1))
- Linear traversal for display (O(n))
- Linear search by ID/name (O(n))
- Node removal with pointer relinking (O(n))

## Tech Stack
- C++
- Visual Studio project files (.sln / .vcxproj)

## How to Run
Each version is a self-contained Visual Studio project:
```bash
# Open either .sln file in Visual Studio and run (F5), or compile directly:
g++ oop-version/"datastructure project 1.cpp" -o bank_oop
g++ function-based-version/"datastructure project.cpp" -o bank_functional
```
