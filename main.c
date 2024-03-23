#include <stdio.h>

#include "filepath.h"

int main() {
  struct FilePathNode *path = parseFilePath("/home/user/file.txt");
  struct FilePathNode *cur = path;
  while (cur != NULL) {
    printf("%s\n", cur->name);
    cur = cur->next;
  }
  freeFilePathNode(path);

  return 0;
}
