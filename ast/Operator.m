classdef Operator < ASTNode
    %OPERATOR Summary of this class goes here
    %   Detailed explanation goes here
    
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

