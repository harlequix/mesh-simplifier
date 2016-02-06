#include "Graphicobject.h"
#include <string>

class FileReader
{
public:
  FileReader(std::string path);
  Graphicobject readFile();
  ~FileReader();

};
