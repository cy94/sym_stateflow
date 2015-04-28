classdef Sum < ArithmeticOperator
    %SUM ASTNode for sum (+)
    %   Eg: 5 + 6
    
    properties
    end
    
    methods
        function obj = Sum(left, right)
            obj = obj@ArithmeticOperator(left, right);
        end
    end
    
end

