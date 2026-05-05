# String Project for C Study ✨

A small C project created for studying and practicing the C language with custom string helper functions built from scratch. 🚀

## 📌 Overview

This repository contains a simple console application that showcases a few string utilities for hands-on C learning, including:

- `my_strlen` 🧮 — calculates the length of a string
- `my_strcpy` 📋 — creates a heap-allocated copy of a string
- `my_strpbrk` 🔎 — finds the first matching character from a set
- `my_strncpy` ✂️ — copies a limited number of characters safely
- `my_strcmp` ⚖️ — compares two strings up to a given count

The demo program in `main.c` prints example results using these helpers.

## 🛠️ Build Requirements

- CMake 4.2 or newer
- A C compiler with C23 support

## ⚙️ Build

```bash
cmake -S . -B build
cmake --build build
```

## ▶️ Run

After building, run the executable:

```bash
./build/proj
```

## 📁 Project Structure

```text
.
├── CMakeLists.txt
├── main.c
└── include/
    ├── my_string.h
    └── my_string.c
```

## 💡 Notes

- The project enables warning flags to help catch potential issues during compilation. 🧪
- This code is educational and meant to support C study and practice. 📘
- `my_strcpy` allocates memory with `malloc`, so remember to free the returned pointer when you use it in your own code. 🧼
- `my_strncpy` always keeps the destination buffer null-terminated when the buffer size is greater than zero. ✅

## 📚 Example

The sample `main.c` demonstrates how to:

- get the length of `"Hello World!"`
- copy strings
- search for a character from a set
- compare two strings

Enjoy exploring the project! 🎉


