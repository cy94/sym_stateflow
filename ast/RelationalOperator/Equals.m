classdef Equals < RelationalOperator
    %EQUAL ASTNode for '=='
    %   Eg: x == 5
    
    properties
    end
    
    methods
        function obj = Equals(left, right)
            obj = obj@RelationalOperator(left, right)
        end
    end
    
end

