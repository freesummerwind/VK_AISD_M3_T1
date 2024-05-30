#include"ArcGraph.h"
#include<cassert>

ArcGraph::ArcGraph( int vertexCount ) : vertexCount( vertexCount )
{
    assert( vertexCount > 0 );
}

ArcGraph::ArcGraph( const IGraph &graph )
{
    vertexCount = graph.VerticesCount();
    for( int i = 0; i < vertexCount; ++i ) {
        auto nextVertices = graph.GetNextVertices( i );
        for( auto nextVertex : nextVertices ) {
            edjList.push_back( std::make_pair( i, nextVertex ) );
        }
    }
}

void ArcGraph::AddEdge(int from, int to)
{
    assert( from >= 0 && from < vertexCount );
    assert( to >= 0 && to < vertexCount );
    // так как первые 3 варианта не предусматривали кратные ребра, здесь также запретим их
    if( !isEdgeInGraph( from, to ) ) {
        edjList.push_back(std::make_pair(from, to));
    }
}

int ArcGraph::VerticesCount() const
{
    return vertexCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const
{
    assert( vertex >= 0 && vertex < vertexCount );
    std::vector<int> nextVertices;
    for( int i = 0; i < edjList.size(); ++i ) {
        if( edjList[i].first == vertex ) {
            nextVertices.push_back( edjList[i].second );
        }
    }
    return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const
{
    assert( vertex >= 0 && vertex < vertexCount );
    std::vector<int> nextVertices;
    for( int i = 0; i < edjList.size(); ++i ) {
        if( edjList[i].second == vertex ) {
            nextVertices.push_back( edjList[i].first );
        }
    }
    return nextVertices;
}

bool ArcGraph::isEdgeInGraph(int from, int to) const
{
    for( int i = 0; i < edjList.size(); ++i ) {
        if( edjList[i].first == from && edjList[i].second == to ) {
            return true;
        }
    }
    return false;
}