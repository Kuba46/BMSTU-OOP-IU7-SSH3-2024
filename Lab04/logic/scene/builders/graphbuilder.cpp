#include "graphbuilder.h"

GraphBuilder::GraphBuilder(std::vector<std::vector<double>>& values) : values(values) {}

std::shared_ptr<obj3d::Figure> GraphBuilder::build()
{
    std::vector<std::vector<obj3d::Vertex>> rows;
    std::vector<obj3d::Edge> edges;
    for (size_t i = 0; i < values.size(); i++)
    {
        std::vector<obj3d::Vertex> row;
        for (size_t j = 0; j < values[i].size(); j++)
        {
            row.push_back(obj3d::Vertex(obj3d::Point(j, i, values[i][j])));
        }
        rows.push_back(row);
    }
    for (size_t i = 0; i < values.size(); i++)
    {
        for (size_t j = 1; j < values[i].size(); j++)
        {
            edges.push_back(obj3d::Edge(rows[i][j - 1], rows[i][j]));
        }
    }
    for (size_t i = 1; i < values.size(); i++) {
        for (size_t j = 0; j < values[i].size(); j++) {
            edges.push_back(obj3d::Edge(rows[i - 1][j], rows[i][j]));
        }
    }
    std::vector<obj3d::Vertex> vertices;
    for (std::vector<obj3d::Vertex>& row : rows)
    {
        for (obj3d::Vertex& vertex : row)
        {
            vertices.push_back(vertex);
        }
    }
    return std::make_shared<obj3d::Figure>(vertices, edges);
}
