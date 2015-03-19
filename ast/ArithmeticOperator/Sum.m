classdef Sum < ArithmeticOperator
    %SUM Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function obj = Sum(left, right)
            obj = obj@ArithmeticOperator(left, right);
        end
    end
    
end

