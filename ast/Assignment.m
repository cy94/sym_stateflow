classdef Assignment < Operator
    %ASSIGNMENT Assignment ASTNode
    %   Represents an assignment of an 
    %   expression to a Variable node
    %   Eg:
    % 		x = 10
    % 		y = 5 + z
    
    properties
    end
    
    methods
        function obj = Assignment(left, right)
            obj = obj@Operator(left, right)
        end
    end
    
end

