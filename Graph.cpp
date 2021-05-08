#include "Graph.h"
#include <iostream>
#include "DisjointSet.h"
#include <algorithm>
using namespace std;
void Graph::constructGraphHelper(std::vector< std::vector<std::string> > erdosVec, std::unordered_map<std::string , unsigned int> authorToPaper) {
    //Initializes the root of the graph
    this->authorToPaper_ = authorToPaper;
    this->erdosVec_ = erdosVec;
    string authorErdos = "Erdos";
    Vertex* setRoot = new Vertex(authorErdos);
    root = setRoot;
    root->setID(0);
    vertices.push_back(root);
    uniqueAuthors["Erdos"] = root;

    //Traverses through the erdosVec the first time while initializing an
    //unordered map that is filled with all of the unique author names in erdosVec
    unsigned int idCounter = 1;

    for (size_t i = 0; i < erdosVec.size(); i++) {
        for (size_t j = 0; j < erdosVec[i].size(); j++) {

            if ( uniqueAuthors.find(erdosVec[i][j]) == uniqueAuthors.end() ) {
                Vertex* author = new Vertex(erdosVec[i][j]);
                author->setID(idCounter);

                // populating uniqueAuthors
                uniqueAuthors[erdosVec[i][j]] = author;
                
                // populating idToVertex
                idToVertex[idCounter] = author;

                //Initializes a vector of Vertex pointers to each unique author
                vertices.push_back(author);
                
                idCounter++;
            }
        }
    }
    
    //Initializes the edge vectors inside each Vertex inside the graph
    unsigned count = 0;
    for (size_t i = 0; i < erdosVec.size(); i++) {
        Vertex* erdos1 = uniqueAuthors[erdosVec[i][0]];
        count++;
        //  Formula for the edge weight: 1/(n(a,b)/[(erd(a)+erd(b))/2])
        //
        //  An edge will always have the following format:
        //  Edge (name of whoever is closer to Erdos, name of second person, weight)
        double weight = 0.5;
        double publications = 1.0;
        if (authorToPaper.find(erdosVec[i][0]) != authorToPaper.end() ) {
            publications = authorToPaper[erdosVec[i][0]];
            weight = 1 / (2 * publications);
        }

        Edge* erdosToErdos1 = new Edge("Erdos", erdos1->getAuthor(), weight);
        wholeEdges.push_back(erdosToErdos1);
        
        //adding edge for Erdos and Erdos1
        root->addEdge(erdosToErdos1);
        erdos1->addEdge(erdosToErdos1);

        for (size_t j = 1; j < erdosVec[i].size(); j++) {
            Vertex* erdos2 = uniqueAuthors[erdosVec[i][j]];
            // An edge will always have the following format:
            // Edge (name of whoever is closer to Erdos, name of second person, weight)
            Edge* edge = new Edge(erdos1->getAuthor(), erdos2->getAuthor(), 1.0);
            wholeEdges.push_back(edge);
            erdos1->addEdge(edge);
            erdos2->addEdge(edge);
        }
    }
}
Graph::Graph(std::vector< std::vector<std::string> > erdosVec, std::unordered_map<std::string , unsigned int> authorToPaper) {
    constructGraphHelper(erdosVec, authorToPaper);
}

void Graph::_copy(Graph const & other) {
    // Clear self
    _delete();
    constructGraphHelper(other.erdosVec_, other.authorToPaper_);
    
}

void Graph::_delete() {
    for (unsigned j = 0; j < wholeEdges.size(); j++) {
        if (wholeEdges[j] != NULL)
            delete wholeEdges[j];
    }

    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices[i] != NULL)
            delete vertices[i];
    }
}


Graph::~Graph() {
    _delete();
}

Graph::Graph(const Graph & other) {
    _copy(other);
}

const Graph & Graph::operator=(Graph const & other) {
    if (this != &other) {
        _copy(other);
    }
    return *this;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int Graph::getSize() {
    return vertices.size();
}

unsigned int Graph::findID(std::string author) {
    for (size_t i = 0; i < vertices.size(); i++){
        if (vertices[i]->getAuthor() == author) {
            return vertices[i]->getID();
        }
    }
    return -1;
}

Vertex* Graph::getRoot() {
    return root;
}

Vertex* Graph::getVertex(std::string name) {
    return uniqueAuthors[name];
}

std::vector< Edge* > Graph::getWholeEdge() {
    return wholeEdges;
}

std::vector< Vertex* > Graph::getWholeVertex() {
    return vertices;
}
bool compareEdges(Edge* edge1, Edge* edge2) {return edge1->weight < edge2->weight;}
////////////////////////////////////////////////
std::vector<Edge*> Graph::KruskalMST() {
    DisjointSets forest;
    for (Vertex* v: vertices) {
        forest.addelements(v->getID());
    }

    std::vector<Edge*> priorityQueue;
    for (Edge* edge: wholeEdges) {
        priorityQueue.push_back(edge);
    }
    std::sort(priorityQueue.begin(), priorityQueue.end(), compareEdges);

    std::vector<Edge*> spanningTree;

    while (spanningTree.size() < vertices.size() - 1) {
        Edge* edge = priorityQueue.front();
        priorityQueue.erase(priorityQueue.begin());
        Vertex* v1 = getVertex(edge->vertex1); 
        Vertex* v2 = getVertex(edge->vertex2); 

        if (forest.find(v1->getID()) != forest.find(v2->getID())) {
            spanningTree.push_back(edge);
            forest.setunion(forest.find(v1->getID()), forest.find(v2->getID()));
        }
    }

    return spanningTree;

}