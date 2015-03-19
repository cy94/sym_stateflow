classdef ArithmeticOperator < Operator
    %ARITHMETICOPERATOR Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = ArithmeticOperator(left, right)
            obj = obj@Operator(left, right);
        end
    end
    
end

