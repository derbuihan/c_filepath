#include <stdio.h>

#include "filepath.h"

void printFilePathNode(struct FilePathNode *node) {
  while (node != NULL) {
    printf("name: %s\n", node->name);
    node = node->next;
  }
}

int main() {
  char *test_filepath = "/home/user/file.txt";
  struct FilePathNode *filePathNode = parseFilePath(test_filepath);

  printf("test_filepath: %s\n", test_filepath);
  printFilePathNode(filePathNode);

  freeFilePathNode(filePathNode);

  return 0;
}
