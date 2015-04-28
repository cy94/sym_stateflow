classdef Constant < ASTNode
    %CONSTANT Constant value ASTNode
    %   Represents a constant value (int or float)
    
    properties
        % Value stored in the node
        value
    end
    
    methods
        function obj = Constant(value)
            obj.value = value;
        end
    end
end

