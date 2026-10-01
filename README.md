# C Line Editor

A simple command-line line editor written in C. The editor works with one line at a time and provides commands to insert, delete, display, and manage text in memory.

## Features

- Insert a line at a selected line number
- Delete a selected line
- Print the complete document with line numbers
- Interactive command-line interface
- Help command
- Validation for invalid line numbers and unknown commands
- Handles an empty document without crashing

## Components

### 1. Document
The `Document` structure stores the text lines in a fixed-size two-dimensional character array and keeps track of the current number of lines.

### 2. Command loop
The `main()` function repeatedly reads a command from the user, identifies the command, validates its input, and calls the appropriate operation.

### 3. Insert operation
`insert_line()` validates the requested line number, shifts existing lines downward, and places the new text at the requested position.

### 4. Delete operation
`delete_line()` validates the line number, shifts later lines upward, and decreases the document line count.

### 5. Display operation
`print_document()` prints every stored line together with its line number.

### 6. Help operation
`show_help()` displays the supported commands and their usage.

## Command Flow

```text
User input
    ↓
Command parser
    ↓
Validate command and line number
    ↓
Call insert / delete / print / help
    ↓
Update or display document
    ↓
Return to command prompt
```

## Supported Commands

| Command | Description | Example |
|---|---|---|
| `i <line> <text>` | Insert text at a line number | `i 1 Hello` |
| `d <line>` | Delete a line | `d 1` |
| `p` | Print the document | `p` |
| `h` | Show help | `h` |
| `q` | Quit the editor | `q` |

## Compile and Run

### GCC

```bash
gcc line_editor.c -o line_editor
```

Run it with:

```bash
./line_editor
```

On Windows PowerShell, you can run:

```powershell
.\line_editor.exe
```

## Example

```text
=== C Line Editor ===
Type 'h' for help.
editor> i 1 Hello World
Line inserted.
editor> i 2 Welcome to C
Line inserted.
editor> p
1: Hello World
2: Welcome to C
editor> d 1
Line deleted.
editor> p
1: Welcome to C
editor> q
Goodbye!
```

## Error Handling

The editor checks for invalid line numbers, a full document, malformed insert/delete commands, and unknown commands. Instead of terminating unexpectedly, it prints an error or usage message and returns to the command prompt.

## Project Structure

```text
line-editor/
├── line_editor.c
├── README.md
└── HELP.md
```

## Author

Prashanti
