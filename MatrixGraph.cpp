#include"MatrixGraph.h"
#include<cassert>

MatrixGraph::MatrixGraph( int vertexCount )
{
    assert( vertexCount > 0 );
    graphMatrix.resize( vertexCount );
    for( int i = 0; i < vertexCount; ++i ) {
        graphMatrix[i].resize( vertexCount );
    }
}

MatrixGraph::MatrixGraph( const IGraph &graph )
{
    int vertexCount = graph.VerticesCount();
    graphMatrix.resize(vertexCount );
    for(int i = 0; i < vertexCount; ++i ) {
        graphMatrix[i].resize(vertexCount );
        auto nextVertices = graph.GetNextVertices( i );
        for( auto nextVertex : nextVertices ) {
            graphMatrix[i][nextVertex] = true;
        }
    }
}

void MatrixGraph::AddEdge( int from, int to )
{
    assert( from >= 0 && from < graphMatrix.size() );
    assert( to >= 0 && to < graphMatrix.size() );
    graphMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const
{
    return graphMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices( int vertex ) const
{
    assert( vertex >= 0 && vertex < graphMatrix.size() );
    std::vector<int> nextVertices;
    for( int i = 0; i < graphMatrix[vertex].size(); ++i ) {
        if( graphMatrix[vertex][i] ) {
            nextVertices.push_back( i );
        }
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices( int vertex ) const
{
    assert( vertex >= 0 && vertex < graphMatrix.size() );
    std::vector<int> prevVertices;
    for( int i = 0; i < graphMatrix.size(); ++i ) {
        if( graphMatrix[i][vertex] ) {
            prevVertices.push_back( i );
        }
    }
    return prevVertices;
}