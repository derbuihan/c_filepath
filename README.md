# FilePath Parser in C

This repository contains an implementation of a file path parser in the C programming language. The parser takes a
string representing a Unix-style file path and produces a linked list representing the path segments.

## Description

This parser is designed for Unix-like filepaths. Each node in the linked list represents a segment of the path.
For example, given the path `/home/user/file.txt`, the parser will produce a linked list with nodes "home", "user",
"file.txt".

## How to Use

1. Include `filepath.h` in your program.

2. Use `parseFilePath` to parse a file path. This function will return a pointer to the head of the linked list.

3. Use the `name` and `next` members of the struct to access each segment of the path.

4. When done, use `freeFilePathNode` to free the memory allocated for the linked list.

Example:

```c
struct FilePathNode *path = parseFilePath("/home/user/file.txt");
struct FilePathNode *cur = path;
while (cur != NULL) {
    printf("%s\n", cur->name);
    cur = cur->next;
}
freeFilePathNode(path);
```

## Implementation Details

The core logic is implemented in four static functions:

- `parseName`: extracts a segment name from the file path.
- `createFilePathNode`: allocates and initializes a new `FilePathNode`.
- `parseFilePath`: utilizes the previous two functions to parse a file path and produce a linked list.
- `freeFilePathNode`: deallocates the memory of the linked list.
