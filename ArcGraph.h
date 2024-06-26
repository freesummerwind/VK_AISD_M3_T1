#ifndef MODUL_3_ARCGRAPH_H
#define MODUL_3_ARCGRAPH_H

#include"IGraph.h"

class ArcGraph : public IGraph {
public:
    ArcGraph( int vertexCount );
    ArcGraph( const IGraph& graph );

    // IGraph
    virtual void AddEdge( int from, int to ) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices( int vertex ) const override;
    virtual std::vector<int> GetPrevVertices( int vertex ) const override;

private:
    std::vector<std::pair<int, int>> edjList;
    int vertexCount;

    bool isEdgeInGraph( int from, int to ) const;
};


#endif //MODUL_3_ARCGRAPH_H
