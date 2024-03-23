#ifndef C_FILEPATH_FILEPATH_H
#define C_FILEPATH_FILEPATH_H

struct FilePathNode {
  char *name;
  struct FilePathNode *next;
};

struct FilePathNode *parseFilePath(char *tok);
void freeFilePathNode(struct FilePathNode *node);

#endif  // C_FILEPATH_FILEPATH_H
