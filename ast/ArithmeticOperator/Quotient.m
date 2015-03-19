classdef Quotient < ArithmeticOperator
    %QUOTIENT Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = Quotient(left, right)
            obj = obj@ArithmeticOperator(left, right);
        end
    end
    
end

