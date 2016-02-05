#include "Graphicobject.h"
#include <string>

class FileReader
{
public:
  FileReader(string path);
  Graphicobject readFile();
  ~FileReader();

};