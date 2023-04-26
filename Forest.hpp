#include <vector>

#include "Shape.hpp"


class Forest
{
    private:
        int ** matrix;
        void add_trees_to_matrix();
        void clear_matrix();
    public:
        int height;
        int width;
        // std::vector<Tree*> trees;
        std::vector<Shape*> trees;
        Forest(int width, int height);
        ~Forest();
        // void add_tree(Tree * tree);
        void add_tree(Shape * tree);
        void print();
};