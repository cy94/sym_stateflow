classdef Quotient < ArithmeticOperator
    %QUOTIENT ASTNode for division (/)
    %   Eg: 5 / 6
    
    properties
    end
    
    methods
        function obj = Quotient(left, right)
            obj = obj@ArithmeticOperator(left, right);
        end
    end
    
end

