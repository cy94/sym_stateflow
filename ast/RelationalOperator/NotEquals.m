classdef NotEquals < RelationalOperator
    %NOTEQUALS ASTNode for '~='
    %   Eg: x ~= 5
    
    properties
    end
    
    methods
        function obj = NotEquals(left, right)
            obj = obj@RelationalOperator(left, right)
        end
    end
    
end

