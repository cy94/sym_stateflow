classdef GreaterThanEqual < RelationalOperator
    %GREATERTHANEQUAL ASTNode for >=
    %   Eg: x >= 5
    
    properties
    end
    
    methods
        function obj = GreaterThanEqual(left, right)
            obj = obj@RelationalOperator(left, right)
        end
    end
    
end

