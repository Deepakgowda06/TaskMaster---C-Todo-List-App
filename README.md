# Todo List App
TaskMaster is a simple and efficient Todo List application built in C++ that helps users manage their daily tasks. The app offers essential features like adding, showing, updating, deleting, and searching for tasks, providing an intuitive command-line interface for easy task management. Whether you want to keep track of your personal to-dos or manage a small project, TaskMaster ensures that you can stay organized and focused. The application is lightweight and serves as a great foundation for further enhancements like task prioritization and persistence through file storage.


This is a simple Todo List application written in C++. It allows users to manage their tasks through basic CRUD (Create, Read, Update, Delete) operations. The app also includes a search feature to find specific tasks by their titles.

## Features

- **Add Task**: Add a new task with a title and description.
- **Show Tasks**: Display all tasks with their details.
- **Update Task**: Modify the title or description of an existing task.
- **Delete Task**: Remove a task from the list.
- **Search Task**: Find a task by its title.

## Getting Started

### Prerequisites

To run this program, you need:
- A C++ compiler (e.g., `g++`, `clang`).
- A terminal or an IDE that supports C++.

### Installation

1. Clone this repository:
    ```bash
    git clone https://github.com/Deepakgowda06/todo-list-cpp.git
    ```

2. Navigate to the project directory:
    ```bash
    cd todolist-cpp
    ```

3. Compile the C++ source file:
    ```bash
    g++ -o todo todolist.cpp
    ```

4. Run the compiled program:
    ```bash
    ./todolist
    ```

### Usage

1. After running the program, you'll be prompted with a menu that allows you to choose between different actions:  
   - Add a new task
   - Show all tasks
   - Update an existing task
   - Delete a task
   - Search for a task by title
   - Exit the program

2. Select an action by entering the corresponding number.

### Example

- **Adding a Task**:
    ```
    Enter task title: Buy groceries
    Task added successfully!
    ```

- **Showing Tasks**:
    ```
    Task List:
    1.  Buy groceries 
    ```

- **Updating a Task**:
    ```
    Enter task number to update: 1
    Enter new title: Buy groceries and fruits
    Task updated successfully!
    ```

- **Deleting a Task**:
    ```
    Enter task number to delete: 1
    Task deleted successfully!
    ```

- **Searching for a Task**:
    ```
    Enter title to search: Buy groceries
    Found task:
    [ ] Buy groceries 
    ```

### Code Structure

- `todolist.cpp`: Main file containing all the logic for task management (add, update, delete, show, and search).

### Improvements

Future versions could include:
- Task prioritization (e.g., high, medium, low priority).
- Deadlines and reminders.
- Saving tasks to a file for persistent storage.

### Contributing

Feel free to submit issues or pull requests if you want to improve this project!

### License

This project is licensed under the MIT License .
