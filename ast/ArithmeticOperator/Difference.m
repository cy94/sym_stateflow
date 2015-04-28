 classdef Difference < ArithmeticOperator
    %DIFFERENCE ASTNode for subtraction (-)
    %   Eg: 5 - 6
    
    properties
    end
    
    methods
        function obj = Difference(left, right)
            obj = obj@ArithmeticOperator(left, right);
        end
    end
    
end

