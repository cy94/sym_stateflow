classdef Operator < ASTNode
    %OPERATOR Base class for all binary operator ASTNodes
    %   Operator has two children, used to store the left
    %   and right ASTs
    
    properties
        left_node
        right_node
    end
    
    methods
        function obj = Operator(left, right)
            obj.left_node = left;
            obj.right_node = right;
            
            left.parent_node = obj;
            right.parent_node = obj;
        end
    end
    
end

