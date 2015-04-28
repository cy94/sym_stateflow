classdef Product < ArithmeticOperator
    %PRODUCT ASTNode for multiplication (*)
    %   Eg: 5 * 6
    
    properties
    end
    
    methods
        function obj = Product(left, right)
            obj = obj@ArithmeticOperator(left, right);
        end
    end
    
end

