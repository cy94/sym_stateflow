classdef And < BooleanOperator
    %AND ASTNode for boolean '&&'
    %   Eg: x && y
    
    properties
    end
    
    methods
        function obj = And(left, right)
            obj = obj@BooleanOperator(left, right)
        end
    end
    
end

