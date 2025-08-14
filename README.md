# 📄 Get Next Line

> Implementation of a function that reads a file **line by line** using a file descriptor.  
> This project helps improve your understanding of **static variables**, **file I/O**, **buffer management**, and **memory allocation**.

---

## 📌 Project Overview

`get_next_line()` allows you to read a text file (or standard input) one line at a time.  
Repeated calls to the function return the next line until the end of the file is reached.  

The function:
- Works with both files and standard input (`stdin`).
- Returns lines **including the newline character** (`\n`) except at EOF when no newline exists.
- Uses **at most one static variable** in the mandatory part.
- Must be **memory-leak free**.

---

## 🖋 Function Prototype

```c
char *get_next_line(int fd);
```
---

## 📜 Mandatory Part

- One static variable is allowed.
- Handles **only one** file descriptor at a time.
- Keeps reading until a newline or EOF is reached.
- Uses `read()` and manual buffer handling.

---

### 📥 Parameters

| Parameter | Description |
|-----------|-------------|
| `fd`      |  File descriptor to read from (e.g., from `open()` or `STDIN_FILENO`). |

### 📤 Return Value

| Return Value | Description |
|--------------|-------------|
| `char *`     | The line read from the file descriptor, including the terminating `\n` if found. |
| `NULL`       | Returned if there is nothing left to read (EOF) or if an error occurs. |

---

### ⚙️ How It Works

- **Read from** `fd` **into a buffer** of size `BUFFER_SIZE`.
- **Store** leftover data in a static variable between calls.
- **Find** the newline (`\n`) position.
- **Return the line** (including `\n` if present).
- **Keep the remainder** in the static variable for the next call.
- **Repeat until** EOF or error.

---

## 🚀 Bonus Part

- Still uses **only one static variable**.
- Can handle **multiple file descriptors** simultaneously.
- Each file descriptor’s state is preserved between calls.
- Example: You can switch between `fd1`, `fd2`, and `fd3` without mixing lines.

---
