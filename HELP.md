# Line Editor Help

## Starting the editor

Compile the program with GCC:

```bash
gcc line_editor.c -o line_editor
```

Run:

```bash
./line_editor
```

On Windows PowerShell:

```powershell
.\line_editor.exe
```

## Commands

### Insert

```text
i <line> <text>
```

Inserts the supplied text at the specified line number.

Example:

```text
i 1 Hello World
```

### Delete

```text
d <line>
```

Deletes the specified line.

Example:

```text
d 1
```

### Print

```text
p
```

Displays all current lines with their line numbers.

### Help

```text
h
```

Displays the available commands.

### Quit

```text
q
```

Exits the editor.

## Notes

- Line numbers start at 1.
- A new line can be inserted from line 1 through the next available line.
- Deleting a line shifts the remaining lines upward.
- Invalid commands and line numbers produce an error message instead of terminating the program.
