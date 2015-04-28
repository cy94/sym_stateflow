classdef LessThanEqual < RelationalOperator
    %LESSTHANEQUAL ASTNode for <=
    %   Eg: x <= 5
    
    properties
    end
    
    methods
        function obj = LessThanEqual(left, right)
            obj = obj@RelationalOperator(left, right)
        end
    end
    
end

