classdef GreaterThan < RelationalOperator
    %GREATERTHAN ASTNode for '>'
    %   Eg: x > 5
    
    properties
    end
    
    methods
        function obj = GreaterThan(left, right)
            obj = obj@RelationalOperator(left, right)
        end
    end
    
end

