# Chapter05_ToDoList

A to-do list application written in C++.

## 📋 Overview

This is a to-do list management application developed in C++ as part of Chapter 5 learning exercises. The project demonstrates task management, persistent data storage, and user interface design concepts through a practical to-do list system.

## 🛠️ Technology Stack

- **Language**: C++
- **Build System**: CMake (recommended)

## 🚀 Getting Started

### Prerequisites

- C++ compiler (C++11 or later)
- CMake 3.10 or higher (optional, but recommended)

### Building the Project

#### Using CMake (Recommended)

```bash
# Clone the repository
git clone https://github.com/liewvk/Chapter05_ToDoList.git
cd Chapter05_ToDoList

# Create a build directory
mkdir build
cd build

# Generate build files and compile
cmake ..
make
```

#### Using Direct Compilation

```bash
# Navigate to the project directory
cd Chapter05_ToDoList

# Compile all source files
g++ -std=c++11 -o ToDoList src/*.cpp
```

### Running the Application

```bash
./ToDoList
```

## 📁 Project Structure

The project is organized as follows:

```
Chapter05_ToDoList/
├── CMakeLists.txt          # CMake configuration file
├── src/                    # Source implementation files (.cpp)
├── include/                # Header files (.h)
├── data/                   # Data files (if applicable)
└── README.md               # This file
```

## ✨ Features

- **Task Management**: Create, view, and manage to-do items
- **Task Completion**: Mark tasks as complete or incomplete
- **Priority Levels**: Assign priority levels to tasks
- **Data Persistence**: Save and load tasks from files
- **Search and Filter**: Find tasks by various criteria
- **Due Dates**: Track task deadlines
- **Task Categories**: Organize tasks by categories

## 📝 Usage

### Basic Operations

The application supports the following operations:

1. **Add Task**: Create a new to-do item
2. **View Tasks**: Display all or filtered tasks
3. **Complete Task**: Mark a task as done
4. **Update Task**: Modify task details (title, priority, due date, etc.)
5. **Delete Task**: Remove a task from the list
6. **Search**: Find tasks by keywords or category
7. **Save/Load**: Persist tasks to and from files

## 📚 Key Concepts Demonstrated

- Classes and Objects
- File I/O Operations
- Dynamic Memory Management
- Data Structures (Vectors, Lists)
- String Manipulation
- Input Validation
- Task Scheduling

## 🎯 Learning Objectives

By working through this project, you will learn:

- How to design and implement a task management system
- Techniques for persistent data storage
- User input handling and validation
- Time and date management in C++
- File operations for saving/loading application state

## 📝 License

This project is currently unlicensed. Please refer to the repository for any licensing information.

## 👤 Author

[liewvk](https://github.com/liewvk)

## 🤝 Contributing

Contributions are welcome! Feel free to fork this repository and submit pull requests with improvements or additional features.

---

**Last Updated**: July 6, 2026
