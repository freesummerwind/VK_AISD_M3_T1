#include"SetGraph.h"
#include<cassert>

SetGraph::SetGraph( int vertexCount )
{
    assert( vertexCount > 0 );
    adjSets.resize( vertexCount );
    prevAdjSets.resize( vertexCount );
}

SetGraph::SetGraph( const IGraph &graph )
{
    int vertexCount = graph.VerticesCount();
    adjSets.resize( vertexCount );
    prevAdjSets.resize( vertexCount );
    for( int i = 0; i < vertexCount; ++i ) {
        auto nextVertices = graph.GetNextVertices( i );
        adjSets[i] = std::set<int>( nextVertices.begin(), nextVertices.end() );
        auto prevVertices = graph.GetPrevVertices( i );
        prevAdjSets[i] = std::set<int>( prevVertices.begin(), prevVertices.end() );
    }
}

void SetGraph::AddEdge( int from, int to )
{
    assert( from >= 0 && from < adjSets.size() );
    assert( to >= 0 && to < adjSets.size() );
    adjSets[from].insert( to );
    prevAdjSets[to].insert( from );
}

int SetGraph::VerticesCount() const
{
    return adjSets.size();
}

std::vector<int> SetGraph::GetNextVertices( int vertex ) const
{
    assert( vertex >= 0 && vertex < adjSets.size() );
    return std::vector<int>( adjSets[vertex].begin(), adjSets[vertex].end() );
}

std::vector<int> SetGraph::GetPrevVertices( int vertex ) const
{
    assert( vertex >= 0 && vertex < adjSets.size() );
    return std::vector<int>( prevAdjSets[vertex].begin(), prevAdjSets[vertex].end() );
}
