#ifndef FILEREADER_H
#define FILEREADER_H
#include <string>
#include "Graphicobject.h"

class FileReader
{
public:
  FileReader();
  Graphicobject readFile(std::string path);
  ~FileReader();
  std::string path;

};
#endif
