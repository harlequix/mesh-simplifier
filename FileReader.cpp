#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <sstream>

  FileReader::FileReader(){

  }
  FileReader::~FileReader(){}

  Graphicobject FileReader::readFile(std::string path){
    std::ifstream file_1(path.c_str());
    std::string str;
    Graphicobject* obj=new Graphicobject();
    int vertex_count=0;
    //count number of vertices
    while (std::getline(file_1, str)){
      std::istringstream iss(str);
      std::string s;
      //would be better as substring matching for first char, but copy and paste ftw!
      double a, b, c;
      iss >> s >> a >> b >> c;
      if(s.compare("v")==0){
        vertex_count++;
      }
    }

    //add vertices to array and fill graphicobject with data from file or from already known data
    Vertex* vertices [vertex_count];
    std::ifstream file_2(path.c_str());
    vertex_count=0;
    while(std::getline(file_2, str)){
      std::istringstream iss(str);
      std::string s;
      double a, b, c;
      iss >> s >> a >> b >> c;
      if(s.compare("v")==0){
        Vertex* vertex=new Vertex(a,b,c);
        vertices[vertex_count]=vertex;
        obj->addVertex(vertices[vertex_count]);
        std::cerr << "Added vertex" << std::endl;
        vertex_count++;
        vertex->setid(vertex_count);
      }
      if(s.compare("f")==0){
        //the vertices of the face
        Vertex* vertex_a=(vertices[(int)a-1]);
        Vertex* vertex_b=(vertices[(int)b-1]);
        Vertex* vertex_c=(vertices[(int)c-1]);

        //bool flags that determine whether edge has to be inserted, 0 yes - 1 no
        int insert_ab=0;
        int insert_bc=0;
        int insert_ca=0;
        //pointer to edges of triangle
        Edge* ab=NULL;
        Edge* bc=NULL;
        Edge* ca=NULL;
        //markers - check if vertex is contained in edge, if yes mark it
        int at_a=0;
        int at_b=0;
        int at_c=0;
        //compare all vertices with vertices in already known edges
        for (int i=0; i<obj->edge_list.size(); i++){
          Edge* edge=obj->edge_list[i];
          Vertex* vert_1=(obj->edge_list[i]->vert1);
          Vertex* vert_2=(obj->edge_list[i]->vert2);
          //if the edge points to one of the vertices in the input face mark it
          if(vertex_a==vert_1 || vertex_a==vert_2){
            at_a=1;
          }
          if(vertex_b==vert_1 || vertex_b==vert_2){
            at_b=1;
          }
          if(vertex_c==vert_1 || vertex_c==vert_2){
            at_c=1;
          }

          //if two vertices are marked, the edge between them is already known (an edge in system pointed to both) - safe pointer on it for triangle construction
          if(at_a==1 && at_b==1){
            insert_ab=1;
            ab=edge;
          }
          if(at_b==1 && at_c==1){ 
            insert_bc=1;
            bc=edge;
          }
          if(at_c==1 && at_a==1){
            insert_ca=1;
            ca=edge;
          }
          at_a=0;
          at_b=0;
          at_c=0;       
        }

        //insert all edges that are not known
        if(insert_ab==0){
          ab=new Edge(vertex_a,vertex_b);
          obj->addEdge(ab);
          std::cerr << "Added edge "<< vertex_a->x <<" to " << vertex_b->x << std::endl;

        }
        if(insert_bc==0){
          bc=new Edge(vertex_b,vertex_c);
          obj->addEdge(bc);
          std::cerr << "Added edge"<< vertex_b->x <<" to " << vertex_c->x << std::endl;
        }
        if(insert_ca==0){
          ca=new Edge(vertex_c,vertex_a);
          obj->addEdge(ca);
          std::cerr << "Added edge"<< vertex_c->x <<" to " << vertex_a->x << std::endl;

        }
        //add Triangle with vertex and edge information
        Triangle* triangle=new Triangle(ab,bc,ca,vertex_a,vertex_b,vertex_c);
        obj->addTriangle(triangle);
        std::cerr << "Added triangle" << std::endl;
      }
    }
    return *obj;
  }
