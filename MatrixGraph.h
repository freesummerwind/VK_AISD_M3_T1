#ifndef MODUL_3_MATRIXGRAPH_H
#define MODUL_3_MATRIXGRAPH_H

#include"IGraph.h"

class MatrixGraph : public IGraph {
public:
    MatrixGraph( int vertexCount );
    MatrixGraph( const IGraph& graph );

    // IGraph
    virtual void AddEdge( int from, int to ) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices( int vertex ) const override;
    virtual std::vector<int> GetPrevVertices( int vertex ) const override;

private:
    std::vector<std::vector<bool>> graphMatrix;
};


#endif //MODUL_3_MATRIXGRAPH_H
