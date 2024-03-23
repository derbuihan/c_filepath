#include "filepath.h"

#include <stdlib.h>
#include <string.h>

static char *parseName(char **tok) {
  while (**tok == '/') (*tok)++;

  char *start = *tok;
  char *end = *tok;
  while (*end != '/' && *end != '\0') end++;
  *tok = end;

  return strndup(start, end - start);
}

static struct FilePathNode *createFilePathNode(char *name) {
  struct FilePathNode *node = malloc(sizeof(struct FilePathNode));
  node->name = name;
  node->next = NULL;
  return node;
}

struct FilePathNode *parseFilePath(char *filepath) {
  struct FilePathNode head = {};
  struct FilePathNode *cur = &head;

  while (*filepath != '\0') {
    char *name = parseName(&filepath);
    struct FilePathNode *filePathNode = createFilePathNode(name);
    cur = cur->next = filePathNode;
  }

  return head.next;
}

void freeFilePathNode(struct FilePathNode *node) {
  while (node != NULL) {
    struct FilePathNode *next = node->next;
    free(node->name);
    free(node);
    node = next;
  }
}
