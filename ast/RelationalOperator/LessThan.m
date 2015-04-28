classdef LessThan < RelationalOperator
    %LessThan ASTNode for '<''
    %   Eg: x < 5
    
    properties
    end
    
    methods
        function obj = LessThan(left, right)
            obj = obj@RelationalOperator(left, right)
        end
    end
    
end

