classdef Or < BooleanOperator
    %OR ASTNode for boolean or (||)
    %   Eg: x || y
    
    properties
    end
    
    methods
        function obj = Or(left, right)
            obj = obj@BooleanOperator(left, right)
        end
    end
    
end

