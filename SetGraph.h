#ifndef MODUL_3_SETGRAPH_H
#define MODUL_3_SETGRAPH_H

#include"IGraph.h"
#include<set>

class SetGraph : public IGraph {
public:
    SetGraph( int vertexCount );
    SetGraph( const IGraph& graph );

    // IGraph
    virtual void AddEdge( int from, int to ) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices( int vertex ) const override;
    virtual std::vector<int> GetPrevVertices( int vertex ) const override;

private:
    std::vector<std::set<int>> adjSets;
    std::vector<std::set<int>> prevAdjSets;
};


#endif //MODUL_3_SETGRAPH_H
