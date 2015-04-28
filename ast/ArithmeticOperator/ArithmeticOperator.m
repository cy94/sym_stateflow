classdef ArithmeticOperator < Operator
    %ARITHMETICOPERATOR Base class for arithmetic operators
    %   Eg: +, -, *, /
    
    properties
    end
    
    methods
        function obj = ArithmeticOperator(left, right)
            obj = obj@Operator(left, right);
        end
    end
    
end

